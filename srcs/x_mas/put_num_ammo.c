/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_hud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:59:40 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 12:47:28 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_digit2(int num)
{
	int	digit;

	digit = 1;
	while (num > 9)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

int		get_tex_num2(int num)
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

int		put_to_img_hud2(t_player *p, t_num *num, int number)
{
	int		tex_num;
	t_dir	*tex;

	tex_num = get_tex_num2(number);
	tex = find_tex_from_list(p, tex_num);
	put_num_hud2(p, num, tex);
	return (0);
}

void	cheat_increase_ammo(t_player *p)
{
	if (p->weapon->type == KEY_1)
	{
		p->weapon->ammo_1++;
		if (p->weapon->ammo_1 > 999)
			p->weapon->ammo_1 = 999;
	}
	if (p->weapon->type == KEY_2)
	{
		p->weapon->ammo_2 += 10;
		if (p->weapon->ammo_2 > 999)
			p->weapon->ammo_2 = 999;
	}
	if (p->weapon->type == KEY_3)
	{
		p->weapon->ammo_3++;
		if (p->weapon->ammo_3 > 999)
			p->weapon->ammo_3 = 999;
	}
}

int		put_num_ammo(t_player *p)
{
	t_num	num;

	if (p->key->u == 1 && p->key->f == 1)
		cheat_increase_ammo(p);
	if (p->weapon->type == KEY_1)
		num.num = p->weapon->ammo_1;
	if (p->weapon->type == KEY_2)
		num.num = p->weapon->ammo_2;
	if (p->weapon->type == KEY_3)
		num.num = p->weapon->ammo_3;
	if (p->weapon->type == KEY_4)
		return (0);
	if (num.num > 999)
		num.num = 999;
	num.digit = 4;
	num.width = p->win_width / 3 / (num.digit + 1);
	num.wrote_digit = 1;
	while (num.num > 9)
	{
		put_to_img_hud2(p, &num, num.num % 10);
		num.num = num.num / 10;
		num.wrote_digit++;
	}
	put_to_img_hud2(p, &num, num.num);
	return (0);
}
