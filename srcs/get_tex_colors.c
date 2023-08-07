/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:06:10 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 14:59:43 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_color2(t_player *p, t_dir *dir, double wall_hight_pos, int rev)
{
	int		color;
	int		x;
	int		y;
	double	tmp;

	p->tmp = 0;
	x = 0;
	y = 0;
	tmp = p->rayc_x;
	if (rev)
		tmp = 1.0 - tmp;
	x = (dir->xpm_width) * tmp;
	if (x < 0)
		x = 0;
	y = dir->xpm_height * wall_hight_pos;
	color = *(unsigned int *)(dir->addr + y * dir->line_len + x * 4);
	return (color);
}

int		get_tex_color3(t_player *p, t_dir *dir, double wall_hight_pos, int rev)
{
	int	color;
	int x;
	int y;

	if (dir == NULL)
		return (-1);
	x = 0;
	y = 0;
	p->tmp = 0;
	x = dir->xpm_width * p->rayc_x;
	rev = 1;
	y = dir->xpm_height * wall_hight_pos;
	color = *(unsigned int *)(dir->addr + y * dir->line_len + x * 4);
	return (color);
}

int		get_tex_wall_color(t_player *p, int dir, double wall_hight_pos)
{
	int color;

	color = -1;
	if (dir == 'N')
		color = get_tex_color2(p, p->no, wall_hight_pos, 0);
	else if (dir == 'S')
		color = get_tex_color2(p, p->so, wall_hight_pos, 1);
	else if (dir == 'W')
		color = get_tex_color2(p, p->we, wall_hight_pos, 1);
	else if (dir == 'E')
		color = get_tex_color2(p, p->ea, wall_hight_pos, 0);
	return (color);
}

int		get_tex_color(t_player *p, int dir, double wall_hight_pos, t_sp *sp)
{
	int	color;

	color = -1;
	if (p->is_door == -42)
		color = get_tex_color_bonus(p, dir, wall_hight_pos, sp);
	else if ((dir == 'N' || dir == 'S' || dir == 'W' || dir == 'E') &&
			p->frame % 10 > 1)
	{
		color = get_moving_wall_tex(p, dir, wall_hight_pos);
	}
	else if (dir == 'N' || dir == 'S' || dir == 'W' || dir == 'E')
		color = get_tex_wall_color(p, dir, wall_hight_pos);
	else if (dir == MAP_SPRITE)
	{
		color = get_tex_color3(p, p->tex_sp, wall_hight_pos, 0);
		if (p->is_bonus)
		{
			if (p->boss_is_exists == 1)
				color = get_tex_color3(p, p->tex_sp2, wall_hight_pos, 0);
			color = get_darker_sprite(p, color, sp->range);
		}
	}
	else if (p->is_bonus)
		color = get_tex_color_bonus(p, dir, wall_hight_pos, sp);
	return (color);
}
