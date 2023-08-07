/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:01:51 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/10 12:04:50 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_sp_z_pos(t_player *p, t_sp *sp)
{
	int tmp;

	if (sp->z_pos < p->ver_angle)
		sp->z_pos += 0.01;
	if (sp->z_pos > p->ver_angle)
		sp->z_pos -= 0.01;
	if (sp->z_pos < 0)
		sp->z_pos = 0;
	sp->time++;
	if (sp->time >= 100000)
		sp->time = 0;
	tmp = sp->time % 100;
	if (1)
		sp->moving = tmp * 0.01;
	if (tmp >= 25)
		sp->moving = (25 - (tmp - 25)) * 0.01;
	if (tmp >= 50)
		sp->moving = (tmp - 50) * 0.01;
	if (tmp >= 75)
		sp->moving = (25 - (tmp - 75)) * 0.01;
	if (sp->health_point <= 1)
		sp->moving = 0;
	return (0);
}

void	get_move_factor(t_player *p, t_sp *sp, t_sp_move *sp_m)
{
	sp_m->move_range = 1.0;
	sp_m->move_angle = 1.0;
	sp_m->move_dir = 1.0;
	if (sp->type == ENEMY_1)
		sp_m->move_range = ENEMY_MOVE_SPEED;
	if (sp->type == ENEMY_BULLET)
		sp_m->move_range = ENEMY_BULLET_SPEED;
	if (sp->type == TEX_STTP_BULLET)
		sp_m->move_range = ENEMY_BULLET_SPEED * 4;
	if (sp->type == ENEMY_1)
	{
		sp_m->move_angle = sp->angle;
		move_sp_z_pos(p, sp);
	}
	if (sp->type == ENEMY_BULLET || sp->type == TEX_STTP_BULLET)
		sp_m->move_angle = sp->move_angle;
	if (sp->type == ENEMY_1)
		sp_m->move_dir = -1;
	if (sp->type == ENEMY_BULLET || sp->type == TEX_STTP_BULLET)
		sp_m->move_dir = -1;
	sp->z_pos += sp->z_pos_add_num;
	sp_m->tmp_range = 0;
}

int		sp_move_bullet(t_player *p, t_sp *sp, double pos_x, double pos_y)
{
	int		cw_rv;

	cw_rv = check_wall(p, pos_x, pos_y);
	if (cw_rv == MAP_WALL)
	{
		sp->alive = 0;
		return (1);
	}
	else if (cw_rv == MAP_FLOOR_2F)
	{
		if (sp->z_pos > 0.5)
			return (0);
		else
			sp->alive = 0;
	}
	return (1);
}

void	sp_move2_bullet(t_player *p, t_sp *sp)
{
	if (sp->range < GRID / 2)
		if (sp->z_pos - p->ver_angle < 0.5)
			if (sp->z_pos - p->ver_angle > -0.5)
				if (p->health->point -= 10)
					sp->alive = 0;
	if (sp->z_pos <= -0.5)
		sp->alive = 0;
	if (++sp->time >= 4)
		sp->time = 0;
	if (sp->inside_aiming == 1 && p->key->shot == P_SHOT_HIT_TIME &&
			p->weapon->type != KEY_4 && sp->type != TEX_STTP_BULLET)
		if (sp->hit_time == 0)
			sp->hit_time = 1;
	if (sp->hit_time > 0)
	{
		if (++sp->hit_time < 5)
			sp->tex_num = TEX_ENEMY2_DEAD5;
		else if (sp->hit_time < 10)
			sp->tex_num = TEX_ENEMY2_DEAD6;
		else
		{
			sp->tex_num = TEX_ENEMY2_DEAD6;
			sp->alive = 0;
		}
	}
}

void	sp_move(t_player *p, t_sp *sp)
{
	t_sp_move sp_m;

	get_move_factor(p, sp, &sp_m);
	if (sp->type == ENEMY_1)
		if (sp->range < GRID * 2)
			return ;
	if (sp->type == ENEMY_BULLET || sp->type == TEX_STTP_BULLET)
		sp_move2_bullet(p, sp);
	while (++sp_m.tmp_range <= sp_m.move_range)
	{
		sp_m.tmp_x = sp->x_pos + cos(sp_m.move_angle) * sp_m.move_dir;
		if (check_wall(p, sp_m.tmp_x, sp->y_pos) == 0)
			sp->x_pos = sp_m.tmp_x;
		else if (sp->type == ENEMY_BULLET || sp->type == TEX_STTP_BULLET)
		{
			if (sp_move_bullet(p, sp, sp_m.tmp_x, sp->y_pos) == 0)
				sp->x_pos = sp_m.tmp_x;
		}
		sp_m.tmp_y = sp->y_pos + sin(sp_m.move_angle) * sp_m.move_dir;
		if (check_wall(p, sp->x_pos, sp_m.tmp_y) == 0)
			sp->y_pos = sp_m.tmp_y;
		else if (sp->type == ENEMY_BULLET || sp->type == TEX_STTP_BULLET)
			if (sp_move_bullet(p, sp, sp->x_pos, sp_m.tmp_y) == 0)
				sp->y_pos = sp_m.tmp_y;
	}
}
