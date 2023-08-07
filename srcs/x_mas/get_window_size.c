/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:28:55 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/16 11:22:48 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ws(t_win_size *ws)
{
	ws->too_big = 0;
	ws->index = 0;
	ws->size_x = 0;
	ws->size_y = 0;
	ws->element_1 = 0;
	ws->element_2 = 0;
}

void	read_win_size3(t_player *p, char *line, t_win_size *ws)
{
	p->win_x_size = ws->size_x;
	p->win_y_size = ws->size_y;
	mlx_get_screen_size(p->mlx_ptr, &ws->size_x, &ws->size_y);
	{
		if (p->win_x_size > ws->size_x)
			p->win_x_size = ws->size_x;
		if (p->win_y_size > ws->size_y)
			p->win_y_size = ws->size_y;
	}
	if (ws->element_1 != 1 || ws->element_2 != 1 ||
			p->win_x_size == 0 || p->win_y_size == 0 ||
			line[ws->index] != '\0')
		ft_error(p, 8);
	if (ws->element_1 == 1 && ws->element_2 == 1 &&
			(p->win_y_size < 200 || p->win_x_size < 200))
	{
		if (p->win_x_size < 200 && p->is_bonus)
			p->win_x_size = 200;
		if (p->win_y_size < 200 && p->is_bonus)
			p->win_y_size = 200;
	}
}

void	read_win_size2(t_player *p, char *line, t_win_size *ws)
{
	while (ft_strchr("  ", line[ws->index]))
		ws->index++;
	while (ft_strchr("1234567890", line[ws->index]))
	{
		ws->size_y = ws->size_y * 10 + (line[ws->index] - '0');
		ws->index++;
		if (ws->size_y > 1000000)
		{
			ws->too_big = 1;
			ws->size_y = 0;
		}
		ws->element_2 = 1;
	}
	if (ws->too_big)
		ws->size_y = 1000000;
	read_win_size3(p, line, ws);
}

int		read_win_size(t_player *p, char *line)
{
	t_win_size	ws;

	init_ws(&ws);
	if (ft_strchr("R", line[ws.index]))
		ws.index++;
	while (ft_strchr(" ", line[ws.index]))
		ws.index++;
	while (ft_strchr("1234567890", line[ws.index]))
	{
		ws.size_x = ws.size_x * 10 + (line[ws.index] - '0');
		ws.index++;
		if (ws.size_x > 1000000)
		{
			ws.too_big = 1;
			ws.size_x = 0;
		}
		ws.element_1 = 1;
	}
	if (ws.too_big)
		ws.size_x = 1000000;
	ws.too_big = 0;
	read_win_size2(p, line, &ws);
	return (0);
}
