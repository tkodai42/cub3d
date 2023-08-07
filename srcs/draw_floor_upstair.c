/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_upstair.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:30:08 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 18:26:52 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw_floor_set1(t_player *p, t_df *df, int floor_height)
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

int		draw_floor_set2(t_player *p, t_df *df, t_dir *dir, int floor_height)
{
	if (check_map_height(p, df->pos_x, df->pos_y, floor_height))
	{
		df->color = get_tex_color_floor(p, dir, df->pos_x, df->pos_y);
		df->color = get_darker(p, df->color, df->range);
		my_mlx_pixel_put(p, df->width_pos, df->win_y, df->color);
		p->buf_draw_valid_height[df->width_pos] = df->win_y;
		p->buf_draw_f_range[df->width_pos] = df->range;
		if (p->buf_draw_vh_head_pos[df->width_pos] < 0)
			p->buf_draw_vh_head_pos[df->width_pos] = df->range;
	}
	df->i = 1;
	return (0);
}

int		ft_draw_floor_upstair(t_player *p, int floor_height)
{
	t_dir	*dir;
	t_df	df;

	dir = find_tex_from_list(p, FLOOR_TEX);
	df.win_y = p->win_height;
	df.i = 0;
	while (df.i < p->win_width)
		p->buf_draw_valid_height[df.i++] = p->win_height;
	while (df.win_y > p->win_height / 2)
	{
		draw_floor_set1(p, &df, floor_height);
		while (df.width_pos < p->win_width)
		{
			if (df.range < p->buf_range[df.width_pos])
				draw_floor_set2(p, &df, dir, floor_height);
			df.pos_x = df.pos_x + df.width_add_dist * cos(p->angle + PI / 2);
			df.pos_y = df.pos_y + df.width_add_dist * sin(p->angle + PI / 2);
			df.width_pos++;
		}
		if (df.i == 0)
			return (0);
		df.win_y--;
	}
	return (0);
}
