/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:00:16 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/09 14:21:21 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_bullet_init2(t_player *p, t_sp *sp, t_sp *bullet)
{
	bullet->move_angle = sp->angle;
	if (bullet->type == TEX_STTP_BULLET)
		bullet->move_angle = sp->move_angle + PI;
	bullet->angle = sp->angle;
	bullet->range = sp->range;
	bullet->x_pos = sp->x_pos;
	bullet->y_pos = sp->y_pos;
	bullet->z_pos = sp->z_pos;
	bullet->tex_num = TEX_BOSS_A;
	bullet->z_pos_add_num = 0;
	if (bullet->type != TEX_STTP_BULLET)
	bullet->z_pos_add_num = (p->ver_angle - bullet->z_pos) /
		(bullet->range / ENEMY_BULLET_SPEED);
	bullet->bullet_left = 0;
	bullet->bullet_right = 1;
}

int		add_list_init_bullet(t_player *p, t_sp *sp, t_sp *bullet)
{
	bullet->next = NULL;
	bullet->valid = 1;
	bullet->alive = 1;
	bullet->hit_time = 0;
	bullet->tex = NULL;
	bullet->angle = 0;
	if (bullet->type == ENEMY_BULLET || bullet->type == TEX_STTP_BULLET)
	{
		add_bullet_init2(p, sp, bullet);
	}
	if (sp->type == TEX_BOSS_1)
	{
		bullet->move_angle = sp->move_angle + PI;
		bullet->range = sp->range;
		bullet->x_pos = sp->x_pos;
		bullet->y_pos = sp->y_pos;
		bullet->z_pos = 0.5;
		bullet->z_pos_add_num = (p->ver_angle - bullet->z_pos) /
			(bullet->range / ENEMY_BULLET_SPEED);
	}
	return (0);
}

int		add_list_bullet(t_player *p, int bullet_type, t_sp *sp)
{
	t_sp	*new_sp;

	new_sp = malloc(sizeof(t_sp));
	if (new_sp == NULL)
		ft_error(p, 6);
	new_sp->type = bullet_type;
	add_list_init_bullet(p, sp, new_sp);
	if (p->sp == NULL)
	{
		p->sp = new_sp;
	}
	else
	{
		add_last_list(p->sp, new_sp);
	}
	return (0);
}

void	ft_bullet2(int *tex_num, double angle, t_sp *sp)
{
	if (angle < PI / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_A1 : TEX_BULLET_A2;
	else if (angle < PI * 3 / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_B1 : TEX_BULLET_B2;
	else if (angle < PI * 5 / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_C1 : TEX_BULLET_C2;
	else if (angle < PI * 7 / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_D1 : TEX_BULLET_D2;
	else if (angle < PI * 9 / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_E1 : TEX_BULLET_E2;
	else if (angle < PI * 11 / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_F1 : TEX_BULLET_F2;
	else if (angle < PI * 13 / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_G1 : TEX_BULLET_G2;
	else if (angle < PI * 15 / 8)
		*tex_num = sp->time < 2 ? TEX_BULLET_H1 : TEX_BULLET_H2;
	else
		*tex_num = sp->time < 2 ? TEX_BULLET_A1 : TEX_BULLET_A2;
}

int		ft_bullet(t_player *p, t_sp *sp)
{
	double	angle;
	int		tex_num;

	tex_num = 0;
	p->tmp = 0;
	angle = sp->move_angle - sp->angle;
	angle = make_validate_angle(angle);
	ft_bullet2(&tex_num, angle, sp);
	sp->tex_num = tex_num;
	sp_move(p, sp);
	sp->tex = find_tex_from_list(p, sp->tex_num);
	return (0);
}
