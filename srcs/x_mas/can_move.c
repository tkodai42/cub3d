/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:25:21 by tkodai            #+#    #+#             */
/*   Updated: 2020/10/16 12:28:15 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		can_move(t_player *p, double x_pos, double y_pos, double height)
{
	int		map_height;

	height = height + (p->key->shift == 1 ? CROUCH_HEIGHT : 0);
	if (y_pos < 0 || x_pos < 0)
		return (0);
	map_height = p->map[(int)y_pos / GRID][(int)x_pos / GRID];
	if (map_height == MAP_FLOOR_1F)
		return (1);
	if (map_height == MAP_WALL_HIDEN && height >= 2.0)
		return (1);
	if ((map_height == MAP_SPRITE || map_height == MAP_DRUM) && height >= 1.0)
		return (1);
	if (map_height == MAP_FLOOR_2F)
		if (height >= 1.0)
			return (1);
	if (map_height == MAP_FLOOR_3F)
		if (height >= 2.0)
			return (1);
	return (0);
}
