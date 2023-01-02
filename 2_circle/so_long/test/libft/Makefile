# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/01/02 16:40:30 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
AR = ar
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	convert/convert_padding.c convert/convert_precision.c convert/convert_prefix.c convert/convert_sign.c convert/convert_space.c \
	flag/init_flag.c flag/need_padding.c flag/need_precision.c flag/need_prefix.c flag/need_sign.c flag/need_space.c flag/update_flag.c \
	format/get_formatf.c format/init_format.c format/is_num_format.c format/is_str_format.c \
	string/ft_tstrjoin.c string/get_tstr_auto.c string/get_tstr.c string/get_tstrf.c \
	tostring/ft_ctoa.c tostring/ft_ptoa.c tostring/ft_utoa.c tostring/ft_vtoa.c tostring/ft_xtoa.c \
	utils/ft_free_s.c utils/ft_strtoupper.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

B_SRCS = ${SRCS:.c=_bonus.c}
B_OBJS = ${OBJS:.o=_bonus.o}

LIBFT = libft/libft.a

ifdef BONUS
    F_OBJS = $(B_OBJS)
else
    F_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(LIBFT) $(F_OBJS)
	cp $(LIBFT) $@
	$(AR) -rc $@ $(F_OBJS)

bonus : 
	make BONUS=1 all

$(LIBFT) :
	make -C libft all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I. -I libft -I gnl

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