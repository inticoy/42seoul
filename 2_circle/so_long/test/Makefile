# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/01/05 15:47:33 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
RM = rm -rf

# CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/draw_game.c srcs/draw_map.c srcs/draw_player.c \
		srcs/hook_key_press.c srcs/hook_key_release.c srcs/hook_loop.c \
		srcs/init_game.c srcs/init_key.c srcs/init_map.c srcs/init_player.c srcs/init_point.c \
		srcs/read_assets.c srcs/read_image.c srcs/read_map.c \
		srcs/so_long.c
OBJS = $(SRCS:.c=.o)

B_SRCS = ${SRCS:.c=_bonus.c}
B_OBJS = ${OBJS:.o=_bonus.o}

MINILIBX = ./minilibx
MLX = mlx

LIBFT = libft/libft.a

ifdef BONUS
    F_OBJS = $(B_OBJS)
else
    F_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(LIBFT) $(F_OBJS)
	$(CC) -L$(MINILIBX) -L./libft -framework OpenGL -framework Appkit -lz $(SRCS) -lmlx -lft -I $(MINILIBX) -I ./libft -I ./libft/libft -I ./libft/gnl -o $@

bonus : 
	make BONUS=1 all

$(LIBFT) :
	make -C libft bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I srcs -I libft -I minilibx -I libft/libft -I libft/gnl

clean :
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	make -C libft clean

fclean :
	make clean
	$(RM) $(NAME)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
