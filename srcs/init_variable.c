/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:40:02 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 14:01:42 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_variable5(t_player *p)
{
	p->buf_range = malloc(sizeof(double) * (p->win_width + 2));
	if (p->buf_range == NULL)
		ft_error(p, 2);
	p->buf_angle = malloc(sizeof(double) * (p->win_width + 2));
	if (p->buf_angle == NULL)
		ft_error(p, 2);
	p->buf_draw_floor = malloc(sizeof(double) * (p->win_width + 2));
	if (p->buf_draw_floor == NULL)
		ft_error(p, 2);
	p->buf_draw_vh_head_pos = malloc(sizeof(double) * (p->win_width + 2));
	if (p->buf_draw_vh_head_pos == NULL)
		ft_error(p, 2);
	p->buf_draw_valid_height = malloc(sizeof(double) * (p->win_width + 2));
	if (p->buf_draw_valid_height == NULL)
		ft_error(p, 2);
	p->buf_draw_f_range = malloc(sizeof(double) * (p->win_width + 2));
	if (p->buf_draw_f_range == NULL)
		ft_error(p, 2);
}

void	init_variable4(t_player *p)
{
	p->win_width = p->win_x_size;
	p->win_height = p->win_y_size;
	p->move_range = MOVE_SPEED;
	p->map_index = 0;
	init_variable5(p);
	p->x_axis = (p->init_p_x * GRID + GRID / 2);
	p->y_axis = (p->init_p_y * GRID + GRID / 2);
	if (p->init_p_angle == 'N')
		p->angle = PI * 3 / 2;
	if (p->init_p_angle == 'S')
		p->angle = PI / 2;
	if (p->init_p_angle == 'W')
		p->angle = PI;
}

void	init_variable3(t_player *p)
{
	p->walk->time = 0;
	p->walk->z_pos = 0;
	p->walk->angle = 0;
	p->walk->gun_x_pos = 0;
	p->weapon->time = 0;
	p->weapon->type = KEY_1;
	p->weapon->ammo_1 = 25;
	p->weapon->ammo_2 = 0;
	p->weapon->ammo_3 = 0;
	p->score->cacodemon = 0;
	p->score->lost_soul = 0;
	p->score->cyber_demon = 0;
	p->score->hg = 0;
	p->score->mg = 0;
	p->score->sg = 0;
	p->score->melee = 0;
	p->score->hit = 0;
	p->dda_x = 0;
	p->dda_y = 0;
	p->is_door = 0;
	p->is_door_pos = 0;
	init_variable4(p);
}

void	init_variable2(t_player *p)
{
	p->frame = 0;
	p->flame_count = 0;
	p->frame_u_d_pos = 0;
	p->tex_sp_line = NULL;
	p->kill_count = 0;
	p->killed_flag = 1;
	p->kill_frame = 0;
	p->boss_spawn = 0;
	p->boss_is_exists = 0;
	p->no_more_lost_soul = 0;
	p->lost_soul_num = 0;
	p->health->point = 100;
	p->health->last_point = 100;
	p->health->time = 0;
	p->is_dylib = IS_DYLIB;
	p->win_buf_index = 0;
	p->rayc_dir = 0;
	p->rayc_x = 0;
	p->rayc_y = 0;
	p->rayc_win_x = 0;
	p->rayc_win_y = 0;
	p->rayc_range = 0;
	p->rayc_angle = 0;
	init_variable3(p);
}

void	init_variable(t_player *p)
{
	p->key->w = 0;
	p->key->s = 0;
	p->key->a = 0;
	p->key->d = 0;
	p->key->right = 0;
	p->key->left = 0;
	p->key->up = 0;
	p->key->down = 0;
	p->key->f = 0;
	p->key->sp = 0;
	p->key->u = 0;
	p->key->j = 0;
	p->key->m = 0;
	p->key->e = 0;
	p->key->shift = 0;
	p->key->jump = 0;
	p->key->shot = 0;
	p->key->map_on_off = 1;
	p->ver_angle = 0;
	p->jump_pos = 0;
	init_variable2(p);
}
