/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:05:57 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/16 11:25:22 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		score_kill_count(t_player *p, t_sp *enemy)
{
	if (enemy->type == ENEMY_1)
		p->score->cacodemon++;
	else if (enemy->type == ENEMY_2)
		p->score->lost_soul++;
	else if (enemy->type == TEX_BOSS_1)
		p->score->cyber_demon++;
}

void		sc_putnum(int num)
{
	if (num < 0)
		return ;
	if (num > 9)
	{
		sc_putnum(num / 10);
	}
	num = num % 10 + 48;
	write(1, &num, 1);
}

void		display_score2(t_player *p)
{
	int		num;
	double	num2;

	num = p->score->hg + p->score->sg + p->score->mg + p->score->melee;
	if (num == 0)
		num2 = 0;
	else
		num2 = (double)p->score->hit / num * 100;
	write(1, "shots      x ", 13);
	sc_putnum(num);
	write(1, "\n", 1);
	write(1, "accuracy     ", 13);
	sc_putnum(num2);
	write(1, " %\n", 3);
	write(1, "o---------------o\n\n", 19);
}

void		display_score(t_player *p)
{
	if (p->is_bonus == 0)
		return ;
	if (p->score->cyber_demon > 0)
		write(1, "\n[YOU WIN!!]\n", 13);
	write(1, "o---------------o\n", 18);
	write(1, "[kills]\n", 8);
	write(1, "cacodemon  x ", 13);
	sc_putnum(p->score->cacodemon);
	write(1, "\n", 1);
	write(1, "lost soul  x ", 13);
	sc_putnum(p->score->lost_soul);
	write(1, "\n", 1);
	write(1, "cyberdemon x ", 13);
	sc_putnum(p->score->cyber_demon);
	write(1, "\n", 1);
	write(1, "total      x ", 13);
	sc_putnum(p->kill_count);
	write(1, "\n - - - - - - - - \n", 19);
	display_score2(p);
}
