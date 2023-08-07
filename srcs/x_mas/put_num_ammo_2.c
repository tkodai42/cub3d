/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_ammo_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:38:54 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/06 15:57:27 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_color_from_x_y_ratio2(t_dir *tex, double x_pos, double y_pos)
{
	int color;
	int x;
	int y;

	x = tex->xpm_width * x_pos;
	y = tex->xpm_height * y_pos;
	color = *(unsigned int *)(tex->addr + y * tex->line_len + x * 4);
	return (color);
}

void	put_num_hud2_init(t_player *p, t_num *num, t_dir *tex,
		t_put_num_hud2 *pnh2)
{
	num->tex_x_pos = 0;
	num->tex_y_pos = 0;
	pnh2->x_pos = p->win_width - num->wrote_digit * num->width;
	pnh2->y_pos = 0;
	pnh2->width = num->width;
	pnh2->height = pnh2->width * ((double)tex->xpm_height / tex->xpm_width);
	pnh2->y_pos = p->win_height - pnh2->height;
}

void	put_num_hud2(t_player *p, t_num *num, t_dir *tex)
{
	t_put_num_hud2	pnh2;

	put_num_hud2_init(p, num, tex, &pnh2);
	while (num->tex_y_pos < pnh2.height)
	{
		pnh2.x_pos = p->win_width - num->wrote_digit * num->width;
		while (num->tex_x_pos < pnh2.width)
		{
			pnh2.color = get_tex_color_from_x_y_ratio2(tex, num->tex_x_pos /
					pnh2.width, num->tex_y_pos / pnh2.height);
			if (pnh2.color >= 0)
				my_mlx_pixel_put(p, pnh2.x_pos, pnh2.y_pos, pnh2.color +
						0x22000000);
			num->tex_x_pos++;
			pnh2.x_pos++;
		}
		num->tex_x_pos = 0;
		num->tex_y_pos++;
		pnh2.y_pos++;
	}
}
