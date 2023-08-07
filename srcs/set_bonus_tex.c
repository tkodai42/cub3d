/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:13:48 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/11 18:28:10 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_bonus_tex_5(t_player *p)
{
	set_new_tex_structure(p, "./texture/enemy/BOSS_A.xpm", TEX_BOSS_A);
	set_new_tex_structure(p, "./texture/enemy/BOSS_B.xpm", TEX_BOSS_B);
	set_new_tex_structure(p, "./texture/enemy/BOSS_C.xpm", TEX_BOSS_C);
	set_new_tex_structure(p, "./texture/enemy/BOSS_D.xpm", TEX_BOSS_D);
	set_new_tex_structure(p, "./texture/enemy/BOSS_E.xpm", TEX_BOSS_E);
	set_new_tex_structure(p, "./texture/enemy/BOSS_F.xpm", TEX_BOSS_F);
	set_new_tex_structure(p, "./texture/enemy/BOSS_G.xpm", TEX_BOSS_G);
	set_new_tex_structure(p, "./texture/enemy/BOSS_H.xpm", TEX_BOSS_H);
	set_new_tex_structure(p, "./texture/enemy/BOSS_0.xpm", TEX_BOSS_0);
	set_new_tex_structure(p, "./texture/enemy/BOSS_WALK1.xpm", TEX_BOSS_WALK1);
	set_new_tex_structure(p, "./texture/enemy/BOSS_WALK2.xpm", TEX_BOSS_WALK2);
	set_new_tex_structure(p, "./texture/enemy/BOSS_WALK3.xpm", TEX_BOSS_WALK3);
	set_new_tex_structure(p, "./texture/enemy/BOSS_WALK4.xpm", TEX_BOSS_WALK4);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DEAD1.xpm", TEX_BOSS_DEAD1);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DEAD2.xpm", TEX_BOSS_DEAD2);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DEAD3.xpm", TEX_BOSS_DEAD3);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DEAD4.xpm", TEX_BOSS_DEAD4);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DEAD5.xpm", TEX_BOSS_DEAD5);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DEAD6.xpm", TEX_BOSS_DEAD6);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DAMEGE1.xpm",
			TEX_BOSS_DAMEGE1);
	set_new_tex_structure(p, "./texture/enemy/BOSS_DAMEGE2.xpm",
			TEX_BOSS_DAMEGE2);
	set_bonus_tex_6(p);
}

void	set_bonus_tex_4(t_player *p)
{
	set_new_tex_structure(p, "./texture/number/mini_number0.xpm", TEX_NUMBER_0);
	set_new_tex_structure(p, "./texture/number/mini_number1.xpm", TEX_NUMBER_1);
	set_new_tex_structure(p, "./texture/number/mini_number2.xpm", TEX_NUMBER_2);
	set_new_tex_structure(p, "./texture/number/mini_number3.xpm", TEX_NUMBER_3);
	set_new_tex_structure(p, "./texture/number/mini_number4.xpm", TEX_NUMBER_4);
	set_new_tex_structure(p, "./texture/number/mini_number5.xpm", TEX_NUMBER_5);
	set_new_tex_structure(p, "./texture/number/mini_number6.xpm", TEX_NUMBER_6);
	set_new_tex_structure(p, "./texture/number/mini_number7.xpm", TEX_NUMBER_7);
	set_new_tex_structure(p, "./texture/number/mini_number8.xpm", TEX_NUMBER_8);
	set_new_tex_structure(p, "./texture/number/mini_number9.xpm", TEX_NUMBER_9);
	set_new_tex_structure(p, "./texture/eagle.xpm", MAP_DOOR_POS);
	set_new_tex_structure(p, "./texture/DOOR2_1.xpm", MAP_DOOR);
	set_new_tex_structure(p, "./texture/drum1.xpm", MAP_DRUM);
	set_new_tex_structure(p, "./texture/drum_boom1.xpm", TEX_DRUM_EXPROSION_1);
	set_new_tex_structure(p, "./texture/drum_boom2.xpm", TEX_DRUM_EXPROSION_2);
	set_new_tex_structure(p, "./texture/drum_boom3.xpm", TEX_DRUM_EXPROSION_3);
	set_new_tex_structure(p, "./texture/weapon/shotgun1.xpm", TEX_SHOTGUN_1);
	set_new_tex_structure(p, "./texture/weapon/shotgun2.xpm", TEX_SHOTGUN_2);
	set_new_tex_structure(p, "./texture/weapon/shotgun3.xpm", TEX_SHOTGUN_3);
	set_new_tex_structure(p, "./texture/weapon/shotgun4.xpm", TEX_SHOTGUN_4);
	set_new_tex_structure(p, "./texture/weapon/shotgun5.xpm", TEX_SHOTGUN_5);
	set_new_tex_structure(p, "./texture/weapon/shotgun6.xpm", TEX_SHOTGUN_6);
	set_bonus_tex_5(p);
}

void	set_bonus_tex_3(t_player *p)
{
	set_new_tex_structure(p, "./texture/bullet/BULLET_A1.xpm", TEX_BULLET_A1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_B1.xpm", TEX_BULLET_B1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_C1.xpm", TEX_BULLET_C1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_D1.xpm", TEX_BULLET_D1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_E1.xpm", TEX_BULLET_E1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_F1.xpm", TEX_BULLET_F1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_G1.xpm", TEX_BULLET_G1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_H1.xpm", TEX_BULLET_H1);
	set_new_tex_structure(p, "./texture/bullet/BULLET_A2.xpm", TEX_BULLET_A2);
	set_new_tex_structure(p, "./texture/bullet/BULLET_B2.xpm", TEX_BULLET_B2);
	set_new_tex_structure(p, "./texture/bullet/BULLET_C2.xpm", TEX_BULLET_C2);
	set_new_tex_structure(p, "./texture/bullet/BULLET_D2.xpm", TEX_BULLET_D2);
	set_new_tex_structure(p, "./texture/bullet/BULLET_E2.xpm", TEX_BULLET_E2);
	set_new_tex_structure(p, "./texture/bullet/BULLET_F2.xpm", TEX_BULLET_F2);
	set_new_tex_structure(p, "./texture/bullet/BULLET_G2.xpm", TEX_BULLET_G2);
	set_new_tex_structure(p, "./texture/bullet/BULLET_H2.xpm", TEX_BULLET_H2);
	set_new_tex_structure(p, "./texture/weapon/ammo_ammo.xpm", TEX_AMMO_1);
	set_new_tex_structure(p, "./texture/weapon/ammo_shotshell.xpm", TEX_AMMO_2);
	set_new_tex_structure(p, "./texture/weapon/fist1.xpm", TEX_FIST_1);
	set_new_tex_structure(p, "./texture/weapon/fist2.xpm", TEX_FIST_2);
	set_new_tex_structure(p, "./texture/weapon/fist3.xpm", TEX_FIST_3);
	set_new_tex_structure(p, "./texture/weapon/fist4.xpm", TEX_FIST_4);
	set_bonus_tex_4(p);
}

int		set_bonus_tex_2(t_player *p)
{
	set_new_tex_structure(p, "./texture/enemy/LS_AT_A1.xpm", TEX_ENEMY2_A);
	set_new_tex_structure(p, "./texture/enemy/LS_AT_B1.xpm", TEX_ENEMY2_B);
	set_new_tex_structure(p, "./texture/enemy/LS_AT_C1.xpm", TEX_ENEMY2_C);
	set_new_tex_structure(p, "./texture/enemy/LS_AT_D1.xpm", TEX_ENEMY2_D);
	set_new_tex_structure(p, "./texture/enemy/LS_AT_E1.xpm", TEX_ENEMY2_E);
	set_new_tex_structure(p, "./texture/enemy/LS_AT_F1.xpm", TEX_ENEMY2_F);
	set_new_tex_structure(p, "./texture/enemy/LS_AT_G1.xpm", TEX_ENEMY2_G);
	set_new_tex_structure(p, "./texture/enemy/LS_AT_H1.xpm", TEX_ENEMY2_H);
	set_new_tex_structure(p, "./texture/enemy/LS_DEAD_1.xpm", TEX_ENEMY2_DEAD1);
	set_new_tex_structure(p, "./texture/enemy/LS_DEAD_2.xpm", TEX_ENEMY2_DEAD2);
	set_new_tex_structure(p, "./texture/enemy/LS_DEAD_3.xpm", TEX_ENEMY2_DEAD3);
	set_new_tex_structure(p, "./texture/enemy/LS_DEAD_4.xpm", TEX_ENEMY2_DEAD4);
	set_new_tex_structure(p, "./texture/enemy/LS_DEAD_5.xpm", TEX_ENEMY2_DEAD5);
	set_new_tex_structure(p, "./texture/enemy/LS_DEAD_6.xpm", TEX_ENEMY2_DEAD6);
	set_new_tex_structure(p, "./texture/enemy/LS_N_A1.xpm",
			TEX_ENEMY2_NEUTRAL_1);
	set_new_tex_structure(p, "./texture/enemy/LS_N_A2.xpm",
			TEX_ENEMY2_NEUTRAL_2);
	set_bonus_tex_3(p);
	return (0);
}

void	set_bonus_tex(t_player *p)
{
	set_new_tex_structure(p, p->is_bonus ? "./texture/pics/greystone.xpm" :
		p->no->file_name, FLOOR_TEX);
	if (p->is_bonus == 0)
		return ;
	set_new_tex_structure(p, "./texture/enemy_bullet.xpm", ENEMY_BULLET);
	set_new_tex_structure(p, "./texture/enemy_bullet_2.xpm", ENEMY_BULLET_1_2);
	set_new_tex_structure(p, "./texture/enemy_bullet_3.xpm", ENEMY_BULLET_1_3);
	set_new_tex_structure(p, "./texture/weapon/handgun1.xpm", TEX_HANDGUN_1);
	set_new_tex_structure(p, "./texture/weapon/handgun2.xpm", TEX_HANDGUN_2);
	set_new_tex_structure(p, "./texture/weapon/handgun3.xpm", TEX_HANDGUN_3);
	set_new_tex_structure(p, "./texture/weapon/handgun4.xpm", TEX_HANDGUN_4);
	set_new_tex_structure(p, "./texture/weapon/handgun5.xpm", TEX_HANDGUN_5);
	set_new_tex_structure(p, "./texture/spawn.xpm", ENEMY_SP_POINT1_1);
	set_new_tex_structure(p, "./texture/spawn_2.xpm", ENEMY_SP_POINT1_2);
	set_new_tex_structure(p, "./texture/spawn_3.xpm", ENEMY_SP_POINT1_3);
	set_new_tex_structure(p, "./texture/spawn_4.xpm", ENEMY_SP_POINT_N);
	set_new_tex_structure(p, "./texture/pics/mossy2.xpm", TEX_WALL_2);
	set_new_tex_structure(p, "./texture/pics/mossy3.xpm", TEX_WALL_3);
	set_new_tex_structure(p, "./texture/pics/mossy4.xpm", TEX_WALL_4);
	set_new_tex_structure(p, "./texture/pics/mossy5.xpm", TEX_WALL_5);
	set_new_tex_structure(p, "./texture/gun2_1_1.xpm", TEX_GUN2_1_1);
	set_new_tex_structure(p, "./texture/gun2_1_2.xpm", TEX_GUN2_1_2);
	set_new_tex_structure(p, "./texture/gun2_2_1.xpm", TEX_GUN2_2_1);
	set_new_tex_structure(p, "./texture/gun2_2_2.xpm", TEX_GUN2_2_2);
	set_bonus_tex_2(p);
}
