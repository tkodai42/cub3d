/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_boss_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:33:30 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/02 16:38:21 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_boss2(t_player *p, t_sp *sp)
{
	int	time;

	p->tmp = 0;
	time = sp->time % 32;
	if (time <= 7)
		sp->tex_num = TEX_BOSS_WALK1;
	else if (time <= 15)
		sp->tex_num = TEX_BOSS_WALK2;
	else if (time <= 23)
		sp->tex_num = TEX_BOSS_WALK3;
	else
		sp->tex_num = TEX_BOSS_WALK4;
	if (sp->time > 230)
		sp->tex_num = TEX_BOSS_0;
	return (0);
}

int		get_tex_boss_dead(t_player *p, t_sp *sp)
{
	p->tmp = 0;
	if (sp->hit_time < 10)
		sp->tex_num = TEX_BOSS_DEAD1;
	else if (sp->hit_time < 20)
		sp->tex_num = TEX_BOSS_DEAD2;
	else if (sp->hit_time < 30)
		sp->tex_num = TEX_BOSS_DEAD3;
	else if (sp->hit_time < 40)
		sp->tex_num = TEX_BOSS_DEAD4;
	else if (sp->hit_time < 50)
		sp->tex_num = TEX_BOSS_DEAD5;
	else
		sp->tex_num = TEX_BOSS_DEAD6;
	return (0);
}

int		get_tex_boss_hit(t_sp *sp)
{
	if (sp->time < -10)
		sp->tex_num = TEX_BOSS_DAMEGE2;
	else
		sp->tex_num = TEX_BOSS_DAMEGE1;
	return (0);
}

void	get_tex_boss3(t_player *p, t_sp *sp, double angle)
{
	p->tmp = 0;
	if (angle < PI / 8)
		sp->tex_num = TEX_BOSS_A;
	else if (angle < PI * 3 / 8)
		sp->tex_num = TEX_BOSS_B;
	else if (angle < PI * 5 / 8)
		sp->tex_num = TEX_BOSS_C;
	else if (angle < PI * 7 / 8)
		sp->tex_num = TEX_BOSS_D;
	else if (angle < PI * 9 / 8)
		sp->tex_num = TEX_BOSS_E;
	else if (angle < PI * 11 / 8)
		sp->tex_num = TEX_BOSS_F;
	else if (angle < PI * 13 / 8)
		sp->tex_num = TEX_BOSS_G;
	else if (angle < PI * 15 / 8)
		sp->tex_num = TEX_BOSS_H;
	else
		sp->tex_num = TEX_BOSS_A;
}
