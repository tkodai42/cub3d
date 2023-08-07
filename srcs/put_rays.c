/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:30:08 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 13:34:50 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_dda_structure(t_player *p, t_dda *dda)
{
	p->tmp = 0;
	dda->tan_a = 0;
	dda->rx = 0;
	dda->ry = 0;
	dda->yo = 0;
	dda->xo = 0;
	dda->x_range = 100000;
	dda->y_range = 100000;
	dda->has_rear_wall = 0;
	dda->has_x_rear_wall = 0;
	dda->has_y_rear_wall = 0;
	dda->rear_x_range = 100000;
	dda->rear_y_range = 100000;
	dda->rear_wall_range = 0;
	dda->rear_rx = 0;
	dda->rear_ry = 0;
	return (0);
}

void	rays_dda_vertical_2(t_player *p, t_dda *dda)
{
	dda->rear_y_range =
		ret_range(p->x_axis, dda->rx, p->y_axis, dda->ry);
	dda->has_rear_wall = 1;
	dda->has_y_rear_wall = 1;
	dda->rear_ry = dda->rx;
}

void	rays_dda_vertical(t_player *p, t_dda *dda)
{
	while (within_screen_range(p, dda->rx, dda->ry))
	{
		my_mlx_pixel_put_mini(p, dda->rx, dda->ry, WHITE);
		if (check_wall(p, dda->rx, dda->ry) == MAP_WALL)
		{
			dda->y_range = ret_range(p->x_axis, dda->rx, p->y_axis, dda->ry);
			break ;
		}
		if (check_wall(p, dda->rx, dda->ry) ==
				MAP_FLOOR_2F && dda->has_y_rear_wall == 0)
			rays_dda_vertical_2(p, dda);
		if (check_wall(p, dda->rx, dda->ry) == MAP_DOOR)
		{
			if (ft_door_y(p, dda))
				break ;
		}
		dda->ry += dda->yo;
		dda->rx += dda->xo;
	}
	dda->y_rx = dda->rx;
	dda->y_ry = dda->ry;
}

void	rays_dda_horizontal(t_player *p, t_dda *dda)
{
	while (within_screen_range(p, dda->rx, dda->ry))
	{
		my_mlx_pixel_put_mini(p, dda->rx, dda->ry, WHITE);
		if (check_wall(p, dda->rx, dda->ry) == MAP_WALL)
		{
			dda->x_range = ret_range(p->x_axis, dda->rx, p->y_axis, dda->ry);
			break ;
		}
		if (check_wall(p, dda->rx, dda->ry) ==
				MAP_FLOOR_2F && dda->has_x_rear_wall == 0)
		{
			dda->rear_x_range =
				ret_range(p->x_axis, dda->rx, p->y_axis, dda->ry);
			dda->has_rear_wall = 1;
			dda->has_x_rear_wall = 1;
			dda->rear_rx = dda->ry;
		}
		if (check_wall(p, dda->rx, dda->ry) == MAP_DOOR)
		{
			if (ft_door_x(p, dda))
				break ;
		}
		dda->ry += dda->yo;
		dda->rx += dda->xo;
	}
}

void	set_angle_buf(t_player *p, double *angle_buf)
{
	int		i = 0;
//1.73205080757 ルート３
	double	x = (double)p->win_width / 2 * 1.73205080;
	while (i < p->win_width)
	{
		if (i < p->win_width / 2)
		{
			angle_buf[i] = atan2((double)p->win_width / 2 - i, x) * -1;
		}
		else
			angle_buf[i] = atan2((double)i - p->win_width / 2, x);
		i++;
	}
}

int		put_rays(t_player *p)
{
	int		win_x_pos;
	float	ray_angle;

	double	angle_buf[p->win_width * 2];
	set_angle_buf(p, angle_buf);
//	半分からどれだけ進んだか
//  if (i < p->win_width / 2)
//　p->win_width / 2 - i
//  else
//  i + p->win_width / 2
//
	win_x_pos = 0;
	ray_angle = p->angle - FOV_LR;
	p->rayc_win_y = 0;
	p->rayc_win_x = 0;
	p->win_buf_index = 0;
	if (OMIT_LINE != 1 || p->is_bonus)
		put_fov_rays(p, ray_angle);
	p->add_wall_count = 0;
	while (win_x_pos < p->win_width)
//	while (win_x_pos < p->win_width && ray_angle < p->angle + FOV_LR)
	{
		rays_dda(p, ray_angle);
		p->rayc_win_x += 1;
		win_x_pos++;
//		ray_angle += (FOV_LR * 2) / p->win_width;
		ray_angle = p->angle + angle_buf[win_x_pos];
		ray_angle = validate_angle2(ray_angle);
		p->win_buf_index = p->rayc_win_x;
	}
	if (OMIT_LINE != 1 || p->is_bonus)
		put_fov_rays(p, ray_angle);
	if (BONUS_SEVERAL_LEVEL && p->is_bonus)
		if (p->ver_angle > 0.5 && p->ver_angle >= 0.5)
			ft_draw_floor_upstair(p, 1);
	return (0);
}
/*
**	if (p->ver_angle > 0.5 && p->ver_angle >= 1.5)
**		ft_draw_floor_upstair(p, 2);
**
**
**		ft_draw_floor(p, 0);
**	while ((ADD_WALL_HEIGHT) >= p->add_wall_count)
**	{
**		win_x_pos = 0;
**		ray_angle = p->angle - FOV_LR;
**		p->rayc_win_y = 0;
**		p->rayc_win_x = 0;
**		p->win_buf_index = 0;
**		put_fov_rays(p, ray_angle);
**		if (p->ver_angle >= 1.5)
**		ft_draw_floor_upstair(p, 2);
**		if (p->ver_angle > 0.5 && p->ver_angle >= p->add_wall_count - 0.5)
**			ft_draw_floor_upstair(p, p->add_wall_count);
**		while (win_x_pos <= p->win_width && ray_angle < p->angle + FOV_LR)
**		{
**			rays_dda(p, ray_angle);
**			p->rayc_win_x += 1;
**			win_x_pos++;
**			ray_angle += (FOV_LR * 2) / p->win_width;
**			p->win_buf_index = p->rayc_win_x;
**		}
**		put_fov_rays(p, ray_angle);
**		p->add_wall_count++;
**	}
*/
