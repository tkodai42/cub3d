/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_factor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:25:36 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 14:55:53 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_moving_wall_tex(t_player *p)
{
	p->move_wall->tex_2 = find_tex_from_list(p, TEX_WALL_2);
	p->move_wall->tex_3 = find_tex_from_list(p, TEX_WALL_3);
	p->move_wall->tex_4 = find_tex_from_list(p, TEX_WALL_4);
	p->move_wall->tex_5 = find_tex_from_list(p, TEX_WALL_5);
	p->move_wall->door = find_tex_from_list(p, MAP_DOOR);
}

void	ft_skybox_init(t_player *p)
{
	p->skybox->n = find_tex_from_list(p, TEX_SKYBOX_N);
	p->skybox->e = find_tex_from_list(p, TEX_SKYBOX_E);
	p->skybox->w = find_tex_from_list(p, TEX_SKYBOX_W);
	p->skybox->s = find_tex_from_list(p, TEX_SKYBOX_S);
	p->tex_sp2 = find_tex_from_list(p, TEX_RED_SP);
}

int		get_bonus_factor(t_player *p)
{
	ft_set_moving_wall_tex(p);
	ft_get_jump_factor(p);
	ft_cleate_enemy(p);
	ft_skybox_init(p);
	return (0);
}
