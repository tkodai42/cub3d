/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rays_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:16:40 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/09 17:50:13 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dda2(t_player *p, t_dda *dda, float *ray_angle)
{
	*ray_angle = validate_angle2(*ray_angle);
	dda->tan_a = -1 / tan(*ray_angle);
	dda->ry = (p->y_axis / GRID);
	if (*ray_angle < PI)
	{
		dda->ry = (int)dda->ry * GRID + GRID;
		dda->rx = (p->y_axis - dda->ry) * dda->tan_a + p->x_axis;
		dda->yo = GRID;
		dda->xo = dda->yo * -1 * dda->tan_a;
	}
	else
	{
		dda->ry = (int)dda->ry * GRID - 0.001;
		dda->rx = (p->y_axis - dda->ry) * dda->tan_a + p->x_axis;
		dda->yo = GRID * -1;
		dda->xo = dda->yo * -1 * dda->tan_a;
	}
}

void	init_dda3(t_player *p, t_dda *dda, float ray_angle)
{
	dda->rx = (p->x_axis / GRID);
	dda->tan_a = tan(ray_angle) * -1;
	if (ray_angle <= PI / 2 || ray_angle > PI * 3 / 2)
	{
		dda->rx = (int)dda->rx * GRID + GRID;
		dda->ry = (p->x_axis - dda->rx) * dda->tan_a + p->y_axis;
		dda->xo = GRID;
		dda->yo = dda->xo * -1 * dda->tan_a;
	}
	else
	{
		dda->rx = (int)dda->rx * GRID - 0.001;
		dda->ry = (p->x_axis - dda->rx) * dda->tan_a + p->y_axis;
		dda->xo = GRID * -1;
		dda->yo = dda->xo * -1 * dda->tan_a;
	}
}

void	rays_dda4(t_player *p, t_dda *dda, int *dir, float ray_angle)
{
	if (dda->y_range < dda->x_range)
	{
		*dir = (ray_angle <= PI ? 'S' : 'N');
		if (dda->y_range == p->is_door)
			p->is_door = -42;
		p->rayc_range = dda->y_range;
		put_point(p, dda->y_rx, dda->y_ry, *dir == 'N' ? RED : RED2);
		p->rayc_angle = ray_angle;
		p->rayc_x = dda->y_rx;
		p->dda_x = dda->y_rx;
		p->dda_y = dda->y_ry;
	}
	else
	{
		*dir = (ray_angle <= PI / 2 || ray_angle > PI * 3 / 2) ? 'E' : 'W';
		if (dda->x_range == p->is_door)
			p->is_door = -42;
		p->rayc_range = dda->x_range;
		put_point(p, dda->rx, dda->ry, *dir == 'E' ? BLUE : YELLOW);
		p->rayc_angle = ray_angle;
		p->rayc_x = dda->ry;
		p->dda_x = dda->rx;
		p->dda_y = dda->ry;
	}
}

int		rays_dda(t_player *p, float ray_angle)
{
	t_dda	dda;
	int		dir;

	p->dda = &dda;
	init_dda_structure(p, &dda);
	init_dda2(p, &dda, &ray_angle);
	rays_dda_vertical(p, &dda);
	init_dda3(p, &dda, ray_angle);
	rays_dda_horizontal(p, &dda);
	rays_dda4(p, &dda, &dir, ray_angle);
	rear_wall(p, &dda);
	p->buf_angle[p->win_buf_index] = p->rayc_angle;
	p->buf_range[p->win_buf_index] = p->rayc_range;
	ray_casting(p, dir);
	return (0);
}
