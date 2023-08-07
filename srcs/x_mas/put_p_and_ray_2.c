/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_and_ray_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:04:12 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 13:22:59 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		validate_angle(t_player *p)
{
	while (p->angle < 0)
	{
		p->angle += PI * 2;
	}
	if (p->angle > PI * 2)
		p->angle = fmod(p->angle, (PI * 2));
	return (0);
}

int		within_screen_range(t_player *p, int win_x, int win_y)
{
	if (win_x < 0 || win_y < 0)
		return (0);
	if (win_x >= p->win_width * p->mini_grid_ratio ||
			win_y >= p->win_height * p->mini_grid_ratio)
		return (0);
	return (1);
}
