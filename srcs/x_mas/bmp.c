/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:04:40 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 18:46:58 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	header_init(char *cont, int width, int height)
{
	int		size;

	size = width * height * 3 + 54;
	*(unsigned int *)cont = (unsigned int)'B';
	*(unsigned int *)(cont + 1) = (unsigned int)'M';
	*(unsigned int *)(cont + 2) = (unsigned long)size;
	*(unsigned int *)(cont + 6) = (unsigned int)0;
	*(unsigned int *)(cont + 8) = (unsigned int)0;
	*(unsigned int *)(cont + 10) = (unsigned int)54;
	*(unsigned int *)(cont + 14) = (unsigned long)40;
	*(unsigned int *)(cont + 18) = (long)width;
	*(unsigned int *)(cont + 22) = (long)-height;
	*(unsigned int *)(cont + 26) = (unsigned int)1;
	*(unsigned int *)(cont + 28) = (unsigned int)24;
	*(unsigned int *)(cont + 30) = (unsigned long)0;
	*(unsigned int *)(cont + 34) = (unsigned long)(size - 54);
	*(unsigned int *)(cont + 38) = (long)0;
	*(unsigned int *)(cont + 42) = (long)0;
	*(unsigned int *)(cont + 46) = (unsigned long)0;
	*(unsigned int *)(cont + 50) = (unsigned long)0;
}

void	header_data(t_player *p, char *cont, int width, int height)
{
	char	*color;
	int		now;
	int		utils[3];

	header_init(cont, width, height);
	now = 54;
	utils[1] = 0;
	while (utils[1] < height)
	{
		utils[0] = 0;
		while (utils[0] < width)
		{
			color = p->img_addr + utils[0] * (p->img_bit_per_pixel / 8)\
			+ (utils[1] * p->img_line_length);
			*(unsigned char *)(cont + now++) = *(unsigned char *)color++;
			*(unsigned char *)(cont + now++) = *(unsigned char *)color++;
			*(unsigned char *)(cont + now++) = *(unsigned char *)color++;
			utils[0]++;
		}
		utils[2] = width % 4;
		while (utils[2]--)
			*(cont + now++) = 0;
		utils[1]++;
	}
}

int		save_bmp2(t_player *p)
{
	int		fd;
	char	*cont;
	int		padding;

	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		ft_error(p, ERROR_FD);
	padding = (p->win_width * 3) % 4;
	cont = malloc((p->win_width + padding) * p->win_height * 3 + 54 + 1);
	header_data(p, cont, p->win_width, p->win_height);
	write(fd, cont, (p->win_width + padding) * p->win_height * 3 + 54);
	close(fd);
	exit(0);
	return (0);
}

int		save_bmp(t_player *p)
{
	if (p->is_bonus)
	{
		frame_count(p);
		ft_enemy_move(p);
		ft_walking(p);
		put_sprite(p);
		ft_put_gun(p);
		ft_player_health(p);
	}
	save_bmp2(p);
	return (0);
}
