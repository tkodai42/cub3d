/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:31:58 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 17:51:46 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		can_reach_to_x(t_player *p, int y, int x)
{
	int tmp_x;

	tmp_x = 0;
	if (p->map_check[y] == NULL)
		return (0);
	while (1)
	{
		if (p->map_check[y][tmp_x] == '\0')
			return (0);
		if (tmp_x == x)
			return (1);
		tmp_x++;
	}
}

int		try_dfs(t_player *p, int y, int x, int *valid)
{
	if (!(*valid) || y == 0 || x == 0)
		return (*valid = 0);
	if (can_reach_to_x(p, y + 1, x) == 0)
		return (*valid = 0);
	if (ft_strchr("012X", p->map_check[y][x + 1]) == 0)
		return (*valid = 0);
	if (ft_strchr("012X", p->map_check[y][x - 1]) == 0)
		return (*valid = 0);
	if (ft_strchr("012X", p->map_check[y + 1][x]) == 0)
		return (*valid = 0);
	if (ft_strchr("012X", p->map_check[y - 1][x]) == 0)
		return (*valid = 0);
	p->map_check[y][x] = 'X';
	if (*valid && ft_strchr("02", p->map_check[y + 1][x]))
		try_dfs(p, y + 1, x, valid);
	if (*valid && ft_strchr("02", p->map_check[y - 1][x]))
		try_dfs(p, y - 1, x, valid);
	if (*valid && ft_strchr("02", p->map_check[y][x + 1]))
		try_dfs(p, y, x + 1, valid);
	if (*valid && ft_strchr("02", p->map_check[y][x - 1]))
		try_dfs(p, y, x - 1, valid);
	return (*valid);
}

int		check_map(t_player *p)
{
	int x;
	int y;
	int	map_valid;

	x = p->init_p_x;
	y = p->init_p_y;
	map_valid = 1;
	try_dfs(p, y, x, &map_valid);
	if (map_valid == 0)
		ft_error(p, 7);
	return (1);
}
