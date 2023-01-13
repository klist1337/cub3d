# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 12:22:16 by eassofi           #+#    #+#              #
#    Updated: 2023/01/13 18:42:06 by eassofi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3d

LIBFT_DIRECTORY = libft/

LIBFT = $(LIBFT_DIRECTORY)libft.a

GAME_DIRECTORY = game/

GAME_FILE = floor.c          handle_key.c     init_image.c     main.c           minimap.c        raycast_dda.c    raycasting.c     raycasting_tex.c

GNL_DIRECTORY = get_next_line/

GNL_FILE = get_next_line.c get_next_line_utils.c

PARSING_DIRECTORY = parsing/

PARSING_FILE = color.c                cub3d_utils.c          cub3d_utils3.c         free_function.c        map_funct2.c           parsing.c\
               color2.c               cub3d_utils2.c         cub3d_utils4.c         init_player_position.c map_function.c         parsing_texture.c


HEADERS = -I includes

MLX = -L miniLibX -lmlx -framework OpenGL -framework AppKit

OBJS = $(addprefix $(OBJECTS_DIRECTORY)$(GAME_DIRECTORY), $(GAME_FILE:.c=.o)) $(addprefix $(OBJECTS_DIRECTORY)$(PARSING_DIRECTORY), $(PARSING_FILE:.c=.o)) $(addprefix $(OBJECTS_DIRECTORY)$(GNL_DIRECTORY), $(GNL_FILE:.c=.o))

SOURCES_DIRECTORY = src/

OBJECTS_DIRECTORY = obj/

FLAGS = -Wall -Wextra -Werror

FLAGS =  -g -fsanitize=address

CC = arch -x86_64 gcc

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

all:$(NAME)

$(LIBFT):
	@arch -x86_64 echo "make $(LIBFT)"
	@arch -x86_64 make -sC $(LIBFT_DIRECTORY)
	@arch -x86_64 make bonus -sC $(LIBFT_DIRECTORY)

$(OBJECTS_DIRECTORY):
	mkdir -p $@
	mkdir -p $(OBJECTS_DIRECTORY)$(GAME_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(PARSING_DIRECTORY)
	mkdir -p $(OBJECTS_DIRECTORY)$(GNL_DIRECTORY)



$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJS)
	$(CC) $(FLAGS) $(MLX) $(HEADERS) $(OBJS) $(LIBFT) -o $(NAME)



clean:
	rm -Rf $(OBJECTS_DIRECTORY)
	@make clean -sC $(LIBFT_DIRECTORY)


fclean: clean
	rm -f $(NAME)
	@make fclean -sC $(LIBFT_DIRECTORY)

re: fclean all

.PHONY: all clean fclean re
