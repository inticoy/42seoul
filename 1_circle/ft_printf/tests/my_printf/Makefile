# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by jinhchoi          #+#    #+#              #
#    Updated: 2022/12/15 22:46:35 by gyoon            ###   ########.fr        #
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
			format/get_formatf.c format/init_format.c \
			string/del_tstr.c string/ft_strtotstr.c string/ft_tstrjoin.c string/ft_tstrlstlen.c string/ft_tstrnew.c string/ft_tstrtoupper.c string/get_tstrf.c string/get_tstrlstf.c string/print_tstrlst.c\
			tostring/ft_ctoa.c tostring/ft_ptoa.c tostring/ft_utoa.c tostring/ft_vtoa.c tostring/ft_xtoa.c \
			utils/ft_free_s.c \
			utils/ft_isdot.c utils/ft_isflag.c utils/ft_isnumfs.c utils/ft_isminus.c utils/ft_ispercent.c utils/ft_isplus.c utils/ft_isstrfs.c utils/ft_iszero.c \
			utils/ft_strlstlen.c utils/ft_strndup.c utils/ft_strtoupper.c 
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