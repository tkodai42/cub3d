/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:02:38 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/10 12:03:26 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sp_is_valid2_1(t_player *p, t_sp *sp, t_put_sp *ptsp)
{
	ptsp->put_pos_x = p->win_width * ((ptsp->fixed_ra + FOV_LR) / FOV_BASED_PI);
	while (ptsp->put_pos_x < p->win_width && ptsp->wrote_len < sp->width / 2)
	{
		if (sp->range < p->buf_range[ptsp->put_pos_x])
			if (put_sp_tex(p, sp, ptsp->put_pos_x, sp->width / 2 +
						ptsp->wrote_len) == 1)
				if (ptsp->put_pos_x == p->win_width / 2)
					sp->inside_aiming = 1;
		ptsp->put_pos_x++;
		ptsp->wrote_len++;
	}
	ptsp->put_pos_x = p->win_width * ((ptsp->fixed_ra + FOV_LR) / FOV_BASED_PI);
	ptsp->wrote_len = 0;
	while (ptsp->put_pos_x >= 0 && ptsp->wrote_len < sp->width / 2)
	{
		if (sp->range < p->buf_range[ptsp->put_pos_x])
			if (put_sp_tex(p, sp, ptsp->put_pos_x, sp->width / 2 -
						ptsp->wrote_len) == 1)
				if (ptsp->put_pos_x == p->win_width / 2)
					sp->inside_aiming = 1;
		ptsp->put_pos_x--;
		ptsp->wrote_len++;
	}
}

void	sp_is_valid2_2(t_player *p, t_sp *sp, t_put_sp *ptsp)
{
	ptsp->put_pos_x = p->win_width * (ptsp->fixed_edge_l + (FOV_LR)) /
		(PI / 3) - 1;
	while (1)
	{
		if (ptsp->wrote_len > sp->width)
			return ;
		if (ptsp->put_pos_x >= p->win_width)
			return ;
		if (ptsp->put_pos_x >= 0)
		{
			if (sp->range < p->buf_range[ptsp->put_pos_x])
			{
				if (put_sp_tex(p, sp, ptsp->put_pos_x, ptsp->wrote_len) == 1)
					if (ptsp->put_pos_x == p->win_width / 2)
						sp->inside_aiming = 1;
			}
		}
		else
			ptsp->put_pos_x = 0 - 1;
		ptsp->put_pos_x++;
		ptsp->wrote_len++;
	}
}

void	sp_is_valid2_3(t_player *p, t_sp *sp, t_put_sp *ptsp)
{
	ptsp->put_pos_x = p->win_width * (ptsp->fixed_edge_r + (FOV_LR)) /
		(PI / 3) - 1;
	while (1)
	{
		if (ptsp->wrote_len > sp->width)
			return ;
		if (ptsp->put_pos_x < 0)
			return ;
		if (ptsp->put_pos_x < p->win_width)
		{
			if (sp->range < p->buf_range[ptsp->put_pos_x])
			{
				put_sp_tex(p, sp, ptsp->put_pos_x, sp->width - ptsp->wrote_len);
			}
		}
		else
			ptsp->put_pos_x = p->win_width + 1;
		ptsp->put_pos_x--;
		ptsp->wrote_len++;
	}
}
