/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:14:16 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 13:43:26 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_mini_square(t_player *p, int x, int y)
{
	int	win_x;
	int	win_y;
	int	start_pos_x;
	int	start_pos_y;

	if (OMIT_LINE && p->is_bonus == 0)
		return (0);
	start_pos_x = GRID * x;
	start_pos_y = GRID * y;
	win_x = start_pos_x;
	win_y = start_pos_y;
	while (win_y < start_pos_y + GRID)
	{
		while (win_x < start_pos_x + GRID)
		{
			my_mlx_pixel_put_mini(p, win_x, win_y, LIME);
			if (p->map[y])
				;
			win_x++;
		}
		win_x = start_pos_x;
		win_y++;
	}
	return (0);
}

int		put_minimap(t_player *p)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (p->map[y] && p->map[y][x])
	{
		while (p->map[y] && p->map[y][x])
		{
			if (ft_strchr("1", p->map[y][x]))
			{
				put_mini_square(p, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
