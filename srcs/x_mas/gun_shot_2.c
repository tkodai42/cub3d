/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_shot_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:34:46 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 14:22:48 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_shot2(t_player *p)
{
	if (p->key->shot >= 13 && p->weapon->type == KEY_1)
		p->key->shot = 0;
	if (p->key->shot >= 3 && p->weapon->type == KEY_2)
		p->key->shot = 0;
	if (p->key->shot >= 30 && p->weapon->type == KEY_3)
		p->key->shot = 0;
	if (p->key->shot >= 30 && p->weapon->type == KEY_4)
		p->key->shot = 0;
}

int		ft_shot(t_player *p)
{
	if (p->key->shot == 0)
	{
		if (p->weapon->type == KEY_1 && p->weapon->ammo_1)
		{
			p->key->shot = 1;
			p->weapon->ammo_1--;
		}
		if (p->weapon->type == KEY_2 && p->weapon->ammo_2)
		{
			p->key->shot = 1;
			p->weapon->ammo_2--;
		}
		if (p->weapon->type == KEY_3 && p->weapon->ammo_3)
		{
			p->key->shot = 1;
			p->weapon->ammo_3--;
		}
		if (p->weapon->type == KEY_4)
			p->key->shot = 1;
	}
	else
		p->key->shot++;
	ft_shot2(p);
	return (0);
}

int		get_gun_color(t_dir *tex, double x_ratio, double y_ratio)
{
	int	color;
	int	x;
	int	y;

	x = tex->xpm_width * x_ratio;
	y = tex->xpm_height * y_ratio;
	color = *(unsigned int *)(tex->addr + y * tex->line_len + x * 4);
	return (color);
}

void	ft_put_gun3(t_player *p, t_putgun *pg)
{
	pg->win_ratio = 2;
	if (p->weapon->type == KEY_2)
		pg->win_ratio = 3;
	if (p->weapon->type == KEY_3)
		pg->win_ratio = (double)15 / 10;
	if (p->weapon->type == KEY_4)
		pg->win_ratio = (double)30 / 10;
}

void	ft_put_gun2(t_player *p, t_dir *tex)
{
	t_putgun	pg;

	ft_put_gun3(p, &pg);
	pg.win_y = p->win_height - (p->win_height / pg.win_ratio);
	pg.width = p->win_height / pg.win_ratio * tex->xpm_width / tex->xpm_height;
	pg.win_x = p->win_width / 2 - pg.width / 2 + p->walk->gun_x_pos;
	pg.x_start_pos = pg.win_x;
	while (pg.win_y < p->win_height)
	{
		while (pg.win_x < p->win_width / 2 + pg.width / 2 +
			p->walk->gun_x_pos - 1)
		{
			pg.color = get_gun_color(tex, (double)(pg.win_x - pg.x_start_pos) /
				pg.width, (double)(pg.win_y - (p->win_height - p->win_height /
						pg.win_ratio)) / (p->win_height / pg.win_ratio));
			if (pg.color >= 0)
				my_mlx_pixel_put(p, pg.win_x, pg.win_y, pg.color);
			pg.win_x++;
		}
		pg.win_x = pg.x_start_pos;
		pg.win_y++;
	}
}
