/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:08:38 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 12:31:41 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_background2(t_player *p, int x, int y)
{
	while (y < p->win_height)
	{
		while (x < p->win_width)
		{
			my_mlx_pixel_put_mini2(p, x, y, BLACK);
			if (p->is_bonus == 0)
				my_mlx_pixel_put(p, x, y, p->floor_color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_draw_background(t_player *p)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= p->win_height / 2)
	{
		while (x < p->win_width)
		{
			my_mlx_pixel_put_mini2(p, x, y, BLACK);
			if (p->is_bonus == 0)
				my_mlx_pixel_put(p, x, y, p->loof_color);
			x++;
		}
		x = 0;
		y++;
	}
	ft_draw_background2(p, x, y);
}

void	draw_floor_is_not_bonus(t_player *p)
{
	int	i;

	i = 0;
	while (i < p->win_width)
	{
		p->buf_draw_valid_height[i] = 10000;
		p->buf_draw_f_range[i] = 100000;
		p->buf_draw_vh_head_pos[i] = 100000;
		i++;
	}
}

int		ft_draw_to_img(t_player *p)
{
	ft_draw_background(p);
	if (p->is_bonus)
		ft_put_skybox(p);
	if (p->is_bonus)
	{
		ft_draw_floor(p, 0);
	}
	else
		draw_floor_is_not_bonus(p);
	return (0);
}
