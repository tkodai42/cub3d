/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:24:24 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/09 17:34:44 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		add_list_init(t_sp *new)
{
	new->next = NULL;
	new->valid = 1;
	new->alive = 1;
	new->z_pos = 0;
	new->z_pos_add_num = 0;
	new->inside_aiming = 0;
	new->health_point = 5;
	new->tex_num = 1;
	new->time = 0;
	new->hit_time = 0;
	new->range = 10000;
	new->tex = NULL;
	new->angle = 0;
	new->move_angle = 0;
	new->move_range = 0;
	return (0);
}

int		*add_last_list(t_sp *list, t_sp *add_sp)
{
	t_sp	*tmp;

	if (list->next == NULL)
	{
		list->next = add_sp;
		return (0);
	}
	tmp = list->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = add_sp;
	return (0);
}

int		add_list(t_player *p, int sp_type, int x_pos, int y_pos)
{
	t_sp	*new_sp;

	new_sp = malloc(sizeof(t_sp));
	if (new_sp == NULL)
		ft_error(p, 2);
	add_list_init(new_sp);
	new_sp->type = sp_type;
	new_sp->x_pos = x_pos;
	new_sp->y_pos = y_pos;
	if (p->sp == NULL)
	{
		p->sp = new_sp;
	}
	else
	{
		add_last_list(p->sp, new_sp);
	}
	return (0);
}

int		set_range_to_sp2(t_sp *sp, t_player *p)
{
	double	x;
	double	y;

	x = (p->x_axis - sp->x_pos);
	y = (p->y_axis - sp->y_pos);
	sp->range = sqrt((x * x) + (y * y));
	sp->fixed_range = sp->range;
	return (0);
}

int		set_range_to_sp(t_player *p, int *sp_num)
{
	t_sp *tmp;

	*sp_num = 0;
	if (p->sp)
		tmp = p->sp;
	else
		return (0);
	while (1)
	{
		(*sp_num)++;
		set_range_to_sp2(tmp, p);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (0);
}
