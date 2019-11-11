# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:29:46 by sjamie            #+#    #+#              #
#    Updated: 2019/11/09 15:50:41 by matruman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= gcc
HEADER			= includes/
CFLAGS			=  -I $(HEADER)

SRC				=	src/ft_itoa_base.c\
					src/ft_printf.c\
					src/get_format.c\
					src/get_format_list.c\
					src/helps.c\
					src/print_conv_di.c\
					src/print_format.c\
					src/print_conv_pouxx.c\
					src/print_conv_cp.c\
					src/print_conv_s.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): lib $(OBJ)
	#$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	ar rc $(NAME) libft/*.o $(OBJ)
	ranlib $(NAME)

lib:
	make -C libft

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
