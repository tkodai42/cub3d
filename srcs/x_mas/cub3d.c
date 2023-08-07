/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:02:34 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 14:54:42 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_cub3d3(t_player *p)
{
	mlx_do_sync(p->mlx_ptr);
	ft_draw_to_img(p);
	put_minimap(p);
	put_p_and_ray(p);
	put_sprite(p);
	if (p->is_bonus)
		ft_put_gun(p);
	if (p->is_bonus)
		ft_player_health(p);
	if (p->save == 1)
		save_bmp(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	if (p->key->map_on_off == 0)
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->mini_ptr,
			0, 0);
	if (p->is_bonus && HUD_BLOOD)
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->hud->ptr, 0, 0);
	if (p->is_bonus)
		frame_count(p);
	if (p->is_bonus)
		ft_enemy_move(p);
	if (p->is_bonus)
		ft_walking(p);
	return (0);
}

int	ft_cub3d2(t_player *p)
{
	get_mini_size(p);
	p->win_ptr = 0;
	if (p->save == 0)
		p->win_ptr = mlx_new_window(p->mlx_ptr, p->win_width, p->win_height,
			"cub3d");
	p->img_ptr = mlx_new_image(p->mlx_ptr, p->win_width, p->win_height);
	p->img_addr = mlx_get_data_addr(p->img_ptr, &p->img_bit_per_pixel,
			&p->img_line_length, &p->img_endian);
	ft_mini_map(p);
	p->hud->ptr = mlx_new_image(p->mlx_ptr, p->win_width, p->win_height);
	p->hud->addr = mlx_get_data_addr(p->hud->ptr, &p->img_bit_per_pixel,
			&p->img_line_length, &p->img_endian);
	if (p->save == 0)
	{
		mlx_hook(p->win_ptr, 2, 0, ft_key_pressed, p);
		mlx_hook(p->win_ptr, 3, 0, ft_key_released, p);
		mlx_hook(p->win_ptr, 17, 0, ft_error, p);
	}
	mlx_loop_hook(p->mlx_ptr, ft_reflect_key, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}

int	ft_cub3d1(t_player *p)
{
	t_jump		jump;
	t_move_wall	move_wall;
	t_key		key;
	t_score		score;
	t_dir		tex_sp2;

	p->key = &key;
	p->jump = &jump;
	p->score = &score;
	p->move_wall = &move_wall;
	p->tex_sp2 = &tex_sp2;
	p->sp = NULL;
	p->map_max_x = 0;
	p->mlx_ptr = mlx_init();
	read_map(p);
	if (p->is_bonus == 0)
		check_map(p);
	init_variable(p);
	set_bonus_tex(p);
	get_bonus_factor(p);
	ft_cub3d2(p);
	return (0);
}

int	ft_cub3d_2(t_player *p)
{
	t_health	health;
	t_skybox	skybox;
	t_hud		hud;
	t_walk		walk;
	t_weapon	weapon;

	p->health = &health;
	p->skybox = &skybox;
	p->walk = &walk;
	p->weapon = &weapon;
	p->hud = &hud;
	ft_cub3d1(p);
	return (0);
}

int	ft_cub3d(t_player *p)
{
	t_dir no;
	t_dir so;
	t_dir we;
	t_dir ea;
	t_dir tex_sp;

	p->no = &no;
	p->so = &so;
	p->we = &we;
	p->ea = &ea;
	p->tex_sp = &tex_sp;
	ft_cub3d_2(p);
	return (0);
}
