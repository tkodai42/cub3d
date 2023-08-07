# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkodai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 20:14:44 by tkodai            #+#    #+#              #
#    Updated: 2020/12/10 17:52:01 by tkodai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
XMAS_NAME	= cub3D_xmas
CC			= clang
CFLAGS		= -O3 -Wall -Wextra -Werror -I.
MLX			= libmlx.dylib
MLXFLAG		= -framework OpenGL -framework AppKit
MINILIB     = minilibx_mms_20200219
#CFLAGS		= -Wall -Wextra -Werror -I./minilib_mms_20200219

SRCS		= srcs/cub3d.c srcs/mini_map.c srcs/read_map.c srcs/check_map.c srcs/put_minimap.c srcs/put_p_and_ray.c srcs/put_rays.c srcs/ray_casting.c srcs/read_tex.c srcs/list_structure.c srcs/put_sprite.c srcs/utils.c srcs/draw_floor_loof.c srcs/frames.c srcs/get_background_colors.c srcs/gun_shot.c srcs/jump.c srcs/bonus_factor.c srcs/enemy.c srcs/sp_move.c srcs/bullet.c srcs/set_bonus_tex.c srcs/get_darker.c srcs/libft_cub3d.c srcs/can_move.c srcs/ft_spawn.c srcs/player_health.c srcs/skybox.c srcs/get_tex_colors.c srcs/draw_floor_upstair.c srcs/put_number_hud.c srcs/walking.c srcs/ft_door.c srcs/lost_soul_enemy.c srcs/big_boss.c srcs/put_num_ammo.c srcs/bmp.c srcs/ft_key.c srcs/init_variable.c srcs/move_player.c srcs/draw_background.c srcs/pixel_puts.c srcs/set_bonus_tex_utils.c srcs/set_bonus_tex_2.c srcs/big_boss_2.c srcs/put_sprite_2.c srcs/put_rays_2.c srcs/put_rays_3.c srcs/ft_key_press_or_release.c srcs/gun_shot_2.c srcs/gun_shot_3.c srcs/list_structure_2.c srcs/put_num_ammo_2.c srcs/put_p_and_ray_2.c srcs/put_sprite_3.c srcs/put_sprite_4.c srcs/lost_soul_enemy_2.c srcs/drum.c srcs/enemy_move_and_shot.c srcs/get_tex_colors_bonus.c srcs/error_messages.c srcs/ft_check_args.c srcs/gnl.c srcs/get_window_size.c srcs/divide_line.c srcs/devide_line_tools.c srcs/display_score.c srcs/divide_line_2.c srcs/ex_bonus/storm_trooper.c srcs/ex_bonus/storm_trooper_bullet.c

X_SRCS		= srcs/x_mas/cub3d.c srcs/x_mas/mini_map.c srcs/x_mas/read_map.c srcs/x_mas/check_map.c srcs/x_mas/put_minimap.c srcs/x_mas/put_p_and_ray.c srcs/x_mas/put_rays.c srcs/x_mas/ray_casting.c srcs/x_mas/read_tex.c srcs/x_mas/list_structure.c srcs/x_mas/put_sprite.c srcs/x_mas/utils.c srcs/x_mas/draw_floor_loof.c srcs/x_mas/frames.c srcs/x_mas/get_background_colors.c srcs/x_mas/gun_shot.c srcs/x_mas/jump.c srcs/x_mas/bonus_factor.c srcs/x_mas/enemy.c srcs/x_mas/sp_move.c srcs/x_mas/bullet.c srcs/x_mas/set_bonus_tex.c srcs/x_mas/get_darker.c srcs/x_mas/libft_cub3d.c srcs/x_mas/can_move.c srcs/x_mas/ft_spawn.c srcs/x_mas/player_health.c srcs/x_mas/skybox.c srcs/x_mas/get_tex_colors.c srcs/x_mas/draw_floor_upstair.c srcs/x_mas/put_number_hud.c srcs/x_mas/walking.c srcs/x_mas/ft_door.c srcs/x_mas/lost_soul_enemy.c srcs/x_mas/big_boss.c srcs/x_mas/put_num_ammo.c srcs/x_mas/bmp.c srcs/x_mas/ft_key.c srcs/x_mas/init_variable.c srcs/x_mas/move_player.c srcs/x_mas/draw_background.c srcs/x_mas/pixel_puts.c srcs/x_mas/set_bonus_tex_utils.c srcs/x_mas/set_bonus_tex_2.c srcs/x_mas/big_boss_2.c srcs/x_mas/put_sprite_2.c srcs/x_mas/put_rays_2.c srcs/x_mas/put_rays_3.c srcs/x_mas/ft_key_press_or_release.c srcs/x_mas/gun_shot_2.c srcs/x_mas/gun_shot_3.c srcs/x_mas/list_structure_2.c srcs/x_mas/put_num_ammo_2.c srcs/x_mas/put_p_and_ray_2.c srcs/x_mas/put_sprite_3.c srcs/x_mas/put_sprite_4.c srcs/x_mas/lost_soul_enemy_2.c srcs/x_mas/drum.c srcs/x_mas/enemy_move_and_shot.c srcs/x_mas/get_tex_colors_bonus.c srcs/x_mas/error_messages.c srcs/x_mas/ft_check_args.c srcs/x_mas/gnl.c srcs/x_mas/get_window_size.c srcs/x_mas/divide_line.c srcs/x_mas/devide_line_tools.c srcs/x_mas/display_score.c srcs/x_mas/divide_line_2.c srcs/ex_bonus/storm_trooper.c srcs/ex_bonus/storm_trooper_bullet.c


SRC_M		= srcs/main.c
SRC_M_B		= bonus/main_bonus.c

OBJS 	= $(SRCS:%.c=%.o)
X_OBJS 	= $(X_SRCS:%.c=%.o)
OBJ_M 	= $(SRC_M:%.c=%.o)
OBJ_M_B	= $(SRC_M_B:%.c=%.o)

OBJ_FILES = $(OBJS)
X_OBJ_FILES = $(X_OBJS)

all: $(NAME)

$(MLX) :
	cd 	"$(PWD)/$(MINILIB)" && make
	cd 	"$(PWD)/$(MINILIB)" && cp $(MLX) ../$(MLX)

all_b : $(OBJ_FILES) $(OBJ_M_B) $(MLX)
	rm -f $(OBJ_M)
	$(CC) $(OBJ_FILES) $(OBJ_M_B) $(MLX) $(MLXFLAG) -o $(NAME)
#	$(CC) -I /usr/local/include $(OBJ_FILES) $(OBJ_M_B) $(MLX) $(MLXFLAG) -o $(NAME)

$(XMAS_NAME) : $(X_OBJS) $(OBJ_M_B) $(MLX)
	rm -f $(OBJ_M)
	$(CC) $(X_OBJ_FILES) $(OBJ_M_B) $(MLX) $(MLXFLAG) -o $(XMAS_NAME)
	
$(NAME) : $(OBJ_FILES) $(OBJ_M) $(MLX)
	rm -f $(OBJ_M_B)
	$(CC) $(OBJ_FILES) $(OBJ_M) $(MLX) $(MLXFLAG) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJ_M) $(OBJ_M_B) $(X_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(XMAS_NAME)

re: fclean all

bonus: all_b

xmas: $(XMAS_NAME)

bonusrun: fclean all_b
	./cub3D map_bonus.cub

kill_mlx:
	rm -f $(MLX)
	cd 	"$(PWD)/$(MINILIB)" && rm -f $(MLX)

.PHONY: all all_b bonus clean fclean re run kill_mlx
