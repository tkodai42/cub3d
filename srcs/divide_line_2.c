/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_line_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:36:46 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 16:37:27 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_enough_element(t_player *p, char *line)
{
	int		flag;

	flag = 0;
	if (p->cf->r != 1)
		flag = 1;
	if (p->cf->no != 1)
		flag = 1;
	if (p->cf->so != 1)
		flag = 1;
	if (p->cf->we != 1)
		flag = 1;
	if (p->cf->ea != 1)
		flag = 1;
	if (p->cf->sp != 1)
		flag = 1;
	if (p->cf->f != 1)
		flag = 1;
	if (p->cf->c != 1)
		flag = 1;
	if (flag == 1)
	{
		free(line);
		ft_error(p, 8);
	}
	return (0);
}

int		is_over_element(t_player *p, char *line)
{
	int		flag;

	flag = 0;
	if (p->cf->r > 1)
		flag = 1;
	if (p->cf->no > 1)
		flag = 1;
	if (p->cf->so > 1)
		flag = 1;
	if (p->cf->we > 1)
		flag = 1;
	if (p->cf->ea > 1)
		flag = 1;
	if (p->cf->sp > 1)
		flag = 1;
	if (p->cf->f > 1)
		flag = 1;
	if (p->cf->c > 1)
		flag = 1;
	if (flag == 1)
	{
		free(line);
		ft_error(p, 8);
	}
	return (0);
}
