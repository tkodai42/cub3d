/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_shot_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:21:47 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/04 17:22:23 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dir	*get_gun_tex(t_player *p, int tex_type)
{
	t_dir	*ret_tex;

	ret_tex = p->tex_sp_line;
	while (ret_tex != NULL)
	{
		if (ret_tex->file_type == tex_type)
			return (ret_tex);
		ret_tex = ret_tex->next;
	}
	return (p->tex_sp_line);
}
