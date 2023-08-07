/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:07:39 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 14:02:17 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_check_file(t_player *p)
{
	p->cf->r = 0;
	p->cf->no = 0;
	p->cf->so = 0;
	p->cf->we = 0;
	p->cf->ea = 0;
	p->cf->sp = 0;
	p->cf->f = 0;
	p->cf->c = 0;
	p->cf->map = 0;
	p->cf->map_is_end = 0;
	p->cf->player = 0;
}

void	read_map2(t_player *p)
{
	char			*line;
	int				rv;
	int				fd;

	fd = open(p->file_name, O_RDWR);
	if (fd < 0)
		ft_error(p, ERROR_FD);
	while ((rv = gnl(fd, &line)) > 0)
	{
		divide_line(p, line);
		if (ft_strlen(line) > 500)
			ft_error(p, 10);
	}
	divide_line(p, line);
	if (ft_strlen(line) > 500)
		ft_error(p, 10);
	if (p->cf->player != 1)
		ft_error(p, 8);
}

int		read_map(t_player *p)
{
	t_check_file	check_file;

	p->cf = &check_file;
	init_check_file(p);
	p->file_name = p->pass_ptr;
	p->map = malloc(sizeof(char *) * (600 + 1));
	if (p->map == NULL)
		ft_error(p, 2);
	p->map_check = malloc(sizeof(char *) * (600 + 1));
	if (p->map == NULL)
		ft_error(p, 2);
	p->map_index = 0;
	read_map2(p);
	return (0);
}
