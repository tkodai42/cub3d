/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_shot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:00:09 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/04 17:21:27 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	gun_type_1(t_player *p, t_dir *gun_tex)
{
	if (p->key->shot <= 0)
		gun_tex = get_gun_tex(p, TEX_HANDGUN_1);
	else if (p->key->shot <= 3)
		gun_tex = get_gun_tex(p, TEX_HANDGUN_2);
	else if (p->key->shot <= 5)
		gun_tex = get_gun_tex(p, TEX_HANDGUN_4);
	else if (p->key->shot <= 7)
		gun_tex = get_gun_tex(p, TEX_HANDGUN_3);
	else
		gun_tex = get_gun_tex(p, TEX_HANDGUN_1);
	if (p->key->shot == 1)
		p->score->hg++;
	ft_put_gun2(p, gun_tex);
}

void	gun_type_2(t_player *p, t_dir *gun_tex)
{
	if ((p->key->shot <= 0 && p->weapon->time == 0) || p->key->up == 0)
		gun_tex = get_gun_tex(p, TEX_GUN2_1_1);
	else if (p->key->shot <= 0 && p->weapon->time == 1)
		gun_tex = get_gun_tex(p, TEX_GUN2_2_1);
	else if (p->weapon->time == 0)
		gun_tex = get_gun_tex(p, TEX_GUN2_1_2);
	else
		gun_tex = get_gun_tex(p, TEX_GUN2_2_2);
	if (p->key->shot == 1)
		p->score->mg++;
	ft_put_gun2(p, gun_tex);
}

void	gun_type_3(t_player *p, t_dir *gun_tex)
{
	if (p->key->shot <= 0)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_1);
	else if (p->key->shot <= 1)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_2);
	else if (p->key->shot <= 3)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_3);
	else if (p->key->shot <= 6)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_4);
	else if (p->key->shot <= 10)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_5);
	else if (p->key->shot <= 14)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_6);
	else if (p->key->shot <= 18)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_5);
	else if (p->key->shot <= 22)
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_4);
	else
		gun_tex = get_gun_tex(p, TEX_SHOTGUN_1);
	if (p->key->shot == 1)
		p->score->sg++;
	ft_put_gun2(p, gun_tex);
}

void	gun_type_4(t_player *p, t_dir *gun_tex)
{
	if (p->key->shot <= 0)
		gun_tex = get_gun_tex(p, TEX_FIST_1);
	else if (p->key->shot <= 1)
		gun_tex = get_gun_tex(p, TEX_FIST_2);
	else if (p->key->shot <= 3)
		gun_tex = get_gun_tex(p, TEX_FIST_3);
	else if (p->key->shot <= 6)
		gun_tex = get_gun_tex(p, TEX_FIST_4);
	else if (p->key->shot <= 10)
		gun_tex = get_gun_tex(p, TEX_FIST_3);
	else if (p->key->shot <= 14)
		gun_tex = get_gun_tex(p, TEX_FIST_2);
	else
		gun_tex = get_gun_tex(p, TEX_FIST_1);
	if (p->key->shot == 1)
		p->score->melee++;
	ft_put_gun2(p, gun_tex);
}

int		ft_put_gun(t_player *p)
{
	t_dir	*gun_tex;

	gun_tex = NULL;
	p->weapon->time++;
	if (p->weapon->time >= 2)
		p->weapon->time = 0;
	if (p->weapon->type == KEY_1)
		gun_type_1(p, gun_tex);
	if (p->weapon->type == KEY_2)
		gun_type_2(p, gun_tex);
	if (p->weapon->type == KEY_3)
		gun_type_3(p, gun_tex);
	if (p->weapon->type == KEY_4)
		gun_type_4(p, gun_tex);
	return (0);
}
