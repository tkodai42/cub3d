/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press_or_release.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:35:15 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/06 17:04:19 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_pressed_bonus(int key, t_player *p)
{
	if (key == KEY_UP)
		p->key->up = 1;
	if (key == KEY_DOWN)
		p->key->down = 1;
	if (key == KEY_F)
		p->key->f = 1;
	if (key == KEY_SP)
		p->key->sp = 1;
	if (key == KEY_U)
		p->key->u = 1;
	if (key == KEY_J)
		p->key->j = 1;
	if (key == KEY_E)
		p->key->e = 1;
	if (key == KEY_M)
		p->key->m = 1;
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
	{
		if (p->weapon->type != KEY_3 && key == KEY_3)
			p->key->shot = 3;
		p->weapon->type = key;
	}
	if (key == KEY_SHIFT_L)
		p->key->shift = 1;
}

void	ft_key_pressed2(int key, t_player *p)
{
	if (key == KEY_RIGHT)
	{
		p->key->right = 1;
		p->key->left = 0;
	}
	if (key == KEY_LEFT)
	{
		p->key->left = 1;
		p->key->right = 0;
	}
	if (key == KEY_ESC)
	{
		ft_error(p, 1);
	}
}

int		ft_key_pressed(int key, t_player *p)
{
	if (key == KEY_W)
	{
		p->key->w = 1;
		p->key->s = 0;
	}
	if (key == KEY_S)
	{
		p->key->s = 1;
		p->key->w = 0;
	}
	if (key == KEY_D)
	{
		p->key->d = 1;
		p->key->a = 0;
	}
	if (key == KEY_A)
	{
		p->key->a = 1;
		p->key->d = 0;
	}
	ft_key_pressed2(key, p);
	ft_key_pressed_bonus(key, p);
	ft_reflect_key(p);
	return (0);
}

void	ft_key_released_bonus(int key, t_player *p)
{
	if (key == KEY_UP)
		p->key->up = 0;
	else if (key == KEY_DOWN)
		p->key->down = 0;
	else if (key == KEY_F)
		p->key->f = 0;
	else if (key == KEY_SP)
		p->key->sp = 0;
	else if (key == KEY_U)
		p->key->u = 0;
	else if (key == KEY_J)
		p->key->j = 0;
	else if (key == KEY_E)
		p->key->e = 0;
	else if (key == KEY_SHIFT_L)
		p->key->shift = 0;
}

int		ft_key_released(int key, t_player *p)
{
	if (key == KEY_W)
		p->key->w = 0;
	else if (key == KEY_S)
		p->key->s = 0;
	else if (key == KEY_D)
		p->key->d = 0;
	else if (key == KEY_A)
		p->key->a = 0;
	else if (key == KEY_RIGHT)
		p->key->right = 0;
	else if (key == KEY_LEFT)
		p->key->left = 0;
	else
		ft_key_released_bonus(key, p);
	ft_reflect_key(p);
	return (0);
}
