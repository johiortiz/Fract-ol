# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 01:52:56 by johyorti          #+#    #+#              #
#    Updated: 2025/06/16 22:45:01 by johyorti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
MLX42_DIR = MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42_LIB = $(MLX42_BUILD)/libmlx42.a
MLX42_INCLUDE = -I$(MLX42_DIR)/include
MLX_LIBS = -lglfw -ldl -lGL -lm -lX11 -lXrandr -lXi

all: $(NAME)

$(MLX42_LIB):
	@if [ ! -f $(MLX42_LIB) ]; then \
		echo "Building MLX42..."; \
		cd $(MLX42_DIR) && cmake -B build . && make -C build -j4; \
	fi

$(NAME): $(MLX42_LIB) $(OBJS)
	$(CC) $(OBJS) $(MLX42_LIB) $(MLX_LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX42_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re