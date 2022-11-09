# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 12:22:16 by eassofi           #+#    #+#              #
#    Updated: 2022/10/15 21:58:55 by eassofi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = include src/game src/parsing get_next_line
NAME = cube3d

SRC = color.c\
color2.c\
cub3d_utils.c\
cub3d_utils2.c\
cub3d_utils3.c\
cub3d_utils4.c\
init_player_position.c\
map_funct2.c\
map_function.c\
parsing.c\
free_function.c\
parsing_texture.c\
main.c\
raycasting.c\
handle_key.c\
floor.c\
raycast_dda.c\
raycasting_tex.c\
init_image.c\
get_next_line.c\
get_next_line_utils.c\

CC = cc

CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)
INC = cube3d.h
LIB = libft.a
FSAN = -g 
INC = ../include

all: $(NAME)

$(NAME): $(OBJ)
				@Make -C ./libft
				@mv ./libft/libft.a ./
				@$(CC) $(CFLAGS) $(FSAN) $(BUFFER) $(LIB) $(LIBFLAGS) $(OBJ) -o $@
				@echo "THE GAME IS READY, YOU CAN RUN IT"
				@echo "Usage ./cub3d [map.cub]"

%.o: %.c 
		@$(CC) $(CFLAGS) -I $(INC) -c $<

clean :
				@rm -rf *.o
fclean : clean
				@echo "Cleaning..."
				@rm -rf libft.a
				@rm -rf $(NAME)
				@Make fclean -C ./libft
re: fclean all