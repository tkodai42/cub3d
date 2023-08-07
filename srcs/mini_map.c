/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:27:24 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/06 18:22:52 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put_mini(t_player *p, int x, int y, int color)
{
	char	*dst;

	if (KILL_MINI)
		return ;
	x = x * ((double)p->mini_grid / GRID);
	y = y * ((double)p->mini_grid / GRID);
	if (x > p->win_width || y > p->win_height)
		return ;
	color += 0x77000000;
	dst = p->mini_addr + (y * p->mini_line_length + x *
			(p->mini_bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_mini_map(t_player *p)
{
	p->mini_ptr = mlx_new_image(p->mlx_ptr, p->win_width, p->win_height);
	p->mini_addr = mlx_get_data_addr(p->mini_ptr, &p->mini_bit_per_pixel,
			&p->mini_line_length, &p->mini_endian);
	return (0);
}
