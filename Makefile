# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 16:33:04 by pablogon          #+#    #+#              #
#    Updated: 2024/08/22 20:35:13 by pablogon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= pipex

CFLAGS:= -Wall -Werror -Wextra \
	#-g -fsanitize=address,undefined \
	#-Wunreachable-code -Ofast

LIBFT_DIR = ./Libft

LIBFT = $(LIBFT_DIR)/libft.a

HEADERS := -I$(LIBFT)

SRCS	:= src/error.c \
src/get_paths.c \
src/main.c \
src/pipex.c \
src/utils.c \

OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)
libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) $(LINK) -o $(NAME)
	@echo "Compiling Pipex..."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re, libft