# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by jinhchoi          #+#    #+#              #
#    Updated: 2022/12/17 13:19:11 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar
RM = rm -rf
CFLAGS = 
ARFLAGS = -rc
SRCFILES := ft_printf.c \
			convert/convert_padding.c convert/convert_precision.c convert/convert_prefix.c convert/convert_sign.c convert/convert_space.c \
			flag/init_flag.c flag/need_padding.c flag/need_precision.c flag/need_prefix.c flag/need_sign.c flag/need_space.c flag/update_flag.c \
			format/get_formatf.c format/init_format.c format/is_num_format.c format/is_str_format.c \
			string/ft_tstrjoin.c string/get_tstr_auto.c string/get_tstr.c string/get_tstrf.c \
			tostring/ft_ctoa.c tostring/ft_ptoa.c tostring/ft_utoa.c tostring/ft_vtoa.c tostring/ft_xtoa.c \
			utils/ft_free_s.c \
			utils/ft_strndup.c utils/ft_strtoupper.c 
OBJS := $(SRCFILES:.c=.o)
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	ar -rc $@ $(OBJS)

bonus : $(NAME)

$(LIBFT) :
	make -C libft bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I. -I libft

clean :
	$(RM) $(OBJS)
	make -C libft clean

fclean : clean
	$(RM) $(NAME)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY : all clean fclean re