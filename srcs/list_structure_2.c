/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_structure_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:28:54 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/04 18:33:20 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sp2(t_sp *target_1, t_sp *target_2, t_sp *target_3, int num)
{
	while (num--)
	{
		if (target_2->range < target_3->range)
		{
			target_1->next = target_3;
			target_2->next = target_3->next;
			target_3->next = target_2;
		}
		target_1 = target_1->next;
		target_2 = target_1->next;
		if (target_2->next != NULL)
			target_3 = target_2->next;
		else
			break ;
	}
}

int		sort_sp(t_player *p, int num)
{
	t_sp	head;
	t_sp	*target_1;
	t_sp	*target_2;
	t_sp	*target_3;

	if (p->sp)
	{
		target_1 = &head;
		target_2 = p->sp;
		head.next = target_2;
		if (target_2->next == NULL)
			return (0);
		target_3 = target_2->next;
	}
	else
		return (0);
	sort_sp2(target_1, target_2, target_3, num);
	p->sp = head.next;
	return (0);
}

int		kill_dead_sp2(t_sp *tmp_1, t_sp *tmp_2, t_sp *del_target)
{
	while (tmp_2->next != NULL)
	{
		if (tmp_2->alive == 0)
		{
			del_target = tmp_2;
			tmp_1->next = tmp_2->next;
			tmp_2 = tmp_2->next;
			free(del_target);
			del_target = NULL;
		}
		else
		{
			tmp_1 = tmp_2;
			tmp_2 = tmp_2->next;
		}
	}
	if (tmp_2->alive == 0)
	{
		free(tmp_2);
		tmp_2 = NULL;
		tmp_1->next = NULL;
	}
	return (0);
}

int		kill_dead_sp(t_player *p)
{
	t_sp head;
	t_sp *tmp_1;
	t_sp *tmp_2;
	t_sp *del_target;

	del_target = NULL;
	if (p->sp)
	{
		tmp_1 = &head;
		head.next = p->sp;
		tmp_2 = p->sp;
	}
	else
		return (0);
	kill_dead_sp2(tmp_1, tmp_2, del_target);
	p->sp = head.next;
	return (0);
}

int		sort_list_sp(t_player *p)
{
	int	i;

	kill_dead_sp(p);
	set_range_to_sp(p, &i);
	sort_sp(p, i);
	return (0);
}
