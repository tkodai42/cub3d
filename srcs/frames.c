/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:53:03 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 16:03:26 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		frame_count(t_player *p)
{
	int tmp;

	p->frame++;
	if (p->frame == 100000)
		p->frame = 0;
	if (1)
	{
		tmp = p->frame % 100;
		if (1)
			p->frame_u_d_pos = tmp * 0.01;
		if (tmp >= 25)
			p->frame_u_d_pos = (25 - (tmp - 25)) * 0.01;
		if (tmp >= 50)
			p->frame_u_d_pos = (tmp - 50) * 0.01;
		if (tmp >= 75)
			p->frame_u_d_pos = (25 - (tmp - 75)) * 0.01;
	}
	if (p->lost_soul_num > 0)
		p->no_more_lost_soul = 1;
	else
		p->no_more_lost_soul = 0;
	if (p->score->cyber_demon > 0)
		ft_error(p, 11);
	return (0);
}
