/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:38:26 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 14:11:50 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		sp_is_valid(t_player *p, t_sp *sp)
{
	t_put_sp ptsp;

	ptsp.fixed_ra = make_pa_base(p, sp->angle);
	ptsp.fixed_edge_l = make_pa_base(p, sp->edge_angle_l);
	ptsp.fixed_edge_r = make_pa_base(p, sp->edge_angle_r);
	ptsp.wrote_len = 0;
	if (FOV_LR * -1 <= ptsp.fixed_ra && ptsp.fixed_ra <= FOV_LR)
	{
		sp_is_valid2_1(p, sp, &ptsp);
	}
	else if (ptsp.fixed_ra > 0 && ptsp.fixed_edge_l <= (FOV_LR))
	{
		sp_is_valid2_2(p, sp, &ptsp);
	}
	else if (ptsp.fixed_ra <= 0 && ptsp.fixed_edge_r >= (FOV_LR * -1))
	{
		sp_is_valid2_3(p, sp, &ptsp);
	}
	return (0);
}

int		put_sp_to_map(t_player *p, t_sp *sp)
{
	double	x;
	double	y;
	t_line	line_pos;

	x = (p->x_axis - sp->x_pos);
	y = (p->y_axis - sp->y_pos);
	line_pos.x1 = p->x_axis;
	line_pos.y1 = p->y_axis;
	line_pos.x2 = sp->x_pos;
	line_pos.y2 = sp->y_pos;
	sp->range = sqrt((x * x) + (y * y));
	put_line(p, line_pos, sp);
	sp_get_fixed_r_h_w(p, sp);
	get_edge(p, line_pos, sp);
	sp_is_valid(p, sp);
	if (OMIT_LINE != 1)
		put_circle(p, sp->x_pos, sp->y_pos, sp->inside_aiming == 1 ?
				RED : WHITE);
	return (0);
}

int		put_sp_2(t_player *p)
{
	t_sp *tmp;

	if (p->sp)
		tmp = p->sp;
	else
		return (0);
	while (1)
	{
		tmp->inside_aiming = 0;
		put_sp_to_map(p, tmp);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (0);
}

int		put_sprite(t_player *p)
{
	sort_list_sp(p);
	put_sp_2(p);
	return (0);
}
