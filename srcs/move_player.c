/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:43:49 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 12:04:05 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move(t_player *p, int move_front)
{
	int		range;
	int		speed_buf;
	double	tmp_x;
	double	tmp_y;

	range = 0;
	speed_buf = (p->key->down == 1 ? 2 : 1);
	while (range <= p->move_range * speed_buf)
	{
		tmp_x = (range + 3) * cos(p->angle) * move_front + p->x_axis;
		tmp_y = p->y_axis;
		if (can_move(p, tmp_x, tmp_y, p->ver_angle) == 1)
		{
			p->x_axis = 1 * cos(p->angle) * move_front + p->x_axis;
		}
		tmp_x = p->x_axis;
		tmp_y = (range + 3) * sin(p->angle) * move_front + p->y_axis;
		if (can_move(p, tmp_x, tmp_y, p->ver_angle) == 1)
		{
			p->y_axis = 1 * sin(p->angle) * move_front + p->y_axis;
		}
		range++;
	}
	return (0);
}

int	ft_turn(t_player *p, int turn_right)
{
	double	turn_buf;

	turn_buf = 1;
	if (p->key->down == 1)
		turn_buf = 1.5;
	p->angle = p->angle + (TURN_SPEED * turn_buf) * turn_right;
	return (0);
}

int	ft_slide(t_player *p, int slide_right)
{
	int		range;
	double	tmp_x;
	double	tmp_y;
	float	move_angle;
	int		speed_buf;

	move_angle = p->angle + PI / 2 * slide_right;
	range = 0;
	speed_buf = (p->key->down == 1 ? 2 : 1);
	while (range <= p->move_range * speed_buf)
	{
		tmp_x = (range + 3) * cos(move_angle) + p->x_axis;
		tmp_y = p->y_axis;
		if (can_move(p, tmp_x, tmp_y, p->ver_angle) == 1)
			p->x_axis = 1 * cos(move_angle) + p->x_axis;
		tmp_x = p->x_axis;
		tmp_y = (range + 3) * sin(move_angle) + p->y_axis;
		if (can_move(p, tmp_x, tmp_y, p->ver_angle) == 1)
		{
			p->y_axis = 1 * sin(move_angle) + p->y_axis;
		}
		range++;
	}
	return (0);
}

int	ft_look_up(t_player *p, int up_down)
{
	p->ver_angle = p->ver_angle + 0.1 * up_down;
	if (up_down == 0)
		p->ver_angle = 0;
	return (0);
}
