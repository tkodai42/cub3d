/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rays_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:25:28 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/04 13:29:31 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	validate_angle2(float angle)
{
	while (angle < 0)
	{
		angle += PI * 2;
	}
	if (angle > PI * 2)
		angle = fmod(angle, (PI * 2));
	return (angle);
}

float	ret_range(float x1, float x2, float y1, float y2)
{
	float rv;
	float tmp_x;
	float tmp_y;

	tmp_x = x1 - x2;
	tmp_y = y1 - y2;
	rv = sqrt((tmp_x * tmp_x) + (tmp_y * tmp_y));
	return (rv);
}

void	rear_wall(t_player *p, t_dda *dda)
{
	if (dda->has_rear_wall == 1)
	{
		dda->rear_wall_range = dda->rear_x_range <
			dda->rear_y_range ? dda->rear_x_range : dda->rear_y_range;
		if (dda->rear_x_range < dda->rear_y_range)
		{
			dda->rear_wall_range = dda->rear_x_range;
			dda->rear_x_pos = dda->rear_rx;
		}
		else
		{
			dda->rear_wall_range = dda->rear_y_range;
			dda->rear_x_pos = dda->rear_ry;
		}
	}
	if (dda->rear_wall_range > p->rayc_range)
	{
		dda->has_rear_wall = 0;
	}
}

int		put_fov_rays(t_player *p, float angle)
{
	int		range;
	float	x_pos;
	float	y_pos;

	range = 1;
	x_pos = p->x_axis;
	y_pos = p->y_axis;
	while (1)
	{
		x_pos = cos(angle) * range + p->x_axis;
		y_pos = sin(angle) * range + p->y_axis;
		if (within_screen_range(p, x_pos, y_pos) == 0)
			return (0);
		my_mlx_pixel_put_mini(p, x_pos, y_pos, RED2);
		range++;
	}
	return (0);
}
