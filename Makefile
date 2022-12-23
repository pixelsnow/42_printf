# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 16:28:38 by vvagapov          #+#    #+#              #
#    Updated: 2022/12/23 20:14:47 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c \
		print_char.c \
		print_str.c \
		print_int.c \
		print_unsigned.c \
		print_hex.c \
		print_ptr.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	@cp ./libft/libft.a $@
	@ar -ruvcs $@ $^

%.o: %.c
	@cc $(FLAGS) -c -o $@ $^

clean:
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re