# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/01/02 16:46:26 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c
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
	$(CC) -L$(MINILIBX) -L./libft -framework OpenGL -framework Appkit -lz $(SRCS) -lmlx -lft -I $(MINILIBX) -I ./libft -I ./libft/libft

bonus : 
	make BONUS=1 all

$(LIBFT) :
	make -C libft bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I. -I libft -I minilibx -I libft/libft

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
