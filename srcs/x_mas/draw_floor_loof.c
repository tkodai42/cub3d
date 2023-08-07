/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_loof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:11:54 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 12:31:58 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_height(t_player *p, double pos_x, double pos_y,
		int floor_height)
{
	int		tmp;

	tmp = 'x';
	if (pos_y / GRID > p->map_max_y)
		return (1);
	if (pos_x < 0 || pos_y < 0)
		return (1);
	if (floor_height == 0)
		tmp = MAP_FLOOR_1F;
	if (floor_height == 1)
		tmp = MAP_FLOOR_2F;
	if (floor_height == 2)
		tmp = MAP_FLOOR_3F;
	if (p->map[(int)pos_y / 64][(int)pos_x / 64] == tmp)
	{
		return (1);
	}
	return (0);
}

int		get_tex_color_floor(t_player *p, t_dir *dir,
		double x_pos, double y_pos)
{
	int color;
	int x;
	int y;

	p->tmp = 0;
	x = dir->xpm_width * ((double)((int)x_pos % 64) / 64);
	y = dir->xpm_height * ((double)((int)y_pos % 64) / 64);
	color = *(unsigned int *)(dir->addr + y * dir->line_len + x * 4);
	return (color);
}

int		draw_floor_seti_1(t_player *p, t_df *df, int floor_height)
{
	df->wall_size = ((p->ver_angle + p->walk->z_pos) - floor_height) / 0.5 + 1;
	df->range = p->win_width * (GRID * df->wall_size) /
		(p->win_height - df->win_y * 2);
	df->range = df->range * -1;
	df->pos_x = p->x_axis + df->range * cos(p->angle);
	df->pos_y = p->y_axis + df->range * sin(p->angle);
	df->width = df->range * tan(PI * ((double)FOV / 360));
	df->pos_x = df->pos_x + df->width * cos(p->angle - PI / 2);
	df->pos_y = df->pos_y + df->width * sin(p->angle - PI / 2);
	df->width_add_dist = df->width * 2 / p->win_width;
	df->i = 0;
	df->width_pos = 0;
	return (0);
}

int		draw_floor_set_2(t_player *p, t_df *df, t_dir *dir)
{
	if (0 <= df->pos_x && df->pos_x <= p->map_max_x * GRID)
	{
		if (0 <= df->pos_y && df->pos_y <= p->map_max_y * GRID)
		{
			df->color = get_tex_color_floor(p, dir, df->pos_x, df->pos_y);
			df->color = get_darker(p, df->color, df->range);
			my_mlx_pixel_put(p, df->width_pos, df->win_y, df->color);
			df->i = 1;
		}
	}
	df->pos_x = df->pos_x + df->width_add_dist * cos(p->angle + PI / 2);
	df->pos_y = df->pos_y + df->width_add_dist * sin(p->angle + PI / 2);
	df->width_pos++;
	return (0);
}

int		ft_draw_floor(t_player *p, int floor_height)
{
	t_dir	*dir;
	t_df	df;

	dir = find_tex_from_list(p, FLOOR_TEX);
	df.win_y = p->win_height - 1;
	df.width_pos = 0;
	df.i = 0;
	while (df.i <= p->win_width)
	{
		p->buf_draw_valid_height[df.i] = p->win_height;
		p->buf_draw_f_range[df.i] = -100;
		p->buf_draw_vh_head_pos[df.i] = -100;
		df.i++;
	}
	while (df.win_y > p->win_height / 2)
	{
		draw_floor_seti_1(p, &df, floor_height);
		while (df.width_pos < p->win_width)
			draw_floor_set_2(p, &df, dir);
		df.win_y--;
		if (df.i == 0)
			return (0);
	}
	return (0);
}

/*
** 	float ca = p->angle - p->rayc_angle;
**
**	p->rayc_angle = p->rayc_range * cas(ca);
**---------------------------------------------------
**	win_y = WIN_PIXEL_Y / 2;
**
**	double	wall_height = WIN_PIXEL_X * GRID / p->rayc_angle;
**
**	win_y = (WIN_PIXEL_Y / 2) - ((WIN_PIXEL_X * GRID / p->rayc_angle) / 2)
**
**
**	win_y = win_y + wall_height * ver_angle;
**
**	win_y = (WIN_PIXEL_Y / 2) - ((WIN_PIXEL_X * GRID / p->rayc_angle) / 2)
**
**
**	0 = (WIN_PIXEL_Y / 2) - (WIN_PIXEL_X * GRID / p->rayc_angle / 2) - win_y
**	(WIN_PIXEL_X * GRID / p->rayc_angle / 2) = (WIN_PIXEL_Y / 2) - win_y
**
**	(WIN_PIXEL_X * GRID / 2) = ((WIN_PIXEL_Y / 2) - win_y) * p->rayc_angle
**
**	range = (WIN_PIXEL_X * GRID / 2) / ((WIN_PIXEL_Y / 2) - win_y);
**
**-------------------------------------------------------
** 	win_y = WIN_PIXEL_Y / 2
**	wall_hight = WIN_PIXEL_X * GRID / range;
**	win_y = win_y - wall_hight / 2
**
**	wall_hight = WIN_PIXEL_X * GRID / range;
**	win_y = WIN_PIXEL_Y / 2 - wall_hight / 2
**
**	wall_hight * range = WIN_PIXEL_X * GRID;
**	win_y = WIN_PIXEL_Y / 2 - wall_hight / 2
**
**	range = WIN_PIXEL_X * GRID / wall_hight;
**	wall_hight / 2 = WIN_PIXEL_Y / 2 - win_y
**
**	range = WIN_PIXEL_X * GRID / wall_hight;
**	wall_hight = WIN_PIXEL_Y - win_y * 2
**
**	range = WIN_PIXEL_X * GRID / (WIN_PIXEL_Y - win_y * 2)
**
**	---------------------------------------------------------------
**	win_y = WIN_PIXEL_Y / 2
**	wall_hight = WIN_PIXEL_X * GRID / range;
**	win_y = win_y - wall_hight / 2 + wall_hight * ver_angle;
**
**	wall_hight = WIN_PIXEL_X * GRID / range;
**	win_y = WIN_PIXEL_Y / 2 - wall_hight / 2 + wall_hight * ver_angle;
**
**	wall_hight = WIN_PIXEL_X * GRID / range;
**	win_y - (WIN_PIXEL_Y / 2) = wall_hight * ver_angle - wall_hight / 2;
**
**	wall_hight = WIN_PIXEL_X * GRID / range;
**	win_y - (WIN_PIXEL_Y / 2) = wall_hight(ver_angle - 1 / 2);
**
**	wall_hight = WIN_PIXEL_X * GRID / range;
**	win_y - (WIN_PIXEL_Y / 2) / (ver_angle - 1 / 2) = wall_hight;
**
**	range = WIN_PIXEL_X * GRID / wall_hight
**	win_y - (WIN_PIXEL_Y / 2) / (ver_angle - 1 / 2) = wall_hight;
**
**	range = WIN_PIXEL_Y * GRID / (win_y - (WIN_PIXEL_Y / 2)
**			/ (ver_angle - 1 / 2))
**
**
**
**	(WIN_PIXEL_X * GRID / 2) / ((WIN_PIXEL_Y / 2) - win_y) =  p->rayc_angle
*/
