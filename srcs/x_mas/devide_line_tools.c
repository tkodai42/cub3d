/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devide_line_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:47:23 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/12 14:10:56 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pack_line_bonus(char **line, t_player *p, t_pack_line *pl)
{
	if (ft_strchr("D", (*line)[pl->i_line]))
		add_list(p, MAP_DOOR_POS, pl->i_line * GRID + GRID / 2,
				p->map_index * GRID + GRID / 2);
	if (ft_strchr("F", (*line)[pl->i_line]))
		add_list(p, MAP_DRUM, pl->i_line * GRID + GRID / 2, p->map_index *
				GRID + GRID / 2);
	if (ft_strchr("8", (*line)[pl->i_line]))
	{
		add_list(p, ENEMY_SP_POINT1_1, pl->i_line * GRID + GRID / 2,
				p->map_index * GRID + GRID / 2);
		(*line)[pl->i_line] = '0';
	}
}

int		pack_line(char **line, t_player *p, char *dest, t_pack_line *pl)
{
	while (*line && (*line)[pl->i_line])
	{
		if (p->is_bonus == 0 && ft_strchr("NEWS 012", (*line)[pl->i_line]) == 0)
			ft_error(p, 7);
		if (ft_strchr("NEWS", (*line)[pl->i_line]))
		{
			if (p->cf->player != 0)
				ft_error(p, 7);
			p->cf->player++;
			p->init_p_x = pl->i_line;
			p->init_p_y = p->map_index;
			p->init_p_angle = (*line)[pl->i_line];
			(*line)[pl->i_line] = '0';
		}
		dest[pl->i_dest++] = (*line)[pl->i_line++];
		if (ft_strchr("22", (*line)[pl->i_line]))
			add_list(p, MAP_SPRITE, pl->i_line * GRID + GRID / 2,
					p->map_index * GRID + GRID / 2);
		pack_line_bonus(line, p, pl);
	}
	return (0);
}

int		skip_space(char **line, t_player *p)
{
	char		*dest;
	t_pack_line	pl;

	pl.i_line = 0;
	pl.i_dest = 0;
	dest = malloc(sizeof(char) * ft_strlen(*line) + 1);
	if (dest == NULL)
		ft_error(p, 2);
	pack_line(line, p, dest, &pl);
	dest[pl.i_dest] = '\0';
	free(*line);
	*line = NULL;
	*line = dest;
	if (p->map_max_x < pl.i_dest)
		p->map_max_x = pl.i_dest;
	return (1);
}

int		ft_is_only_space_str(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '\0')
		return (1);
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
