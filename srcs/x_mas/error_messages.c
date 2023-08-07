/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:06:39 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/16 11:51:09 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error2(t_player *p, int error_type)
{
	p->tmp = 0;
	if (error_type == 9)
		write(1, "Error\nConfiguration file / color is invalid\n", 44);
	else if (error_type == 10)
		write(1, "Error\nmap is too big\n", 21);
	else if (error_type == 11)
	{
		write(1, "\n", 1);
		if (p->score->cyber_demon <= 0)
			write(1, "\n[GAME OVER]\n", 14);
		display_score(p);
	}
	else
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		write(1, "\npressed [x]\n\n", 14);
		display_score(p);
	}
}

int		ft_error(t_player *p, int error_type)
{
	p->tmp = 0;
	if (error_type == ERROR_ESC)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		write(1, "\npressed esc\n\n", 14);
		display_score(p);
	}
	else if (error_type == ERROR_MALLOC)
		write(1, "Error\nmalloc error\n", 18);
	else if (error_type == ERROR_PAS)
		write(1, "Error\npath is invalid\n", 22);
	else if (error_type == ERROR_ARGS)
		write(1, "Error\nargs is invalid\n", 22);
	else if (error_type == ERROR_FD)
		write(1, "Error\nfd is invalid\n", 20);
	else if (error_type == 6)
		write(1, "Error\nfailed create sp\n", 20);
	else if (error_type == 7)
		write(1, "Error\nmap is invalid / failed dfs\n", 34);
	else if (error_type == 8)
		write(1, "Error\nConfiguration file is invalid\n", 36);
	else
		ft_error2(p, error_type);
	exit(0);
	return (0);
}
