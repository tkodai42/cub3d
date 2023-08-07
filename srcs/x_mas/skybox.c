/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:32:27 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 14:20:40 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_color_skybox(t_dir *tex, double x_rate, double y_rate)
{
	int		color;
	int		x;
	int		y;

	x = tex->xpm_width * x_rate;
	y = tex->xpm_height * y_rate;
	if (y >= tex->xpm_height || y < 0)
		return (BLACK);
	color = *(unsigned int *)(tex->addr + y * tex->line_len + x * 4);
	return (color);
}

int		ft_put_skybox2(t_player *p, int win_x_pos, double tex_x_rate,
		t_dir *tmp)
{
	double	tex_y_rate;
	int		win_y_pos;
	int		height;
	int		color;

	height = p->win_width * 90 / FOV;
	win_y_pos = p->win_height - 1;
	color = RED;
	while (win_y_pos >= 0)
	{
		tex_y_rate = (double)(height / 2 +
				(win_y_pos - p->win_height / 2)) / height;
		color = get_tex_color_skybox(tmp, tex_x_rate, tex_y_rate);
		my_mlx_pixel_put(p, win_x_pos, win_y_pos, color);
		win_y_pos--;
	}
	return (0);
}

double	get_skybox_dir2(t_player *p, double skybox_angle, t_dir **dest)
{
	double	rv;

	if (skybox_angle < PI * 7 / 4)
	{
		*dest = p->skybox->n;
		rv = skybox_angle - PI * 5 / 4;
	}
	else
	{
		*dest = p->skybox->e;
		rv = skybox_angle - PI * 7 / 4;
	}
	return (rv);
}

double	get_skybox_dir(t_player *p, double skybox_angle, t_dir **dest)
{
	double	rv;

	if (skybox_angle < PI * 1 / 4)
	{
		*dest = p->skybox->e;
		rv = skybox_angle + PI * 1 / 4;
	}
	else if (skybox_angle < PI * 3 / 4)
	{
		*dest = p->skybox->s;
		rv = skybox_angle - PI * 1 / 4;
	}
	else if (skybox_angle < PI * 5 / 4)
	{
		*dest = p->skybox->w;
		rv = skybox_angle - PI * 3 / 4;
	}
	else
		rv = get_skybox_dir2(p, skybox_angle, dest);
	rv = rv / (PI / 2);
	return (rv);
}

int		ft_put_skybox(t_player *p)
{
	t_dir	*tmp;
	double	x_pos;
	double	angle_add_num;
	double	skybox_angle;
	double	tex_x_rate;

	x_pos = 0;
	skybox_angle = p->angle - FOV_BASED_PI / 2;
	angle_add_num = FOV_BASED_PI / p->win_width;
	while (x_pos < p->win_width)
	{
		tex_x_rate = get_skybox_dir(p, skybox_angle, &tmp);
		ft_put_skybox2(p, x_pos, tex_x_rate, tmp);
		x_pos++;
		skybox_angle += angle_add_num;
	}
	return (0);
}
