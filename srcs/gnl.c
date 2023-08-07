/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:24:59 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 13:51:25 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		has_new_line(char *tmp, int *index)
{
	*index = 0;
	while (tmp && tmp[*index])
	{
		if (tmp[*index] == '\n')
		{
			tmp[*index] = '\0';
			return (1);
		}
		(*index)++;
	}
	return (0);
}

int		gnl2(int fd, char **line, char **stock, int index)
{
	int		rt;
	char	buf[1001];
	char	*tmp;

	while ((rt = read(fd, buf, 1000)) > 0)
	{
		buf[rt] = '\0';
		tmp = ft_strjoin(*stock, buf);
		free(*stock);
		*stock = NULL;
		if (has_new_line(tmp, &index))
		{
			*line = ft_strdup(tmp);
			*stock = ft_strdup(&tmp[index + 1]);
			free(tmp);
			return (1);
		}
		*stock = tmp;
	}
	*line = ft_strdup(*stock);
	return (0);
}

int		gnl(int fd, char **line)
{
	int			index;
	char		*tmp;
	static char *stock;

	if (fd < 0)
		return (-1);
	if (!stock)
		stock = ft_strdup("");
	if (has_new_line(stock, &index))
	{
		*line = ft_strdup(stock);
		tmp = ft_strdup(&stock[index + 1]);
		free(stock);
		stock = tmp;
		return (1);
	}
	return (gnl2(fd, line, &stock, index));
}
