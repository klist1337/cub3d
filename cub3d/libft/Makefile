# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 20:51:00 by eassofi           #+#    #+#              #
#    Updated: 2022/10/15 22:00:45 by eassofi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c\
	   ft_memcmp.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c\
	   ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	   ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c\
	   ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c\
	   ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstadd_back_bonus.c\
       ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c\
	   ft_lstsize_bonus.c ft_lstiter_bonus.c\

OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "\033[0;32mDone !"
.c.o:
	@echo "Compiling...."
	@$(CC) $(CFLAGS) -c $(SRCS)

clean:
		@echo "\033[0;31mCleaning..."
		@$(RM) $(OBJS)
		
fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;31mCleaning..."

re: fclean all
