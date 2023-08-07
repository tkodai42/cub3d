/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkodai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:56:59 by tkodai            #+#    #+#             */
/*   Updated: 2020/11/13 14:48:20 by tkodai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include "mlx.h"
# define PI				3.1415926534
# define GRID			64
# define WIN_PIXEL_X 	500
# define WIN_PIXEL_Y 	500
# define KEY_W			13
# define KEY_S			1
# define KEY_A			0
# define KEY_D			2
# define KEY_I			34
# define KEY_F			3
# define KEY_RIGHT		124
# define KEY_LEFT		123
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_SP			49
# define KEY_ESC		53
# define KEY_SHIFT_R	258
# define KEY_U			32
# define KEY_J			38
# define KEY_M			46
# define KEY_E			14
# define KEY_SHIFT_L	257
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define BLACK	0x000000
# define LIME	0x00FF00
# define RED	0xFF0000
# define WHITE	0xFFFFFF
# define RED2	0xFFAAAA
# define RED3	0xFF4050
# define RED4	0xbc143c
# define GRAY	0x808080
# define BLUE	0x0000FF
# define GREEN	0x008000
# define YELLOW	0xFFFF00
# define MAP_FLOOR_1F 	'0'
# define MAP_FLOOR_2F 	'3'
# define MAP_FLOOR_3F 	'4'
# define MAP_WALL		'1'
# define MAP_SPRITE		'2'
# define MAP_N			'N'
# define MAP_E			'E'
# define MAP_W			'W'
# define MAP_S			'S'
# define MAP_MAN	(MAP_FLOOR_1F || MAP_WALL || MAP_SPRITE)
# define MAP_ENEMY_1		 '5'
# define MAP_ENEMY_2		 '6'
# define MAP_ENEMY_3		 '7'
# define MAP_ENEMY_SP_POINT	'8'
# define MAP_WALL_HIDEN		'H'
# define MAP_ITEM_1			'9'
# define MAP_ITEM_2 		'A'
# define MAP_ITEM_3 		'B'
# define MAP_ITEM_4 		'C'
# define MAP_DOOR 			'D'
# define MAP_DOOR_OPEN 		'O'
# define MAP_DOOR_POS 		'C'
# define MAP_DRUM			'F'
# define TYPE_WALL	1
# define TYPE_FLOOR	2
# define TYPE_SP	3
# define T_S_OBJ	1
# define T_S_ENEMY	2
# define T_S_BULLET	3
# define T_S_ITEM	4
# define FLOOR_TEX	99
# define ENEMY_1 	5
# define ENEMY_1_2	51
# define ENEMY_1_3	52
# define ENEMY_1_DEAD_1 	53
# define ENEMY_BULLET		6
# define ENEMY_BULLET_1_2 	20
# define ENEMY_BULLET_1_3 	21
# define ENEMY_2			7
# define TEX_SKYBOX_N 101
# define TEX_SKYBOX_E 102
# define TEX_SKYBOX_W 103
# define TEX_SKYBOX_S 104
# define TEX_NUMBER_0 120
# define TEX_NUMBER_1 121
# define TEX_NUMBER_2 122
# define TEX_NUMBER_3 123
# define TEX_NUMBER_4 124
# define TEX_NUMBER_5 125
# define TEX_NUMBER_6 126
# define TEX_NUMBER_7 127
# define TEX_NUMBER_8 128
# define TEX_NUMBER_9 129
# define TEX_DRUM_EXPROSION_1	130
# define TEX_DRUM_EXPROSION_2	131
# define TEX_DRUM_EXPROSION_3	132
# define TEX_WALL_2	133
# define TEX_WALL_3	134
# define TEX_WALL_4	135
# define TEX_WALL_5	136
# define TEX_GUN2_1_1	137
# define TEX_GUN2_1_2	138
# define TEX_GUN2_2_1	139
# define TEX_GUN2_2_2	140
# define TEX_ENEMY_1_DEAD_1	141
# define TEX_ENEMY_1_DEAD_2	142
# define TEX_ENEMY_1_DEAD_3	143
# define TEX_ENEMY_1_DEAD_4	144
# define TEX_ENEMY_1_DAMEGE_1	145
# define TEX_SHOTGUN_1	146
# define TEX_SHOTGUN_2	147
# define TEX_SHOTGUN_3	148
# define TEX_SHOTGUN_4	149
# define TEX_SHOTGUN_5	150
# define TEX_SHOTGUN_6	151
# define TEX_HANDGUN_1	152
# define TEX_HANDGUN_2	153
# define TEX_HANDGUN_3	154
# define TEX_HANDGUN_4	155
# define TEX_HANDGUN_5	156
# define TEX_ENEMY2_A	157
# define TEX_ENEMY2_B	158
# define TEX_ENEMY2_C	159
# define TEX_ENEMY2_D	160
# define TEX_ENEMY2_E	161
# define TEX_ENEMY2_F	162
# define TEX_ENEMY2_G	163
# define TEX_ENEMY2_H	164
# define TEX_ENEMY2_DEAD1	165
# define TEX_ENEMY2_DEAD2	166
# define TEX_ENEMY2_DEAD3	167
# define TEX_ENEMY2_DEAD4	168
# define TEX_ENEMY2_DEAD5	169
# define TEX_ENEMY2_DEAD6	170
# define TEX_ENEMY2_NEUTRAL_1	171
# define TEX_ENEMY2_NEUTRAL_2	300
# define TEX_BOSS_1	172
# define TEX_BOSS_A	173
# define TEX_BOSS_B	174
# define TEX_BOSS_C	175
# define TEX_BOSS_D	176
# define TEX_BOSS_E	177
# define TEX_BOSS_F	178
# define TEX_BOSS_G	179
# define TEX_BOSS_H	180
# define TEX_BOSS_0	181
# define TEX_BOSS_WALK1	182
# define TEX_BOSS_WALK2	183
# define TEX_BOSS_WALK3	184
# define TEX_BOSS_WALK4	185
# define TEX_BOSS_DEAD1	186
# define TEX_BOSS_DEAD2	187
# define TEX_BOSS_DEAD3	188
# define TEX_BOSS_DEAD4	189
# define TEX_BOSS_DEAD5	190
# define TEX_BOSS_DEAD6	191
# define TEX_BOSS_DAMEGE1	192
# define TEX_BOSS_DAMEGE2	193
# define TEX_BULLET_A1	194
# define TEX_BULLET_B1	195
# define TEX_BULLET_C1	196
# define TEX_BULLET_D1	197
# define TEX_BULLET_E1	198
# define TEX_BULLET_F1	199
# define TEX_BULLET_G1	200
# define TEX_BULLET_H1	201
# define TEX_BULLET_A2	202
# define TEX_BULLET_B2	203
# define TEX_BULLET_C2	204
# define TEX_BULLET_D2	205
# define TEX_BULLET_E2	206
# define TEX_BULLET_F2	207
# define TEX_BULLET_G2	208
# define TEX_BULLET_H2	209
# define TEX_AMMO_1	210
# define TEX_AMMO_2	211
# define TEX_FIST_1	212
# define TEX_FIST_2	213
# define TEX_FIST_3	214
# define TEX_FIST_4	215
# define TEX_RED_SP	216
# define TEX_STORMTROOPER_1 217
# define TEX_STORMTROOPER_A1 218
# define TEX_STORMTROOPER_B1 219
# define TEX_STORMTROOPER_C1 220
# define TEX_STORMTROOPER_D1 221
# define TEX_STORMTROOPER_E1 222
# define TEX_STORMTROOPER_F1 223
# define TEX_STORMTROOPER_G1 224
# define TEX_STORMTROOPER_H1 225
# define TEX_STORMTROOPER_A2 226
# define TEX_STORMTROOPER_B2 227
# define TEX_STORMTROOPER_C2 228
# define TEX_STORMTROOPER_D2 229
# define TEX_STORMTROOPER_E2 230
# define TEX_STORMTROOPER_F2 231
# define TEX_STORMTROOPER_G2 232
# define TEX_STORMTROOPER_H2 233
# define TEX_STORMTROOPER_A3 234
# define TEX_STORMTROOPER_B3 235
# define TEX_STORMTROOPER_C3 236
# define TEX_STORMTROOPER_D3 237
# define TEX_STORMTROOPER_E3 238
# define TEX_STORMTROOPER_F3 239
# define TEX_STORMTROOPER_G3 240
# define TEX_STORMTROOPER_H3 241
# define TEX_STORMTROOPER_A4 242
# define TEX_STORMTROOPER_B4 243
# define TEX_STORMTROOPER_C4 244
# define TEX_STORMTROOPER_D4 245
# define TEX_STORMTROOPER_E4 246
# define TEX_STORMTROOPER_F4 247
# define TEX_STORMTROOPER_G4 248
# define TEX_STORMTROOPER_H4 249
# define TEX_STORMTROOPER_A5 250
# define TEX_STORMTROOPER_B5 251
# define TEX_STORMTROOPER_C5 252
# define TEX_STORMTROOPER_D5 253
# define TEX_STORMTROOPER_E5 254
# define TEX_STORMTROOPER_F5 255
# define TEX_STORMTROOPER_G5 256
# define TEX_STORMTROOPER_H5 257
# define TEX_STORMTROOPER_A6 258
# define TEX_STORMTROOPER_B6 259
# define TEX_STORMTROOPER_C6 260
# define TEX_STORMTROOPER_D6 261
# define TEX_STORMTROOPER_E6 262
# define TEX_STORMTROOPER_F6 263
# define TEX_STORMTROOPER_G6 264
# define TEX_STORMTROOPER_H6 265
# define TEX_STTP_BULLET 266
# define TEX_STTP_DEAD1 267
# define TEX_STTP_DEAD2 268
# define TEX_STTP_DEAD3 269
# define TEX_STTP_DEAD4 270
# define TEX_STTP_SHOT1 271
# define TEX_STTP_SHOT2 272

# define ERROR_ESC	1
# define ERROR_MALLOC	2
# define ERROR_PAS	3
# define ERROR_ARGS	4
# define ERROR_FD 5
# define ERROR_B	6
# define ERROR_C	7
# define ERROR_D	8
# define ENEMY_SP_POINT1_1	13
# define ENEMY_SP_POINT1_2	14
# define ENEMY_SP_POINT1_3	15
# define ENEMY_SP_POINT_N	301
# define TURN_SPEED PI / 48
# define MOVE_SPEED 7
# define MINI_POS 1
# define FOV 60
# define KILL_MINI 0
# define ADD_WALL_HEIGHT 2
# define JUMP_HEIGHT 1.5
# define JUMP_SPEED 0.1
# define JUMP_GRAVITY 0.01
# define CROUCH_HEIGHT 0.3
# define BONUS_ENEMY 1
# define ENEMY_MOVE_SPEED 2
# define ENEMY_BULLET_SPEED 12
# define ENEMY2_ATTACK_TIME 100
# define ENEMY2_MOVE_RANGE 5
# define BONUS_MAP_CHECK	0
# define BONUS_SEVERAL_LEVEL 1
# define BONUS_SOUND		0
# define P_SHOT_HIT_TIME	1
# define BONUS_DARKER		1
# define DARKER_RATIO		5
# define ONLY_SKYBOX		0
# define OMIT_LINE			1
# define SKYBOX_SAND		0
# define FOV_BASED_PI (PI * 2/ (360 / FOV))
# define FOV_LR (PI / (360 / FOV))
# define SCREEN_MAX_HEIGHT 1440
# define SCREEN_MAX_WIDTH 2560
# define IS_DYLIB 1
# define IMMORTAL 0
# define HUD_BLOOD 1

typedef struct			s_line
{
	double				x1;
	double				y1;
	double				x2;
	double				y2;
	double				range;
	double				angle;
}						t_line;

typedef	struct			s_dda
{
	float				tan_a;
	float				rx;
	float				ry;
	float				yo;
	float				xo;
	float				y_rx;
	float				y_ry;
	float				x_range;
	float				y_range;
	int					has_x_rear_wall;
	int					has_y_rear_wall;
	float				has_rear_wall;
	float				rear_x_range;
	float				rear_y_range;
	float				rear_wall_range;
	int					rear_wall_dir;
	float				rear_rx;
	float				rear_ry;
	float				rear_x_pos;
}						t_dda;

typedef struct			s_drawfloor
{
	int					win_y;
	double				pos_x;
	double				pos_y;
	double				range;
	int					color;
	double				width;
	double				width_add_dist;
	int					width_pos;
	double				wall_size;
	int					i;
}						t_df;

typedef struct			s_raycasting
{
	int					color;
	double				win_y;
	double				wall_hight;
	int					wh_pos;
}						t_raycasting;

typedef struct			s_dir
{
	char				*file_name;
	char				*addr;
	int					bits_per_pixel;
	int					line_len;
	int					xpm_width;
	int					xpm_height;
	int					type_bonus;
	int					file_type;
	struct s_dir		*next;
}						t_dir;

typedef	struct			s_sprite
{
	int					valid;
	int					alive;
	int					health_point;
	int					type;
	struct s_sprite		*next;
	struct s_dir		*tex;
	double				x_pos;
	double				y_pos;
	double				edge_xl;
	double				edge_yl;
	double				edge_xr;
	double				edge_yr;
	double				edge_angle_l;
	double				edge_angle_r;
	double				angle_width;
	double				range;
	double				fixed_range;
	double				height;
	double				width;
	double				angle;
	double				move_angle;
	int					move_range;
	double				z_pos;
	double				z_pos_add_num;
	int					inside_aiming;
	int					tex_num;
	int					time;
	double				moving;
	int					hit_time;
	double				bullet_left;
	double				bullet_right;
}						t_sp;

typedef	struct			s_health
{
	float				point;
	float				last_point;
	int					time;

}						t_health;

typedef struct			s_key
{
	int					w;
	int					s;
	int					a;
	int					d;
	int					f;
	int					right;
	int					left;
	int					up;
	int					down;
	int					sp;
	int					u;
	int					j;
	int					m;
	int					e;
	int					one;
	int					two;
	int					three;
	int					shift;
	int					jump;
	int					shot;
	int					map_on_off;
}						t_key;

typedef struct			s_jump
{
	double				jump_speed;
	int					stop_flag;
	int					floor;
}						t_jump;

typedef struct			s_skybox
{
	t_dir				*n;
	t_dir				*e;
	t_dir				*w;
	t_dir				*s;
}						t_skybox;

typedef struct			s_hud
{
	void				*ptr;
	void				*addr;
}						t_hud;

typedef struct			s_number_hud
{
	int					digit;
	int					width;
	int					height;
	int					num;
	int					wrote_digit;
	double				tex_x_pos;
	double				tex_y_pos;
}						t_num;

typedef struct			s_walk
{
	int					time;
	double				z_pos;
	double				angle;
	double				gun_x_pos;
}						t_walk;

typedef struct			s_weapon
{
	int					time;
	int					type;
	int					ammo_1;
	int					ammo_2;
	int					ammo_3;
}						t_weapon;

typedef struct			s_put_sp
{
	double				fixed_ra;
	double				fixed_edge_l;
	double				fixed_edge_r;
	int					put_pos_x;
	int					wrote_len;
}						t_put_sp;

typedef struct			s_putsptex
{
	int					boss;
	double				moving;
	double				fish_eye_height;
	double				height;
	double				sp_floor;
	double				sp_loof;
	double				y_pos_win;
	double				tex_y_pos;
	int					color;
	int					painted;
	int					x_pos_win;
	int					x_pos_img;
}						t_putsptex;

typedef struct			s_putlilne
{
	double				put_x;
	double				put_y;
	double				x;
	double				y;
	int					range;
}						t_putline;

typedef struct			s_move_wall
{
	t_dir				*tex_2;
	t_dir				*tex_3;
	t_dir				*tex_4;
	t_dir				*tex_5;
	t_dir				*door;
}						t_move_wall;

typedef struct			s_sp_move
{
	int					tmp_range;
	int					move_range;
	int					move_dir;
	double				move_angle;
	double				tmp_x;
	double				tmp_y;
}						t_sp_move;

typedef struct			s_putgun
{
	int					width;
	int					win_y;
	int					win_x;
	int					x_start_pos;
	double				win_ratio;
	int					color;
}						t_putgun;

typedef struct			s_mv_lost
{
	int					tmp_range;
	int					move_range;
	double				move_angle;
	double				tmp_x;
	double				tmp_y;
	int					tmp_xx;
	int					tmp_yy;

}						t_mv_lostsoul;

typedef struct			s_put_num_hud2
{
	int					x_pos;
	int					y_pos;
	int					width;
	int					height;
	int					color;
}						t_put_num_hud2;

typedef struct			s_check_file
{
	int					r;
	int					no;
	int					so;
	int					we;
	int					ea;
	int					sp;
	int					f;
	int					c;
	int					map;
	int					map_is_end;
	int					player;
}						t_check_file;

typedef struct			s_pack_line
{
	int					i_line;
	int					i_dest;
}						t_pack_line;

typedef struct			s_win_size
{
	int					index;
	int					size_x;
	int					size_y;
	int					element_1;
	int					element_2;
	int					too_big;
}						t_win_size;

typedef struct			s_color_check
{
	int					c1;
	int					c2;
	int					c3;
	int					c4;
	int					c1_exists;
	int					c2_exists;
	int					c3_exists;
}						t_color_check;

typedef struct			s_score
{
	int					cacodemon;
	int					lost_soul;
	int					cyber_demon;
	int					sg;
	int					hg;
	int					mg;
	int					melee;
	int					hit;
}						t_score;

typedef struct			s_player
{
	int					tmp;
	char				*tmp_str;
	void				*mlx_ptr;
	void				*win_ptr;
	int					win_width;
	int					win_height;
	int					pid;
	char				*file_name;
	int					win_x_size;
	int					win_y_size;
	char				**map;
	char				**map_check;
	int					map_index;
	int					init_p_x;
	int					init_p_y;
	char				init_p_angle;
	int					map_max_x;
	int					map_max_y;
	int					floor_color;
	int					loof_color;
	int					frame;
	double				frame_u_d_pos;
	t_key				*key;
	t_dir				*no;
	t_dir				*so;
	t_dir				*we;
	t_dir				*ea;
	t_dir				*tex_sp;
	t_dir				*tex_sp2;
	t_dir				*tex_sp_line;
	t_sp				*sp;
	t_dda				*dda;
	t_health			*health;
	t_skybox			*skybox;
	t_hud				*hud;
	t_walk				*walk;
	t_weapon			*weapon;
	t_jump				*jump;
	t_move_wall			*move_wall;
	t_check_file		*cf;
	t_score				*score;
	double				x_axis;
	double				y_axis;
	double				angle;
	double				move_range;
	double				ver_angle;
	double				jump_pos;
	double				jump_inital_velocity;
	void				*img_ptr;
	void				*img_addr;
	int					img_bit_per_pixel;
	int					img_line_length;
	int					img_endian;
	void				*mini_ptr;
	void				*mini_addr;
	int					mini_bit_per_pixel;
	int					mini_line_length;
	int					mini_endian;
	double				mini_grid;
	double				mini_grid_ratio;
	int					rayc_win_x;
	int					rayc_win_y;
	float				rayc_range;
	float				rayc_angle;
	int					rayc_dir;
	float				rayc_x;
	float				rayc_y;
	double				*buf_angle;
	double				*buf_range;
	double				*buf_draw_floor;
	double				*buf_draw_valid_height;
	double				*buf_draw_vh_head_pos;
	double				*buf_draw_f_range;
	int					win_buf_index;
	int					flame_count;
	int					kill_count;
	int					killed_flag;
	int					kill_frame;
	int					boss_spawn;
	int					boss_is_exists;
	int					no_more_lost_soul;
	int					lost_soul_num;
	double				is_door;
	int					is_door_pos;
	int					dda_x;
	int					dda_y;
	float				add_wall_count;
	int					save;
	char				*pass_ptr;
	int					is_dylib;
	int					is_bonus;
	int					cc1;
	int					cc2;
	int					cc3;
}						t_player;

int						main(int argc, char *argv[]);
void					my_mlx_pixel_put(t_player *p, int x, int y, int color);
void					my_mlx_pixel_put_hud(t_player *p,
						int x, int y, int color);
int						ft_cub3d3(t_player *p);
int						ft_look_up(t_player *p, int up);
void					ft_map_on(t_player *p);
int						ft_move(t_player *p, int move);
int						ft_turn(t_player *p, int turn);
int						ft_slide(t_player *p, int slide);
void					my_mlx_pixel_put_mini2(t_player *p,
						int x, int y, int c);
int						ft_mini_map(t_player *p);
void					my_mlx_pixel_put_mini(t_player *p, int x,
						int y, int color);
int						read_map(t_player *p);
int						open_file_tex(t_player *p, t_dir *dir);
int						ft_strchr(char *str, char c);
char					*ft_strdup(char *str);
int						ft_strlen(char *str);
char					*ft_strjoin(char *str1, char *str2);
int						check_map(t_player *p);
int						put_minimap(t_player *p);
int						put_p_and_ray(t_player *p);
int						within_screen_range(t_player *p, int win_x, int win_y);
int						put_point(t_player *p, int og_x, int og_y, int color);
int						check_wall(t_player *p, int x, int y);
float					ret_range(float x1, float x2, float x3, float x4);
int						put_rays(t_player *p);
int						ray_casting(t_player *p, int dir);
int						get_tex_color(t_player *p, int dir,
						double wall_height_pos, t_sp *sp);
int						get_tex_color_bonus(t_player *p, int dir,
						double wall_pos, t_sp *sp);
int						get_tex_color2(t_player *p, t_dir *dir,
						double wall_hight_pos, int rev);
int						get_tex_color3(t_player *p, t_dir *dir,
						double wall_hight_pos, int rev);
int						get_moving_wall_tex(t_player *p, int dir,
						double wall_pos);
int						read_tex_map(t_player *p, t_dir *dir, char *file_name);
int						add_list(t_player *p, int sp_type,
						int x_pos, int y_pos);
int						sort_list_sp(t_player *p);
int						*add_last_list(t_sp *list, t_sp *sp);
int						set_range_to_sp(t_player *p, int *sp_num);
int						put_sprite(t_player *p);
double					put_line(t_player *p, t_line pos, t_sp *sp);
int						put_circle(t_player *p, int x, int y, int color);
int						get_edge(t_player *p, t_line line_pos, t_sp *sp);
int						sp_get_fixed_r_h_w(t_player *p, t_sp *sp);
double					make_validate_angle(double angle);
double					make_pa_base(t_player *p, double angle);
int						trans_color(int fb);
void					ft_map_on(t_player *p);
int						get_mini_size(t_player *p);
int						ft_draw_floor(t_player *p, int floor_height);
int						ft_draw_floor_upstair(t_player *p, int floor_height);
int						get_background_colors(t_player *p,
						char *line, int f_or_c);
int						check_map_height(t_player *p, double x,
						double y, int fh);
int						get_tex_color_floor(t_player *p, t_dir *dir,
						double x, double y);
int						frame_count(t_player *p);
int						ft_jump(t_player *p, int fall_down, double crouch);
int						ft_get_jump_factor(t_player *p);
int						get_player_height(t_player *p, double crouch);
int						get_bonus_factor(t_player *p);
void					set_bonus_tex(t_player *p);
void					set_bonus_tex_6(t_player *p);
t_dir					*find_tex_from_list(t_player *p, int type);
int						set_new_tex_structure(t_player *p,
						char *fn, int f_type);
int						ft_cleate_enemy(t_player *p);
int						ft_enemy_move(t_player *p);
void					sp_move(t_player *p, t_sp *sp);
int						add_list_bullet(t_player *p, int type, t_sp *sp);
int						ft_bullet(t_player *p, t_sp *sp);
int						ft_shot(t_player *p);
int						ft_put_gun(t_player *p);
t_dir					*get_gun_tex(t_player *p, int tex_type);
void					ft_put_gun2(t_player *p, t_dir *tex);
int						can_move(t_player *p, double x_pos,
						double y_pos, double height);
int						get_darker(t_player *p, int color, double range);
int						get_darker_sprite(t_player *p, int color, double range);
int						ft_spawn_point(t_player *p, t_sp *sp);
int						ft_player_health(t_player *p);
int						ft_put_skybox(t_player *p);
void					ft_skybox_init(t_player *p);
int						get_tex_color(t_player *p, int d, double w, t_sp *sp);
int						put_number_hud(t_player *p);
int						ft_walking(t_player *p);
int						ft_door_x(t_player *p, t_dda *dda);
int						ft_door_y(t_player *p, t_dda *dda);
int						door_open_close(t_player *p, t_sp *door);
int						lost_soul(t_player *p, t_sp *sp);
int						get_tex_lostsoul(t_player *p, t_sp *sp);
void					big_boss(t_player *p, t_sp *boss);
int						get_tex_boss2(t_player *p, t_sp *sp);
int						get_tex_boss_dead(t_player *p, t_sp *sp);
void					get_tex_boss3(t_player *p, t_sp *sp, double angle);
int						get_tex_boss_hit(t_sp *sp);
int						put_num_ammo(t_player *p);
void					put_num_hud2(t_player *p, t_num *num, t_dir *tex);
int						save_bmp(t_player *p);
int						ft_key_released(int key, t_player *p);
int						ft_key_pressed(int key, t_player *p);
int						ft_reflect_key(t_player *p);
void					init_variable(t_player *p);
int						ft_draw_to_img(t_player *p);
void					ft_draw_background(t_player *p);
void					sp_is_valid2_1(t_player *p, t_sp *sp, t_put_sp *ptsp);
void					sp_is_valid2_2(t_player *p, t_sp *sp, t_put_sp *ptsp);
void					sp_is_valid2_3(t_player *p, t_sp *sp, t_put_sp *ptsp);
int						put_sp_tex(t_player *p, t_sp *sp, int x, int y);
int						rays_dda(t_player *p, float ray_angle);
float					validate_angle2(float angle);
int						init_dda_structure(t_player *p, t_dda *dda);
void					rays_dda_vertical(t_player *p, t_dda *dda);
void					rays_dda_horizontal(t_player *p, t_dda *dda);
void					rear_wall(t_player *p, t_dda *dda);
int						put_fov_rays(t_player *p, float angle);
int						validate_angle(t_player *p);
void					drum_explosion(t_player *p, t_sp *drum);
int						ft_enemy_move_and_shot(t_player *p, t_sp *enemy);
int						ft_knock_back(t_player *p, t_sp *sp);
int						ft_error(t_player *p, int type);
void					ft_check_args(t_player *p, int argc, char *argv[]);
int						ft_cub3d(t_player *p);
int						gnl(int fd, char **line);
int						read_win_size(t_player *p, char *line);
int						divide_line(t_player *p, char *line);
int						pack_line(char **line, t_player *p, char
						*dest, t_pack_line *pl);
int						skip_space(char **line, t_player *p);
int						ft_is_only_space_str(char *line);
void					display_score(t_player *p);
void					score_kill_count(t_player *p, t_sp *sp);
int						is_enough_element(t_player *p, char *line);
int						is_over_element(t_player *p, char *line);

void					ft_stormtrooper(t_player *p, t_sp *sp);
int						ft_bullet_sttp(t_player *p, t_sp *sp);
int						get_tex_color4(t_player *p, t_dir *dir,
						double wall_hight_pos, t_sp *sp);
//int						add_list_bullet_sttp(t_player *p, int type, t_sp *sp);
#endif
