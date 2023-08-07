/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:29:59 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 18:30:14 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		make_validate_angle(double angle)
{
	while (angle < 0)
		angle = angle + PI * 2;
	if (angle > PI * 2)
		angle = fmod(angle, (PI * 2));
	return (angle);
}

double		make_pa_base(t_player *p, double angle)
{
	double	vertical_angle;

	vertical_angle = p->angle * -1;
	angle += vertical_angle;
	while (angle >= PI)
		angle = angle - PI * 2;
	while (angle <= PI * -1)
		angle = angle + PI * 2;
	return (angle);
}

int			trans_color(int front_back)
{
	int		color;

	if (front_back == 1)
		color = 0x00000000;
	if (front_back == 0)
		color = 0xFF000000;
	return (color);
}

void		ft_map_on(t_player *p)
{
	if (p->key->map_on_off == 1)
		p->key->map_on_off = 0;
	else
		p->key->map_on_off = 1;
	p->key->m = 0;
}

int			get_mini_size(t_player *p)
{
	double	grid_x;
	double	grid_y;

	grid_x = p->win_width / (p->map_max_x + 1);
	grid_y = p->win_height / (p->map_max_y + 1);
	p->mini_grid = grid_x < grid_y ? grid_x : grid_y;
	p->mini_grid_ratio = (double)GRID / p->mini_grid;
	return (0);
}
