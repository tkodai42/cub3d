/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_soul_enemy_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:40:24 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 14:45:04 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_lostsoul_is_dead(t_player *p, t_sp *sp)
{
	int		tex_num;

	tex_num = 0;
	p->tmp = 0;
	if (sp->hit_time < 5)
		tex_num = TEX_ENEMY2_DEAD1;
	else if (sp->hit_time < 10)
		tex_num = TEX_ENEMY2_DEAD2;
	else if (sp->hit_time < 15)
		tex_num = TEX_ENEMY2_DEAD3;
	else if (sp->hit_time < 20)
		tex_num = TEX_ENEMY2_DEAD4;
	else if (sp->hit_time < 25)
		tex_num = TEX_ENEMY2_DEAD5;
	else
		tex_num = TEX_ENEMY2_DEAD6;
	sp->tex_num = tex_num;
	return (0);
}

int		get_tex_lostsoul_is_nt(t_player *p, t_sp *sp)
{
	p->tmp = 0;
	if (p->frame % 10 < 5)
		sp->tex_num = TEX_ENEMY2_NEUTRAL_1;
	else
		sp->tex_num = TEX_ENEMY2_NEUTRAL_2;
	return (0);
}

void	get_tex_lostsoul2(double angle, int *tex_num)
{
	if (angle < PI / 8)
		*tex_num = TEX_ENEMY2_A;
	else if (angle < PI * 3 / 8)
		*tex_num = TEX_ENEMY2_B;
	else if (angle < PI * 5 / 8)
		*tex_num = TEX_ENEMY2_C;
	else if (angle < PI * 7 / 8)
		*tex_num = TEX_ENEMY2_D;
	else if (angle < PI * 9 / 8)
		*tex_num = TEX_ENEMY2_E;
	else if (angle < PI * 11 / 8)
		*tex_num = TEX_ENEMY2_F;
	else if (angle < PI * 13 / 8)
		*tex_num = TEX_ENEMY2_G;
	else if (angle < PI * 15 / 8)
		*tex_num = TEX_ENEMY2_H;
	else
		*tex_num = TEX_ENEMY2_A;
}

int		get_tex_lostsoul(t_player *p, t_sp *sp)
{
	double	angle;
	int		tex_num;

	tex_num = 0;
	p->tmp = 0;
	angle = sp->move_angle - sp->angle;
	angle = angle + PI;
	angle = make_validate_angle(angle);
	get_tex_lostsoul2(angle, &tex_num);
	sp->tex_num = tex_num;
	if (sp->time < ENEMY2_ATTACK_TIME)
		get_tex_lostsoul_is_nt(p, sp);
	if (sp->health_point == 0)
		get_tex_lostsoul_is_dead(p, sp);
	return (0);
}
