/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:41:20 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 16:39:41 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	divide_line5(t_player *p, char *line)
{
	is_enough_element(p, line);
	p->cf->map = 1;
	if (p->map_index > 500)
		ft_error(p, 10);
	p->map_check[p->map_index] = ft_strdup(line);
	skip_space(&line, p);
	p->map[p->map_index] = line;
	p->map[p->map_index + 1] = NULL;
	p->map_check[p->map_index + 1] = NULL;
	p->map_max_y = ++p->map_index - 1;
}

void	divide_line4(t_player *p, char *line)
{
	if (ft_is_only_space_str(line))
	{
		if (p->cf->map == 1)
		{
			if (line[0] == '\0' && p->cf->map_is_end != 1)
			{
				free(line);
				p->cf->map_is_end = 1;
				return ;
			}
			free(line);
			ft_error(p, 7);
		}
		free(line);
	}
	else
		divide_line5(p, line);
}

void	divide_line3(t_player *p, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		p->cf->f++;
		is_over_element(p, line);
		get_background_colors(p, line, 'F');
		free(line);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		p->cf->c++;
		is_over_element(p, line);
		get_background_colors(p, line, 'C');
		free(line);
	}
	else
		divide_line4(p, line);
}

void	divide_line2(t_player *p, char *line)
{
	if (line[0] == 'W' && line[1] == 'E')
	{
		p->cf->we++;
		is_over_element(p, line);
		read_tex_map(p, p->we, line);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		p->cf->ea++;
		is_over_element(p, line);
		read_tex_map(p, p->ea, line);
	}
	else if (line[0] == 'S' && line[1] == ' ')
	{
		p->cf->sp++;
		is_over_element(p, line);
		read_tex_map(p, p->tex_sp, line);
	}
	else
		divide_line3(p, line);
}

int		divide_line(t_player *p, char *line)
{
	p->tmp_str = line;
	if (line[0] == 'R' && line[1] == ' ')
	{
		p->cf->r++;
		is_over_element(p, line);
		read_win_size(p, line);
		free(line);
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		p->cf->no++;
		is_over_element(p, line);
		read_tex_map(p, p->no, line);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		p->cf->so++;
		is_over_element(p, line);
		read_tex_map(p, p->so, line);
	}
	else
		divide_line2(p, line);
	return (0);
}
