# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 16:28:38 by vvagapov          #+#    #+#              #
#    Updated: 2022/12/23 18:51:58 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	printf.c \
		print_char.c \
		print_str.c \
		print_int.c \
		print_unsigned.c \
		print_hex.c \
		print_ptr.c

LIBFT_DIR = libft

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	@cp $(LIBFT_DIR)/libft.a $@
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