#include "cub3d.h"

void	get_tex_troop_2(t_player *p, int *tex_num, double angle, t_sp *sp)
{
	int		motion = 5;
	int		time = sp->time % (6 * motion);

	if (time < motion)
		time = 1;
	else if (time < motion * 2)
		time = 2;
	else if (time < motion * 3)
		time = 3;
	else if (time < motion * 4)
		time = 4;
	else if (time < motion * 5)
		time = 5;
	else
		time = 6;
//---------------------------------------------

	if (angle < PI / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_A1 : TEX_STORMTROOPER_A2 : TEX_STORMTROOPER_A3 : TEX_STORMTROOPER_A4 : TEX_STORMTROOPER_A5 : TEX_STORMTROOPER_A6;
	else if (angle < PI * 3 / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_B1 : TEX_STORMTROOPER_B2 : TEX_STORMTROOPER_B3 : TEX_STORMTROOPER_B4 : TEX_STORMTROOPER_B5 : TEX_STORMTROOPER_B6;
	else if (angle < PI * 5 / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_C1 : TEX_STORMTROOPER_C2 : TEX_STORMTROOPER_C3 : TEX_STORMTROOPER_C4 : TEX_STORMTROOPER_C5 : TEX_STORMTROOPER_C6;
	else if (angle < PI * 7 / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_D1 : TEX_STORMTROOPER_D2 : TEX_STORMTROOPER_D3 : TEX_STORMTROOPER_D4 : TEX_STORMTROOPER_D5 : TEX_STORMTROOPER_D6;
	else if (angle < PI * 9 / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_E1 : TEX_STORMTROOPER_E2 : TEX_STORMTROOPER_E3 : TEX_STORMTROOPER_E4 : TEX_STORMTROOPER_E5 : TEX_STORMTROOPER_E6;
	else if (angle < PI * 11 / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_F1 : TEX_STORMTROOPER_F2 : TEX_STORMTROOPER_F3 : TEX_STORMTROOPER_F4 : TEX_STORMTROOPER_F5 : TEX_STORMTROOPER_F6;
	else if (angle < PI * 13 / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_G1 : TEX_STORMTROOPER_G2 : TEX_STORMTROOPER_G3 : TEX_STORMTROOPER_G4 : TEX_STORMTROOPER_G5 : TEX_STORMTROOPER_G6;
	else if (angle < PI * 15 / 8)
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_H1 : TEX_STORMTROOPER_H2 : TEX_STORMTROOPER_H3 : TEX_STORMTROOPER_H4 : TEX_STORMTROOPER_H5 : TEX_STORMTROOPER_H6;
	else
		*tex_num = time != 6 ? time!= 5 ? time != 4 ? time != 3 ? time != 2 ? TEX_STORMTROOPER_A1 : TEX_STORMTROOPER_A2 : TEX_STORMTROOPER_A3 : TEX_STORMTROOPER_A4 : TEX_STORMTROOPER_A5 : TEX_STORMTROOPER_A6;
	
	if (sp->time < 200 && sp->health_point != 0 && ((angle < PI * 3 / 8) || (PI * 14 / 8 < angle)))
	{
		if (sp->time % 10 < 5)
			*tex_num = TEX_STTP_SHOT2;
		else
			*tex_num = TEX_STTP_SHOT1;
			
		if (sp->time % 10 == 0)
//		if (sp->time == 1)
		{
			add_list_bullet(p, TEX_STTP_BULLET, sp);
		}
	}
	if (sp->health_point == 0)
	{
		if (sp->hit_time < 6)
			*tex_num = TEX_STTP_DEAD1;
		else if (sp->hit_time < 12)
			*tex_num = TEX_STTP_DEAD2;		
		else if (sp->hit_time < 18)
			*tex_num = TEX_STTP_DEAD3;
		else
			*tex_num = TEX_STTP_DEAD4;
	}
}

void	get_tex_troop(t_player *p, t_sp *sp)
{
	int		tex_num;
	double	angle;

	p->tmp = 1;
	angle = sp->move_angle - sp->angle + PI;
	angle = make_validate_angle(angle);
	get_tex_troop_2(p, &tex_num, angle, sp);
	sp->tex_num = tex_num;
}


void	facing_to_player(t_player *p, t_sp *sp)
{
	double face_sp_angle;

	p->tmp = 0;
	face_sp_angle = sp->move_angle - (sp->angle + PI);
	while (face_sp_angle < 0)
		face_sp_angle = face_sp_angle + PI * 2;
	while (face_sp_angle > PI)
		face_sp_angle = face_sp_angle - PI * 2;
	if (face_sp_angle > 0)
		sp->move_angle += PI / 128 * -1;
	else
		sp->move_angle += PI / 128;
}

void	move_troop(t_player *p, t_sp *sp)
{
	double	tmp_x;
	double	tmp_y;
	int		tmp_range;
	int		move_range;

	tmp_range = 1;
	move_range = 1;
	if ((sp->inside_aiming == 1 && p->key->shot == P_SHOT_HIT_TIME &&
		p->weapon->type != KEY_4) && sp->hit_time > 50)
		sp->alive = 0;
	if ((sp->inside_aiming == 1 && p->key->shot == P_SHOT_HIT_TIME &&
		p->weapon->type != KEY_4) || sp->health_point == 0)
	{
		sp->health_point = 0;
		return ;
	}
	if (sp->tex_num == TEX_STTP_SHOT1 || sp->tex_num == TEX_STTP_SHOT2)
		return ;
	while (tmp_range <= move_range)
	{
		tmp_x = cos(sp->move_angle) * GRID + sp->x_pos;
		if (check_wall(p, tmp_x, sp->y_pos) == 0)
			sp->x_pos = cos(sp->move_angle) + sp->x_pos;
		tmp_y = sin(sp->move_angle) * GRID + sp->y_pos;
		if (check_wall(p, sp->x_pos, tmp_y) == 0)
			sp->y_pos = sin(sp->move_angle) + sp->y_pos;
		tmp_range++;
	}
}

void	ft_stormtrooper(t_player *p, t_sp *sp)
{
	sp->time++;
	if (sp->time > 500)
		sp->time = 0;
	if (sp->health_point == 0 && sp->hit_time < 200)
		sp->hit_time++;
	facing_to_player(p, sp);
	move_troop(p, sp);
	get_tex_troop(p, sp);
	sp->tex = find_tex_from_list(p, sp->tex_num);
}

/*
**	time < 500
**	time < 2
**
**
**
**
**
**
*/
