/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_and_shot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:05:20 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 11:13:40 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cut_function_aiminig_for_norm(t_player *p, t_sp *enemy)
{
	p->kill_count++;
	p->killed_flag++;
	score_kill_count(p, enemy);
	enemy->moving = 0;
	enemy->time = 1;
	enemy->hit_time = 0;
}

void	ft_enemy_move_and_shot_aiming(t_player *p, t_sp *enemy)
{
	if (--enemy->health_point > 1 && p->weapon->type == KEY_3)
		enemy->health_point = 1;
	if (enemy->health_point)
		p->score->hit++;
	if (enemy->health_point == 1)
	{
		cut_function_aiminig_for_norm(p, enemy);
	}
	if (enemy->health_point <= 0 && enemy->time >= 50)
	{
		enemy->alive = 0;
		if (p->frame % 2 == 0)
			add_list(p, TEX_AMMO_2, enemy->x_pos, enemy->y_pos);
		else
			add_list(p, TEX_AMMO_1, enemy->x_pos, enemy->y_pos);
	}
	else if (enemy->health_point > 1)
	{
		ft_knock_back(p, enemy);
		enemy->hit_time = 30;
	}
}

void	ft_enemy_m_a_s_enemy1(t_player *p, t_sp *enemy, t_dir *tmp)
{
	if (enemy->health_point <= 1)
	{
		if (enemy->time < 5)
			tmp = find_tex_from_list(p, TEX_ENEMY_1_DEAD_1);
		else if (enemy->time < 10)
			tmp = find_tex_from_list(p, TEX_ENEMY_1_DEAD_2);
		else if (enemy->time < 15)
			tmp = find_tex_from_list(p, TEX_ENEMY_1_DEAD_3);
		else if (enemy->time < 20)
			tmp = find_tex_from_list(p, TEX_ENEMY_1_DEAD_4);
		else
			tmp = find_tex_from_list(p, ENEMY_1_DEAD_1);
	}
	else if (enemy->hit_time > 0)
		tmp = find_tex_from_list(p, TEX_ENEMY_1_DAMEGE_1);
	else if (enemy->time % 30 <= 5)
		tmp = find_tex_from_list(p, ENEMY_1);
	else if (enemy->time % 30 <= 15)
		tmp = find_tex_from_list(p, ENEMY_1_2);
	else if (enemy->time % 30 <= 25)
		tmp = find_tex_from_list(p, ENEMY_1_3);
	else
		tmp = find_tex_from_list(p, ENEMY_1);
	enemy->tex = tmp;
}

void	cut_function_emas_for_norm(t_sp *enemy)
{
	if (enemy->time >= 1 && enemy->time < 50)
		enemy->time++;
	if (enemy->health_point <= 1)
	{
		if (enemy->z_pos > 0)
		{
			if (enemy->time > 5)
				enemy->time = 5;
			enemy->z_pos -= 0.02;
		}
	}
}

int		ft_enemy_move_and_shot(t_player *p, t_sp *enemy)
{
	t_dir	*tmp;

	tmp = NULL;
	cut_function_emas_for_norm(enemy);
	if (enemy->hit_time > 0)
		enemy->hit_time--;
	if (enemy->time % 30 == 15 && enemy->health_point > 1 &&
		enemy->hit_time == 0)
		add_list_bullet(p, ENEMY_BULLET, enemy);
	if (enemy->inside_aiming == 1 && p->key->shot == P_SHOT_HIT_TIME)
	{
		if (p->weapon->type == KEY_4 && enemy->range > GRID * 2)
			return (0);
		ft_enemy_move_and_shot_aiming(p, enemy);
	}
	else if (enemy->health_point > 1 && enemy->hit_time < 1)
		sp_move(p, enemy);
	if (enemy->type == ENEMY_1)
		ft_enemy_m_a_s_enemy1(p, enemy, tmp);
	return (0);
}
