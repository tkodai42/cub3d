/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_soul_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:03:42 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 14:44:59 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_lost_soul2(t_player *p, t_sp *sp, t_mv_lostsoul *mvls)
{
	while (mvls->tmp_range <= mvls->move_range)
	{
		mvls->tmp_xx = sp->x_pos + (mvls->move_range + GRID) *
			cos(mvls->move_angle);
		mvls->tmp_yy = sp->y_pos + (mvls->move_range + GRID) *
			sin(mvls->move_angle);
		if (check_wall(p, mvls->tmp_xx, mvls->tmp_yy) != 0)
		{
			if (sp->time > ENEMY2_ATTACK_TIME)
				sp->time = 0;
			return (0);
		}
		mvls->tmp_x = sp->x_pos + cos(mvls->move_angle);
		if (check_wall(p, mvls->tmp_x, sp->y_pos) == 0)
			sp->x_pos = mvls->tmp_x;
		else if (sp->time > ENEMY2_ATTACK_TIME)
			sp->time = 0;
		mvls->tmp_y = sp->y_pos + sin(mvls->move_angle);
		if (check_wall(p, sp->x_pos, mvls->tmp_y) == 0)
			sp->y_pos = mvls->tmp_y;
		else if (sp->time > ENEMY2_ATTACK_TIME)
			sp->time = 0;
		mvls->tmp_range++;
	}
	return (0);
}

int		move_lost_soul(t_player *p, t_sp *sp)
{
	t_mv_lostsoul	mvls;

	mvls.move_angle = sp->move_angle;
	mvls.tmp_range = 0;
	if (sp->time >= ENEMY2_ATTACK_TIME)
		mvls.move_range = ENEMY2_MOVE_RANGE;
	else
	{
		mvls.move_range = 1;
		if (sp->z_pos < 1)
			sp->z_pos += 0.03;
	}
	sp->z_pos += sp->z_pos_add_num;
	if (sp->z_pos < 0)
		sp->z_pos = 0;
	if (sp->z_pos > 2)
		sp->z_pos = 2;
	mvls.tmp_xx = 0;
	mvls.tmp_yy = 0;
	move_lost_soul2(p, sp, &mvls);
	return (0);
}

void	lost_soul2(t_player *p, t_sp *enemy)
{
	if (enemy->range < GRID && enemy->health_point && (enemy->z_pos -
			p->ver_angle < 0.5 && enemy->z_pos - p->ver_angle > -0.5))
	{
		p->kill_count++;
		score_kill_count(p, enemy);
		enemy->health_point = 0;
		enemy->hit_time = 15;
		p->health->point -= 30;
	}
	if (enemy->hit_time > 30)
		enemy->alive = 0;
	get_tex_lostsoul(p, enemy);
	if (enemy->health_point == 0)
	{
		enemy->hit_time++;
		enemy->tex = find_tex_from_list(p, enemy->tex_num);
		return ;
	}
	move_lost_soul(p, enemy);
	enemy->tex = find_tex_from_list(p, enemy->tex_num);
}

int		lost_soul(t_player *p, t_sp *enemy)
{
	enemy->time++;
	p->lost_soul_num++;
	if (enemy->time > 300)
	{
		enemy->time = 0;
		enemy->z_pos_add_num = 0;
	}
	if (enemy->time == ENEMY2_ATTACK_TIME)
	{
		enemy->move_angle = enemy->angle + PI;
		enemy->z_pos_add_num = (p->ver_angle - enemy->z_pos) /
			(enemy->range / ENEMY2_MOVE_RANGE);
	}
	if (enemy->time < ENEMY2_ATTACK_TIME)
		enemy->move_angle = enemy->angle + PI;
	if (enemy->inside_aiming == 1 && p->key->shot == P_SHOT_HIT_TIME &&
			enemy->health_point && p->weapon->type != KEY_4)
	{
		p->kill_count++;
		p->score->hit++;
		score_kill_count(p, enemy);
		enemy->health_point = 0;
	}
	lost_soul2(p, enemy);
	return (0);
}
