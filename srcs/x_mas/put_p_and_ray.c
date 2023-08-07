/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_and_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:51:57 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 13:46:41 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_point(t_player *p, int og_x, int og_y, int color)
{
	int win_x;
	int win_y;

	win_x = og_x / MINI_POS - 2;
	win_y = og_y / MINI_POS - 2;
	while (win_y <= og_y / MINI_POS)
	{
		while (win_x <= og_x / MINI_POS)
		{
			my_mlx_pixel_put_mini(p, win_x, win_y, color);
			win_x++;
		}
		win_x = og_x / MINI_POS - 2;
		win_y++;
	}
	return (0);
}

int		ray_put_front(t_player *p)
{
	int		ray_range;
	double	x_pos;
	double	y_pos;

	ray_range = 1;
	x_pos = p->x_axis;
	y_pos = p->y_axis;
	while (1)
	{
		x_pos = cos(p->angle) * ray_range + x_pos;
		y_pos = sin(p->angle) * ray_range + y_pos;
		if (within_screen_range(p, x_pos, y_pos) == 0)
			return (0);
		my_mlx_pixel_put_mini(p, x_pos / MINI_POS, y_pos / MINI_POS, RED);
	}
	return (0);
}

void	put_mass(t_player *p)
{
	int	win_x;
	int	win_y;

	win_x = 0;
	win_y = 0;
	while (win_x / MINI_POS < p->win_width * p->mini_grid_ratio)
	{
		while (win_y < p->win_height * p->mini_grid_ratio)
		{
			my_mlx_pixel_put_mini(p, win_x / MINI_POS, win_y, GRAY);
			win_y++;
		}
		win_x = win_x + GRID;
		win_y = 0;
	}
	while (win_y / MINI_POS < p->win_height * p->mini_grid_ratio)
	{
		win_x = 0;
		while (win_x < p->win_width * p->mini_grid_ratio)
		{
			my_mlx_pixel_put_mini(p, win_x, win_y / MINI_POS, GRAY);
			win_x++;
		}
		win_y = win_y + GRID;
	}
}

int		check_wall(t_player *p, int x, int y)
{
	if (y / GRID > p->map_max_y)
		return (MAP_WALL);
	if (x < 0 || y < 0)
		return (0);
	if (p->map[y / GRID][x / GRID] == MAP_WALL)
	{
		return (MAP_WALL);
	}
	if (p->map[y / GRID][x / GRID] == MAP_WALL_HIDEN)
	{
		return (MAP_WALL);
	}
	if (p->map[y / GRID][x / GRID] == MAP_FLOOR_2F)
	{
		return (MAP_FLOOR_2F);
	}
	if (p->map[y / GRID][x / GRID] == MAP_FLOOR_3F)
	{
		return (MAP_FLOOR_3F);
	}
	if (p->map[y / GRID][x / GRID] == MAP_DOOR)
	{
		return (MAP_DOOR);
	}
	return (0);
}

int		put_p_and_ray(t_player *p)
{
	if (OMIT_LINE != 1 || p->is_bonus)
		put_mass(p);
	if (OMIT_LINE != 1 || p->is_bonus)
		ray_put_front(p);
	validate_angle(p);
	put_point(p, p->x_axis, p->y_axis, WHITE);
	put_rays(p);
	return (0);
}
