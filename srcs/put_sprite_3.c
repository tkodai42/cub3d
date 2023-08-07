/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:53:37 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 13:56:32 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_circle(t_player *p, int x, int y, int color)
{
	double		circle_range;
	double		angle;
	double		put_x_pos;
	double		put_y_pos;

	circle_range = GRID / 8;
	angle = 0;
	if (OMIT_LINE != 1)
	{
		while (angle <= PI * 2)
		{
			put_x_pos = circle_range * cos(angle) + x;
			put_y_pos = circle_range * sin(angle) + y;
			my_mlx_pixel_put_mini(p, put_x_pos, put_y_pos, color);
			angle += PI / 32;
		}
	}
	return (0);
}

void	put_line2(t_player *p, t_line pos, t_putline pl)
{
	while (pl.range < pos.range)
	{
		my_mlx_pixel_put_mini(p, pl.put_x, pl.put_y, GREEN);
		pl.put_x = pl.range * cos(pos.angle) + p->x_axis;
		pl.put_y = pl.range * sin(pos.angle) + p->y_axis;
		pl.range++;
	}
}

double	put_line(t_player *p, t_line pos, t_sp *sp)
{
	t_putline pl;

	pl.put_x = pos.x1;
	pl.put_y = pos.y1;
	pl.range = 0;
	pl.x = (pos.x2 - pos.x1);
	pl.y = (pos.y2 - pos.y1);
	pos.range = sqrt((pl.x * pl.x) + (pl.y * pl.y));
	pos.angle = atan2(pl.y, pl.x);
	if (sp)
	{
		while (pos.angle < 0)
			pos.angle = pos.angle + PI * 2;
		if (pos.angle > PI * 2)
			pos.angle = fmod(pos.angle, (PI * 2));
		sp->angle = pos.angle;
	}
	if (OMIT_LINE != 1)
		put_line2(p, pos, pl);
	pos.angle = make_validate_angle(pos.angle);
	return (pos.angle);
}
