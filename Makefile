# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 01:52:56 by johyorti          #+#    #+#              #
#    Updated: 2025/06/06 12:50:22 by johyorti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = $(wildcard src/*.c) 
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g


LIBMLX_PATH = ./MLX42 

MLX_FLAGS = -I$(LIBMLX_PATH)/include -L$(LIBMLX_PATH)/build -lmlx42 -lglfw -L/usr/lib -lX11 -lm -pthread

LIBFT_PATH = libft
LIBFT_A = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) # Esto compilará tu libft primero (si la usas)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean # Limpia también la libft (si la usas)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean # Limpia también la libft (si la usas)

re: fclean all

.PHONY: all clean fclean re