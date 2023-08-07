/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_darker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:06:16 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 14:38:41 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		put_blood(t_player *p, int *color1, int *color2, int *color3)
{
	int		bc;
	int		hp;

	return (0);
	if (p->health->point >= 50)
		return (0);
	hp = p->health->point * 2;
	bc = 100 - hp;
	bc = bc / 2;
	hp = 100 - bc;
	*color1 = *color1 * hp / 100 + 256 * bc / 100;
	*color2 = *color2 * hp / 100;
	*color3 = *color3 * hp / 100;
	p->tmp = 0;
	return (0);
}

void	get_darker2(int *tmp, int muzzle_flash, double range)
{
	*tmp -= range / (DARKER_RATIO + muzzle_flash);
	if (*tmp < 0)
		*tmp = 1;
}

int		get_darker(t_player *p, int color, double range)
{
	int tmp1;
	int tmp2;
	int tmp3;
	int	muzzle_flash;

	if (color == LIME)
	{
		if (p->boss_is_exists == 1)
			return (RED);
		return (color);
	}
	tmp3 = color % 256;
	color = color / 256;
	tmp2 = color % 256;
	color = color / 256;
	tmp1 = color;
	muzzle_flash = 0;
	if (1 <= p->key->shot && p->key->shot < 5)
		muzzle_flash = 20 * 100;
	get_darker2(&tmp1, muzzle_flash, range);
	get_darker2(&tmp2, muzzle_flash, range);
	get_darker2(&tmp3, muzzle_flash, range);
	put_blood(p, &tmp1, &tmp2, &tmp3);
	color = tmp1 * 256 * 256 + tmp2 * 256 + tmp3;
	return (color);
}

void	get_darker_sprite2(int *tmp, int muzzle_flash, double range)
{
	*tmp -= range / (DARKER_RATIO + muzzle_flash);
	if (*tmp <= 0)
		*tmp = 1;
}

int		get_darker_sprite(t_player *p, int color, double range)
{
	int tmp1;
	int tmp2;
	int tmp3;
	int	muzzle_flash;

	if (BONUS_DARKER == 0)
		return (color);
	if (color <= 0)
		return (color);
	tmp3 = color % 256;
	color = color / 256;
	tmp2 = color % 256;
	color = color / 256;
	tmp1 = color;
	muzzle_flash = (1 <= p->key->shot && p->key->shot < 5) ? 20 * 20 : 0;
	if (tmp1 > 0)
		get_darker_sprite2(&tmp1, muzzle_flash, range);
	if (tmp2 > 0)
		get_darker_sprite2(&tmp2, muzzle_flash, range);
	if (tmp3 > 0)
		get_darker_sprite2(&tmp3, muzzle_flash, range);
	put_blood(p, &tmp1, &tmp2, &tmp3);
	color = tmp1 * 256 * 256 + tmp2 * 256 + tmp3;
	return (color);
}
