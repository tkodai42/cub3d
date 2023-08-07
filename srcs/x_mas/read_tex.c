/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:22:35 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/06 15:40:16 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cut_sp(char *file_name, int *index)
{
	while (*file_name && *file_name == ' ')
	{
		(*index)++;
		file_name++;
	}
	return (0);
}

int		open_file_tex(t_player *p, t_dir *dir)
{
	void	*img;
	int		tmp;

	img = mlx_xpm_file_to_image(p->mlx_ptr, dir->file_name,
			&dir->xpm_width, &dir->xpm_height);
	if (img == NULL)
		ft_error(p, ERROR_PAS);
	dir->addr = mlx_get_data_addr(img, &dir->bits_per_pixel,
			&dir->line_len, &tmp);
	return (0);
}

int		read_tex_map(t_player *p, t_dir *dir, char *file_name)
{
	int		index;
	char	*new_file_name;

	p->tmp = 0;
	dir->type_bonus = 0;
	index = 0;
	cut_sp(file_name + 2, &index);
	new_file_name = ft_strdup(file_name + 2 + index);
	free(file_name);
	dir->file_name = new_file_name;
	open_file_tex(p, dir);
	return (0);
}
