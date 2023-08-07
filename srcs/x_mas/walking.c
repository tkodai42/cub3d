/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:00:12 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/04 13:01:24 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_move(t_player *p)
{
	if (p->key->w == 1)
		return (1);
	if (p->key->a == 1)
		return (1);
	if (p->key->d == 1)
		return (1);
	if (p->key->s == 1)
		return (1);
	return (0);
}

int		ft_walking(t_player *p)
{
	int swing_width;

	if (p->key->down == 1)
		swing_width = 2;
	else
		swing_width = 1;
	if (p->key->jump > 0 || is_move(p) == 0 || p->key->shift)
	{
		p->walk->z_pos = 0;
		p->walk->time = 0;
		p->walk->angle = 0;
		p->walk->gun_x_pos = 0;
		return (0);
	}
	p->walk->time++;
	p->walk->angle += PI / 9;
	p->walk->z_pos = sin(p->walk->angle) * (-0.1 / swing_width);
	p->walk->gun_x_pos = cos(p->walk->angle / 2) * (20 * swing_width);
	if (fmod(p->walk->angle, (PI * 2)) > PI)
		p->walk->z_pos = p->walk->z_pos / 2;
	return (0);
}
