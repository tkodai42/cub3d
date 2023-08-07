/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_health.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:53:30 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/04 14:30:11 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_blood_hud(t_player *p)
{
	long	color;
	int		x;
	int		y;
	int		tmp;

	color = RED;
	x = 0;
	y = 0;
	tmp = p->health->point;
	if (99 >= tmp && tmp >= 40)
		tmp = 100;
	color = color + (long)256 * 256 * 256 * (255 - (100 - tmp));
	while (y < p->win_height)
	{
		while (x < p->win_width)
		{
			my_mlx_pixel_put_hud(p, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		put_life_var2(t_player *p)
{
	int	x_pos;
	int y_pos;
	int	len;
	int	width;
	int	health_width;

	width = p->win_width / 3;
	health_width = width * (p->health->point / 100);
	x_pos = p->win_width / 30;
	y_pos = p->win_width / 30;
	len = 0;
	while (y_pos < width / 4)
	{
		while (len < health_width)
		{
			my_mlx_pixel_put(p, x_pos++, y_pos, LIME);
			len++;
		}
		len = 0;
		y_pos++;
		x_pos = p->win_width / 30;
	}
	return (0);
}

int		put_life_var(t_player *p)
{
	int	x_pos;
	int y_pos;
	int	len;
	int	width;

	width = p->win_width / 3;
	x_pos = p->win_width / 30;
	y_pos = p->win_width / 30;
	len = 0;
	while (y_pos < width / 4)
	{
		while (len < width)
		{
			my_mlx_pixel_put(p, x_pos++, y_pos, RED);
			len++;
		}
		len = 0;
		y_pos++;
		x_pos = p->win_width / 30;
	}
	put_life_var2(p);
	return (0);
}

int		ft_player_health(t_player *p)
{
	if (p->health->last_point > p->health->point)
		p->health->time = 0;
	if (p->health->point < 100)
	{
		if (p->health->time++ > 200)
		{
			p->health->point += (0.25 * (p->health->time - 200) / 4);
			if (p->health->point >= 100)
			{
				p->health->time = 0;
				p->health->point = 100;
			}
		}
	}
	if (p->health->point < 0)
		p->health->point = 0;
	p->health->last_point = p->health->point;
	put_life_var(p);
	put_blood_hud(p);
	put_number_hud(p);
	if (IMMORTAL == 0)
		if (p->health->point <= 0)
			ft_error(p, 11);
	return (0);
}
