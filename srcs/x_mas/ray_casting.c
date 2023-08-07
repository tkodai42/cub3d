/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:58:50 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 15:47:29 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting_upstairs_init(t_player *p, int f_level, t_raycasting *rc)
{
	rc->win_y = p->win_height / 2;
	rc->wall_hight = p->win_width * GRID / p->rayc_range;
	rc->wh_pos = 0;
	rc->win_y = rc->win_y + rc->wall_hight * (p->ver_angle + p->walk->z_pos) -
		rc->wall_hight * f_level;
	rc->win_y = rc->win_y - rc->wall_hight / 2;
}

void	ray_casting_upstairs(t_player *p, int dir, int f_level)
{
	t_raycasting	rc;

	ray_casting_upstairs_init(p, f_level, &rc);
	while (rc.wh_pos <= rc.wall_hight)
	{
		if (rc.win_y >= 0 && rc.win_y < p->win_height)
		{
			rc.color = get_tex_color(p, dir, (rc.wh_pos++ /
						rc.wall_hight), NULL);
			if (p->is_bonus)
				rc.color = get_darker(p, rc.color, p->rayc_range);
			my_mlx_pixel_put(p, p->rayc_win_x, rc.win_y++, rc.color);
		}
		else if (rc.win_y < 0)
		{
			rc.wh_pos = rc.win_y * -1;
			rc.win_y = 0;
		}
		else
			break ;
	}
}

void	ray_casting_rear_wall(t_player *p, int dir, int f_level)
{
	t_raycasting	rc;

	rc.win_y = p->win_height / 2;
	rc.wall_hight = p->win_width * GRID / p->dda->rear_wall_range;
	rc.wh_pos = 0;
	rc.win_y = rc.win_y + rc.wall_hight * (p->ver_angle + p->walk->z_pos) -
		rc.wall_hight * f_level;
	rc.win_y = rc.win_y - rc.wall_hight / 2;
	while (rc.wh_pos <= rc.wall_hight)
	{
		if (rc.win_y >= 0 && rc.win_y < p->win_height)
		{
			rc.color = get_tex_color(p, dir, (rc.wh_pos++ /
						rc.wall_hight), NULL);
			rc.color = get_darker(p, rc.color, p->dda->rear_wall_range);
			my_mlx_pixel_put(p, p->rayc_win_x, rc.win_y++, rc.color);
		}
		else if (rc.win_y < 0)
		{
			rc.wh_pos = rc.win_y * -1;
			rc.win_y = 0;
		}
		else
			break ;
	}
}

int		ray_casting(t_player *p, int dir)
{
	float	ca;
	int		i;
	int		add_wall_height;

	add_wall_height = (p->is_bonus ? ADD_WALL_HEIGHT : 0);
	ca = p->angle - p->rayc_angle;
	p->rayc_range = p->rayc_range * cos(ca);
	i = 0;
	p->rayc_x = fmod(p->rayc_x, 64);
	p->rayc_x = p->rayc_x / 64;
	while (add_wall_height >= i)
	{
		ray_casting_upstairs(p, dir, i);
		i++;
	}
	p->is_door = 0;
	if (p->dda->has_rear_wall == 1)
	{
		p->dda->rear_wall_range = p->dda->rear_wall_range * cos(ca);
		p->rayc_x = p->dda->rear_x_pos;
		p->rayc_x = fmod(p->rayc_x, 64);
		p->rayc_x = p->rayc_x / 64;
		ray_casting_rear_wall(p, dir, 0);
	}
	return (0);
}
