/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus_tex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:31:29 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/05 18:31:51 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dir	*find_tex_from_list(t_player *p, int file_type)
{
	t_dir *ret_dir;

	ret_dir = p->tex_sp_line;
	while (ret_dir->file_type != file_type)
	{
		ret_dir = ret_dir->next;
		if (ret_dir == NULL)
			return (ret_dir);
	}
	return (ret_dir);
}

int		add_tex_list_last(t_dir *list, t_dir *new_tex)
{
	t_dir	*tmp;

	if (list->next == NULL)
	{
		list->next = new_tex;
		return (0);
	}
	tmp = list->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_tex;
	return (0);
}

int		set_new_tex_structure(t_player *p, char *file_name, int file_type)
{
	t_dir *new_tex;

	new_tex = malloc(sizeof(t_dir));
	if (new_tex == NULL)
		ft_error(p, 2);
	new_tex->file_name = file_name;
	new_tex->file_type = file_type;
	new_tex->type_bonus = 1;
	new_tex->next = NULL;
	if (p->tex_sp_line == NULL)
	{
		p->tex_sp_line = new_tex;
	}
	else
	{
		add_tex_list_last(p->tex_sp_line, new_tex);
	}
	open_file_tex(p, new_tex);
	return (0);
}
