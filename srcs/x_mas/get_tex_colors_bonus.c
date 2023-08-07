/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_colors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:42:53 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 15:42:54 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_color_bonus3(t_player *p, int dir,
		double wall_pos, t_sp *sp)
{
	int		color;

	if (dir == TEX_BOSS_1)
		color = get_tex_color3(p, sp->tex, wall_pos, 0);
	else if (dir == TEX_AMMO_1 || dir == TEX_AMMO_2)
		color = get_tex_color3(p, sp->tex, wall_pos, 0);
	else if (dir == TEX_STORMTROOPER_1)
		color = get_tex_color3(p, sp->tex, wall_pos, 0);
	else if (dir == TEX_STTP_BULLET)
		color = get_tex_color4(p, sp->tex, wall_pos, sp);
	else		
		color = -1;
	return (color);
}

int		get_tex_color_bonus2(t_player *p, int dir,
		double wall_pos, t_sp *sp)
{
	int		color;

	if (dir == ENEMY_1)
	{
		color = get_tex_color3(p, sp->tex, wall_pos, 0);
		color = get_darker_sprite(p, color, sp->range);
	}
	else if (dir == ENEMY_SP_POINT1_1)
	{
		color = get_tex_color3(p, sp->tex, wall_pos, 0);
	}
	else if (dir == MAP_DRUM)
	{
		color = get_tex_color3(p, sp->tex, wall_pos, 0);
		if (sp->tex_num == MAP_DRUM)
			color = get_darker_sprite(p, color, sp->range);
	}
	else if (dir == ENEMY_2)
		color = get_tex_color3(p, sp->tex, wall_pos, 0);
	else
		color = get_tex_color_bonus3(p, dir, wall_pos, sp);
	return (color);
}

int		get_tex_color_bonus(t_player *p, int dir,
		double wall_pos, t_sp *sp)
{
	int		color;
	double	tmp;
	int		i;

	color = -1;
	if (dir == ENEMY_BULLET)
	{
		if (sp->hit_time > 0)
			color = get_tex_color3(p, sp->tex, wall_pos, 0);
		else
			color = get_tex_color3(p, sp->tex, wall_pos, 0);
	}
	else if (p->is_door == -42)
	{
		tmp = p->rayc_x;
		i = p->map_check[p->dda_y / GRID][p->dda_x / GRID];
		i = (double)(i - 'D') / 40 * 100;
		p->rayc_x -= (i) * 0.01;
		color = get_tex_color2(p, p->move_wall->door, wall_pos, 0);
		p->rayc_x = tmp;
	}
	else
		color = get_tex_color_bonus2(p, dir, wall_pos, sp);
	return (color);
}

int		get_time_wall(t_player *p)
{
	int	time;

	time = p->flame_count % 5;
	if (time == 0)
		return (0);
	return (time);
}

int		get_moving_wall_tex(t_player *p, int dir, double wall_pos)
{
	int		color;
	int		time;
	int		rv;

	if (dir == 'N' || dir == 'E')
		rv = 0;
	else
		rv = 1;
	time = p->frame % 10;
	if (time <= 3)
		color = get_tex_color2(p, p->move_wall->tex_2, wall_pos, rv);
	else if (time <= 5)
		color = get_tex_color2(p, p->move_wall->tex_3, wall_pos, rv);
	else if (time <= 7)
		color = get_tex_color2(p, p->move_wall->tex_4, wall_pos, rv);
	else
		color = get_tex_color2(p, p->move_wall->tex_5, wall_pos, rv);
	return (color);
}
