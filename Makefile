# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 19:29:46 by sjamie            #+#    #+#              #
#    Updated: 2019/11/08 16:48:42 by matruman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_printf

CC				= gcc
HEADER			= includes/
CFLAGS			=  -I $(HEADER)

SRC				=	src/ft_itoa_base.c\
					src/ft_printf.c\
					src/get_format.c\
					src/get_format_list.c\
					src/helps.c\
					src/main.c\
					src/print_conv_di.c\
					src/print_format.c\
					src/print_conv_ouxX.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

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
