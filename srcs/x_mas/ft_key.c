/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:26:45 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/06 18:18:48 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tmp_bullet_init(t_player *p, t_sp *p_sp)
{
	p_sp->angle = p->angle;
	p_sp->move_angle = p->angle;
	p_sp->range = 200;
	p_sp->x_pos = cos(p->angle) * 64 + p->x_axis;
	p_sp->y_pos = sin(p->angle) * 64 + p->y_axis;
	p_sp->z_pos = p->ver_angle - 0.1;
}

void	tmp_bullet(t_player *p)
{
	t_sp	p_sp;

	tmp_bullet_init(p, &p_sp);
	add_list_bullet(p, TEX_STTP_BULLET, &p_sp);
}


int	ft_reflect_key_bonus(t_player *p)
{
	if (p->key->u == 1)
		ft_look_up(p, 1);
	if (p->key->down == 1)
		ft_look_up(p, -1);
	if (p->key->f == 1)
		ft_look_up(p, 0);
	if (p->key->sp == 1 || p->key->jump == 1)
		ft_jump(p, 0, 0);
	if (p->key->up == 1 || p->key->shot >= 1)
	{
		ft_shot(p);
		// player blaster
//		if (p->key->shot == 1)
//			tmp_bullet(p);
	}
	if (p->key->m == 1)
		ft_map_on(p);
	if (p->key->u == 0)
		get_player_height(p, 0);
	if (p->key->shift == 1)
		get_player_height(p, CROUCH_HEIGHT);
	return (0);
}

int	ft_reflect_key(t_player *p)
{
	if (p->key->w == 1)
		ft_move(p, 1);
	if (p->key->s == 1)
		ft_move(p, -1);
	if (p->key->d == 1)
		ft_slide(p, 1);
	if (p->key->a == 1)
		ft_slide(p, -1);
	if (p->key->right == 1)
		ft_turn(p, 1);
	if (p->key->left == 1)
		ft_turn(p, -1);
	ft_reflect_key_bonus(p);
	ft_cub3d3(p);
	return (0);
}
