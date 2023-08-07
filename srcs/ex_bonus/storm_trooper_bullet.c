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

int		get_tex_color4(t_player *p, t_dir *dir, double wall_hight_pos, t_sp *sp)
{
	int	color;
	int x;
	int y;

	if (dir == NULL)
		return (-1);
	x = 0;
	y = 0;
	p->tmp = 0;
	if (0.49 < p->rayc_x && p->rayc_x < 0.51)
		;
	else if (p->rayc_x < sp->bullet_left || sp->bullet_right < p->rayc_x)
		return (-1);
	x = dir->xpm_width * p->rayc_x;
	y = dir->xpm_height * wall_hight_pos;
	color = *(unsigned int *)(dir->addr + y * dir->line_len + x * 4);
	return (color);
}

void	ft_bullet2_sttp(int *tex_num, double angle, t_sp *sp)
{
	double	width = fabs(sin(angle));
	
	*tex_num = TEX_STTP_BULLET;
	sp->bullet_left = (1.0 - width) / 2;
	sp->bullet_right = (width + 1) / 2;
}

int		ft_bullet_sttp(t_player *p, t_sp *sp)
{
	double	angle;
	int		tex_num;

	tex_num = 0;
	p->tmp = 0;
	angle = sp->move_angle - sp->angle;
	angle = make_validate_angle(angle);
	ft_bullet2_sttp(&tex_num, angle, sp);
	sp->tex_num = tex_num;
	sp_move(p, sp);
	sp->tex = find_tex_from_list(p, sp->tex_num);
	return (0);
}
