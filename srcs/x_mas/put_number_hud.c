/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_hud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:59:40 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/06 15:57:37 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_num(int num)
{
	int tex_num;

	tex_num = 0;
	if (num == 0)
		tex_num = TEX_NUMBER_0;
	if (num == 1)
		tex_num = TEX_NUMBER_1;
	if (num == 2)
		tex_num = TEX_NUMBER_2;
	if (num == 3)
		tex_num = TEX_NUMBER_3;
	if (num == 4)
		tex_num = TEX_NUMBER_4;
	if (num == 5)
		tex_num = TEX_NUMBER_5;
	if (num == 6)
		tex_num = TEX_NUMBER_6;
	if (num == 7)
		tex_num = TEX_NUMBER_7;
	if (num == 8)
		tex_num = TEX_NUMBER_8;
	if (num == 9)
		tex_num = TEX_NUMBER_9;
	return (tex_num);
}

int		get_tex_color_from_x_y_ratio(t_dir *tex, double x_pos, double y_pos)
{
	int color;
	int x;
	int y;

	x = tex->xpm_width * x_pos;
	y = tex->xpm_height * y_pos;
	color = *(unsigned int *)(tex->addr + y * tex->line_len + x * 4);
	return (color);
}

void	put_num_hud(t_player *p, t_num *num, t_dir *tex)
{
	t_put_num_hud2	pn;

	num->tex_x_pos = 0;
	num->tex_y_pos = 0;
	pn.x_pos = p->win_width - num->wrote_digit * num->width;
	pn.y_pos = 0;
	pn.width = num->width;
	pn.height = pn.width * ((double)tex->xpm_height / tex->xpm_width);
	while (num->tex_y_pos < pn.height)
	{
		pn.x_pos = p->win_width - num->wrote_digit * num->width;
		while (num->tex_x_pos < pn.width)
		{
			pn.color = get_tex_color_from_x_y_ratio(tex, num->tex_x_pos /
					pn.width, num->tex_y_pos / pn.height);
			if (pn.color >= 0)
				my_mlx_pixel_put(p, pn.x_pos, pn.y_pos, pn.color + 0x22000000);
			num->tex_x_pos++;
			pn.x_pos++;
		}
		num->tex_x_pos = 0;
		num->tex_y_pos++;
		pn.y_pos++;
	}
}

int		put_to_img_hud(t_player *p, t_num *num, int number)
{
	int		tex_num;
	t_dir	*tex;

	tex_num = get_tex_num(number);
	tex = find_tex_from_list(p, tex_num);
	put_num_hud(p, num, tex);
	return (0);
}

int		put_number_hud(t_player *p)
{
	t_num	num;

	if (ONLY_SKYBOX)
		if (p->key->down == 1)
			p->kill_count++;
	num.num = p->kill_count;
	num.digit = 3;
	num.width = p->win_width / 3 / (num.digit + 1);
	num.wrote_digit = 1;
	while (num.num > 9)
	{
		put_to_img_hud(p, &num, num.num % 10);
		num.num = num.num / 10;
		num.wrote_digit++;
	}
	put_to_img_hud(p, &num, num.num);
	put_num_ammo(p);
	return (0);
}
