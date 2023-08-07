/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:00:13 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/02 16:14:55 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_get_jump_factor(t_player *p)
{
	double all;
	double speed;

	all = 0;
	speed = 0;
	while (JUMP_HEIGHT > all)
	{
		speed += JUMP_GRAVITY;
		all += speed;
	}
	speed = speed - JUMP_GRAVITY;
	p->jump_inital_velocity = speed;
	return (0);
}

void	ft_jump3(t_player *p, double crouch, double height)
{
	if (p->ver_angle <= height)
	{
		p->ver_angle = height - crouch;
		p->jump->stop_flag = 1;
	}
}

void	ft_jump2(t_player *p, double crouch)
{
	p->ver_angle += p->jump->jump_speed;
	p->jump_pos += 1;
	if (p->jump->floor == MAP_FLOOR_1F)
	{
		ft_jump3(p, crouch, 0);
	}
	if (p->jump->floor == MAP_FLOOR_2F || p->jump->floor == MAP_SPRITE
			|| p->jump->floor == MAP_DRUM)
	{
		if (p->ver_angle <= 1)
		{
			p->ver_angle = 1 - crouch;
			p->jump->stop_flag = 1;
		}
	}
	if (p->jump->floor == MAP_WALL_HIDEN)
	{
		if (p->ver_angle <= 2.0)
		{
			p->ver_angle = 2.0 - crouch;
			p->jump->stop_flag = 1;
		}
	}
}

int		ft_jump(t_player *p, int fall_down, double crouch)
{
	p->jump->floor = p->map[(int)p->y_axis / 64][(int)p->x_axis / 64];
	if (p->jump->floor == MAP_WALL_HIDEN)
		fall_down = 1;
	if (fall_down)
	{
		p->jump_pos = 1;
		p->key->jump = 1;
		p->jump->jump_speed = 0;
	}
	p->jump->stop_flag = 0;
	if (p->jump_pos == 0)
	{
		p->jump->jump_speed = p->jump_inital_velocity;
		p->key->jump = 1;
	}
	else
		p->jump->jump_speed -= JUMP_GRAVITY;
	ft_jump2(p, crouch);
	if (p->jump->stop_flag == 1)
	{
		p->jump_pos = 0;
		p->jump->jump_speed = 0;
		p->key->jump = 0;
	}
	return (0);
}

int		get_player_height(t_player *p, double crouch)
{
	if (p->key->jump == 1)
		return (0);
	ft_jump(p, 1, crouch);
	return (0);
}
