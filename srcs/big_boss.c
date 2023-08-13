/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_boss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:27:57 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/02 16:38:23 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		facing_player(t_player *p, t_sp *boss)
{
	double face_boss_angle;

	p->tmp = 0;
	face_boss_angle = boss->move_angle - (boss->angle + PI);
	while (face_boss_angle < 0)
		face_boss_angle = face_boss_angle + PI * 2;
	while (face_boss_angle > PI)
		face_boss_angle = face_boss_angle - PI * 2;
	if (face_boss_angle > 0)
		boss->move_angle += PI / 128 / 2 * -1;
	else
		boss->move_angle += PI / 128 / 2;
	return (0);
}

int		get_tex_boss(t_player *p, t_sp *sp)
{
	double	angle;
	int		tex_num;

	tex_num = 0;
	p->tmp = 0;
	angle = sp->move_angle - sp->angle;
	angle = angle + PI;
	angle = make_validate_angle(angle);
	get_tex_boss3(p, sp, angle);
	if (sp->time < 250)
		get_tex_boss2(p, sp);
	if ((PI * 5 / 8 < angle && angle < PI * 11 / 8) && sp->inside_aiming == 1 &&
			p->key->shot == P_SHOT_HIT_TIME && sp->health_point &&
			p->weapon->type != KEY_4)
	{
		sp->health_point--;
		p->score->hit++;
		sp->time = -30;
	}
	if (sp->time < 0)
		get_tex_boss_hit(sp);
	if (sp->health_point <= 0)
		get_tex_boss_dead(p, sp);
	return (0);
}

int		move_boss(t_player *p, t_sp *boss)
{
	double	tmp_x;
	double	tmp_y;
	int		tmp_range;
	int		move_range;

	tmp_range = 1;
	move_range = 1;
	while (tmp_range <= move_range)
	{
		tmp_x = cos(boss->move_angle) * GRID + boss->x_pos;
		if (check_wall(p, tmp_x, boss->y_pos) == 0)
			boss->x_pos = cos(boss->move_angle) + boss->x_pos;
		tmp_y = sin(boss->move_angle) * GRID + boss->y_pos;
		if (check_wall(p, boss->x_pos, tmp_y) == 0)
			boss->y_pos = sin(boss->move_angle) + boss->y_pos;
		tmp_range++;
	}
	return (0);
}

void	big_boss(t_player *p, t_sp *boss)
{
	boss->time++;
	if (boss->time > 500)
		boss->time = 0;
	if (boss->time > 250)
	{
		facing_player(p, boss);
		if (boss->time > 230 && boss->time % 6 == 0 && boss->health_point > 0)
			add_list_bullet(p, ENEMY_BULLET, boss);
	}
	else
	{
		boss->move_angle = boss->angle + PI;
		if (boss->time < 230)
			move_boss(p, boss);
	}
	boss->health_point <= 0 ? boss->hit_time++ : (p->boss_is_exists = 1);
	if (boss->hit_time > 100)
	{
		boss->alive = 0;
		p->killed_flag++;
		p->score->cyber_demon++;
		p->boss_spawn = -1;
	}
	get_tex_boss(p, boss);
	boss->tex = find_tex_from_list(p, boss->tex_num);
}
