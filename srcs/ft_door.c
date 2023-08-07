/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:31:27 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/10 12:47:34 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_door_y(t_player *p, t_dda *dda)
{
	int i;

	i = p->map_check[(int)dda->ry / GRID][(int)dda->rx / GRID];
	i = (double)(i - 'D') / 40 * 100;
	if (((int)(dda->rx + dda->xo / 2) % GRID) < GRID * (0.01 * (i)))
		return (0);
	dda->ry += dda->yo / 2;
	dda->rx += dda->xo / 2;
	dda->y_range = ret_range(p->x_axis, dda->rx, p->y_axis, dda->ry);
	dda->y_rx = dda->rx;
	dda->y_ry = dda->ry;
	p->is_door = dda->y_range;
	return (1);
}

int		ft_door_x(t_player *p, t_dda *dda)
{
	int i;

	i = p->map_check[(int)dda->ry / GRID][(int)dda->rx / GRID];
	i = (double)(i - 'D') / 40 * 100;
	if (((int)(dda->ry + dda->yo / 2) % GRID) < GRID * (0.01 * (i)))
		return (0);
	dda->ry += dda->yo / 2;
	dda->rx += dda->xo / 2;
	dda->x_range = ret_range(p->x_axis, dda->rx, p->y_axis, dda->ry);
	p->is_door = dda->x_range;
	return (1);
}

void	door_open_close2(t_player *p, t_sp *door)
{
	int	x;
	int	y;
	int	tmp;

	x = door->x_pos;
	y = door->y_pos;
	tmp = p->map_check[y / GRID][x / GRID];
	tmp += door->hit_time;
	if (tmp < 'D')
		tmp = 'D';
	if (tmp > 'D' + 40)
		tmp = 'D' + 40;
	p->map_check[y / GRID][x / GRID] = tmp;
	if (p->map_check[y / GRID][x / GRID] != 'D' + 40)
		p->map[y / GRID][x / GRID] = 'D';
	if (p->map_check[y / GRID][x / GRID] == 'D' + 40)
	{
		p->map[y / GRID][x / GRID] = '0';
		door->time = 0;
	}
	if (p->map_check[y / GRID][x / GRID] == 'D')
		door->time = 0;
}

int		door_open_close(t_player *p, t_sp *door)
{
	int x;
	int	y;
	int	tmp;

	y = door->y_pos;
	x = door->x_pos;
	if (door->time > 0)
		door->time--;
	if (p->key->e == 1 && door->time == 0)
	{
		if (door->range <= GRID * 2)
		{
			tmp = p->map[y / GRID][x / GRID];
			if ((int)p->y_axis / GRID == y / GRID)
				if ((int)p->x_axis / GRID == x / GRID)
					return (0);
			if (tmp == 'D')
				door->hit_time = 1;
			else
				door->hit_time = -1;
			door->time = 40;
		}
	}
	door_open_close2(p, door);
	return (0);
}
