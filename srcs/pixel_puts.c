/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_puts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:16:34 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 18:42:35 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_player *p, int x, int y, int color)
{
	char	*dst;

	if (p->key->down == 1)
	{
		if (p->key->map_on_off == 0)
			color += 0xFF000000;
		else
			color += 0xC0000000;
	}
	else
		color += 0x000000;
	dst = p->img_addr + (y * p->img_line_length + x *
			(p->img_bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put_mini2(t_player *p, int x, int y, int color)
{
	char	*dst;

	color += 0x99000000;
	if (KILL_MINI)
		return ;
	dst = p->mini_addr + (y * p->img_line_length + x *
			(p->img_bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put_hud(t_player *p, int x, int y, int color)
{
	char	*dst;

	dst = p->hud->addr + (y * p->img_line_length + x *
			(p->img_bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}
