/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spawn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:44:18 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/09 13:12:54 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_spawn_point2(t_player *p, t_sp *sp)
{
	if (p->boss_spawn == 1 && sp->time == 0 && p->kill_count > 15)
	{
		add_list(p, TEX_BOSS_1, sp->x_pos, sp->y_pos);
		sp->time = 300;
		p->boss_spawn = -1;
		p->killed_flag++;
	}
	if (p->killed_flag > 0 && sp->time == 0)
	{
		add_list(p, ENEMY_1, sp->x_pos, sp->y_pos);
		p->killed_flag--;
		sp->time = 300;
	}
	if (sp->health_point > 0)
		sp->tex = find_tex_from_list(p, ENEMY_SP_POINT_N);
	else if (sp->tex_num == 2)
		sp->tex = find_tex_from_list(p, ENEMY_SP_POINT1_2);
	else if (sp->tex_num == 3)
		sp->tex = find_tex_from_list(p, ENEMY_SP_POINT1_3);
	else
		sp->tex = find_tex_from_list(p, ENEMY_SP_POINT1_1);
}

int		ft_spawn_point(t_player *p, t_sp *sp)
{
	sp->tex_num++;
	if (sp->time > 0)
		sp->time--;
	if (sp->tex_num > 3)
		sp->tex_num = 1;
	if (sp->range < GRID * 2)
		sp->time = 30;
	if (p->boss_spawn == -1)
		sp->health_point = -100;
	if (sp->inside_aiming == 1 && p->key->shot == P_SHOT_HIT_TIME)
		if (p->weapon->type != KEY_4)
			sp->health_point -= 1;
	if (p->frame % 400 == 0 && p->kill_count > 2 && p->no_more_lost_soul == 0)
	{
		add_list(p, ENEMY_2, sp->x_pos, sp->y_pos);
		sp->time += 30;
	}
	ft_spawn_point2(p, sp);
	return (0);
}
