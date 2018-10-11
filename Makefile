# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 15:48:04 by akurpas           #+#    #+#              #
#    Updated: 2018/10/09 18:27:13 by akurpas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf parse_conversion ft_itoa_base concat libft1 libft2 wchar \
		integer string char float getfloat \
		float2 float3 float_hex bonus color
SRC_FILES = $(addsuffix .c,$(FILES))

OBJ_FILES = $(addsuffix .o,$(FILES))

CFLAGS = -Wall -Wextra -Werror


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(SRC_FILES)
	gcc $(CFLAGS) -c $(SRC_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
