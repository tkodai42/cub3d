/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drum.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:58:00 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 16:01:42 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drum_tex(t_player *p, t_sp *drum)
{
	if (drum->time > 10)
		drum->tex_num = TEX_DRUM_EXPROSION_3;
	else if (drum->time > 5)
		drum->tex_num = TEX_DRUM_EXPROSION_2;
	else if (drum->time >= 1)
		drum->tex_num = TEX_DRUM_EXPROSION_1;
	else
		drum->tex_num = MAP_DRUM;
	drum->tex = find_tex_from_list(p, drum->tex_num);
}

void	drum_explosion2(t_player *p, t_sp *drum)
{
	if (drum->time == 5)
		if (drum->range < GRID * 2)
			p->health->point += -30;
	if (drum->time >= 15)
	{
		drum->alive = 0;
		p->map[(int)drum->y_pos / GRID][(int)drum->x_pos / GRID] = '0';
	}
	drum_tex(p, drum);
}

void	drum_explosion(t_player *p, t_sp *drum)
{
	if (drum->time == 0)
	{
		if (drum->inside_aiming == 1 && p->key->shot == P_SHOT_HIT_TIME)
		{
			if (p->weapon->type == KEY_4 && drum->range > GRID)
			{
				drum_tex(p, drum);
				return ;
			}
			drum->time = 1;
			drum_tex(p, drum);
			return ;
		}
	}
	if (drum->time == 0)
	{
		drum_tex(p, drum);
		return ;
	}
	drum->time++;
	drum_explosion2(p, drum);
}
