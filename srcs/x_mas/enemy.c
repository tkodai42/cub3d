/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:54:26 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 11:13:44 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cleate_enemy(t_player *p)
{
	p->tmp = 1;
	add_list(p, TEX_STORMTROOPER_1, 200, 200);
	return (0);
}

int		ft_knock_back(t_player *p, t_sp *enemy)
{
	double	knocked_x;
	double	knocked_y;
	double	move_angle;
	int		moved_range;

	moved_range = GRID / 10;
	if (p->weapon->type == KEY_4)
		moved_range = GRID * 2;
	if (enemy)
	{
		knocked_x = enemy->x_pos;
		knocked_y = enemy->y_pos;
		move_angle = enemy->angle;
		while (moved_range-- && check_wall(p, knocked_x, knocked_y) == 0)
		{
			enemy->x_pos = knocked_x;
			enemy->y_pos = knocked_y;
			knocked_x = cos(move_angle) + enemy->x_pos;
			knocked_y = sin(move_angle) + enemy->y_pos;
		}
	}
	return (0);
}

int		ft_ammo(t_player *p, t_sp *sp)
{
	if (sp->range < GRID)
	{
		if (sp->type == TEX_AMMO_1)
		{
			p->weapon->ammo_1 += 20;
			p->weapon->ammo_2 += 20;
			sp->alive = 0;
		}
		if (sp->type == TEX_AMMO_2)
		{
			p->weapon->ammo_3 += 5;
			sp->alive = 0;
		}
	}
	if (sp->type == TEX_AMMO_1)
		sp->tex = find_tex_from_list(p, TEX_AMMO_1);
	if (sp->type == TEX_AMMO_2)
		sp->tex = find_tex_from_list(p, TEX_AMMO_2);
	return (0);
}

void	ft_enemy_move2(t_player *p, t_sp *tmp_sp)
{
	if (tmp_sp->type == ENEMY_1)
		ft_enemy_move_and_shot(p, tmp_sp);
	else if (tmp_sp->type == ENEMY_BULLET)
		ft_bullet(p, tmp_sp);
	else if (tmp_sp->type == MAP_DOOR_POS)
		door_open_close(p, tmp_sp);
	else if (tmp_sp->type == MAP_DRUM)
		drum_explosion(p, tmp_sp);
	else if (tmp_sp->type == ENEMY_2)
		lost_soul(p, tmp_sp);
	else if (tmp_sp->type == TEX_BOSS_1)
		big_boss(p, tmp_sp);
	else if (tmp_sp->type == TEX_AMMO_1 || tmp_sp->type == TEX_AMMO_2)
		ft_ammo(p, tmp_sp);
	else if (tmp_sp->type == TEX_STORMTROOPER_1)
		ft_stormtrooper(p, tmp_sp);
	else if (tmp_sp->type == TEX_STTP_BULLET)
		ft_bullet_sttp(p, tmp_sp);
}

int		ft_enemy_move(t_player *p)
{
	t_sp	*tmp_sp;
	int		boss;

	boss = 1;
	tmp_sp = p->sp;
	p->boss_is_exists = 0;
	p->lost_soul_num = 0;
	while (tmp_sp != NULL)
	{
		if (tmp_sp->type == ENEMY_SP_POINT1_1)
		{
			ft_spawn_point(p, tmp_sp);
			if (tmp_sp->health_point > 0)
				boss = 0;
		}
		else
			ft_enemy_move2(p, tmp_sp);
		tmp_sp = tmp_sp->next;
	}
	if (boss && p->boss_spawn == 0)
		p->boss_spawn = 1;
	return (0);
}
