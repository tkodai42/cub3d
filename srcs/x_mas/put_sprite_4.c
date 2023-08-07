/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:56:47 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 14:15:59 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_edge(t_player *p, t_line line_pos, t_sp *sp)
{
	double boss;

	boss = 1;
	if (sp->type == TEX_BOSS_1)
		boss = 2;
	sp->edge_xl = sp->x_pos + cos(sp->angle - PI / 2) * (GRID / 2) * boss;
	sp->edge_yl = sp->y_pos + sin(sp->angle - PI / 2) * (GRID / 2) * boss;
	sp->edge_xr = sp->x_pos + cos(sp->angle + PI / 2) * (GRID / 2) * boss;
	sp->edge_yr = sp->y_pos + sin(sp->angle + PI / 2) * (GRID / 2) * boss;
	line_pos.x2 = sp->edge_xl;
	line_pos.y2 = sp->edge_yl;
	sp->edge_angle_l = put_line(p, line_pos, NULL);
	line_pos.x2 = sp->edge_xr;
	line_pos.y2 = sp->edge_yr;
	sp->edge_angle_r = put_line(p, line_pos, NULL);
	while (sp->edge_angle_r < sp->edge_angle_l)
	{
		sp->edge_angle_r += PI * 2;
	}
	sp->angle_width = sp->edge_angle_r - sp->edge_angle_l;
	sp->width = (double)p->win_width * sp->angle_width / (PI / (180 / FOV));
	sp->height = sp->width;
	return (0);
}

int		sp_get_fixed_r_h_w(t_player *p, t_sp *sp)
{
	double ca;

	ca = p->angle - sp->angle;
	sp->fixed_range = sp->range * cos(ca);
	return (0);
}

void	put_sp_tex2_2(t_player *p, t_sp *sp, t_putsptex *pt_sp_tex)
{
	{
		p->rayc_x = (double)pt_sp_tex->x_pos_img / sp->width;
		pt_sp_tex->color = get_tex_color(p, sp->type, pt_sp_tex->tex_y_pos /
				pt_sp_tex->height, sp);
		if (pt_sp_tex->color > 0 &&
				(p->buf_draw_valid_height[pt_sp_tex->x_pos_win] >
				pt_sp_tex->y_pos_win ||
				p->buf_draw_vh_head_pos[pt_sp_tex->x_pos_win] > sp->range ||
				sp->z_pos > 0.7))
		{
			pt_sp_tex->painted = 1;
			my_mlx_pixel_put(p, pt_sp_tex->x_pos_win, pt_sp_tex->y_pos_win,
					pt_sp_tex->color);
		}
	}
}

int		put_sp_tex2(t_player *p, t_sp *sp, t_putsptex *pt_sp_tex)
{
	while (pt_sp_tex->tex_y_pos < pt_sp_tex->height)
	{
		if (pt_sp_tex->y_pos_win < 0)
		{
			pt_sp_tex->tex_y_pos = pt_sp_tex->y_pos_win * -1;
			pt_sp_tex->y_pos_win = 0;
		}
		if (pt_sp_tex->y_pos_win < p->win_height && pt_sp_tex->y_pos_win >= 0)
			put_sp_tex2_2(p, sp, pt_sp_tex);
		else
			return (pt_sp_tex->painted);
		pt_sp_tex->y_pos_win++;
		pt_sp_tex->tex_y_pos++;
	}
	return (pt_sp_tex->painted);
}

int		put_sp_tex(t_player *p, t_sp *sp, int x_pos_win, int x_pos_img)
{
	t_putsptex	pt_sp_tex;

	pt_sp_tex.x_pos_win = x_pos_win;
	pt_sp_tex.x_pos_img = x_pos_img;
	pt_sp_tex.boss = 1;
	if (sp->type == TEX_BOSS_1)
		pt_sp_tex.boss = 2;
	pt_sp_tex.moving = 0;
	if (sp->type == ENEMY_1)
		pt_sp_tex.moving = sp->moving + sp->z_pos;
	if (sp->type == ENEMY_BULLET || sp->type == ENEMY_2 || sp->type == TEX_STTP_BULLET)
		pt_sp_tex.moving = sp->z_pos;
	pt_sp_tex.fish_eye_height = p->win_width * (GRID) / sp->fixed_range;
	pt_sp_tex.height = p->win_width * (GRID * pt_sp_tex.boss) / sp->fixed_range;
	pt_sp_tex.sp_floor = p->win_height / 2 + pt_sp_tex.height / 2;
	pt_sp_tex.sp_loof = pt_sp_tex.sp_floor - pt_sp_tex.height;
	pt_sp_tex.y_pos_win = pt_sp_tex.sp_loof + pt_sp_tex.fish_eye_height *
		((p->ver_angle + p->walk->z_pos - (sp->type == TEX_BOSS_1 ? 0.5 : 0)) -
		1 * (pt_sp_tex.moving));
	pt_sp_tex.tex_y_pos = 0;
	pt_sp_tex.painted = 0;
	put_sp_tex2(p, sp, &pt_sp_tex);
	return (pt_sp_tex.painted);
}
