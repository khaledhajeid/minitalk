# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kal-haj- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 13:32:13 by kal-haj-          #+#    #+#              #
#    Updated: 2025/09/23 13:32:15 by kal-haj-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME1 = client
NAME2 = server
BONUS_NAME1 = client_bonus
BONUS_NAME2 = server_bonus
LIBFT_DIR = libft
SRC = client.c \
	server.c \
	server_bonus.c \
	client_bonus.c
	
NAMELIB = $(LIBFT_DIR)/libft.a
OBJ	= $(SRC:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(NAMELIB) client.o
	$(CC) $(CFLAGS) client.o $(NAMELIB) -o $@

$(NAME2): $(NAMELIB) server.o
	$(CC) $(CFLAGS) server.o $(NAMELIB) -o $@

bonus: $(BONUS_NAME1) $(BONUS_NAME2)

$(BONUS_NAME1): $(NAMELIB) client_bonus.o
	$(CC) $(CFLAGS) client_bonus.o $(NAMELIB) -o $@

$(BONUS_NAME2): $(NAMELIB) server_bonus.o
	$(CC) $(CFLAGS) server_bonus.o $(NAMELIB) -o $@

$(NAMELIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME1) $(NAME2) $(BONUS_NAME1) $(BONUS_NAME2)

re: fclean all

.PHONY: all clean fclean re bonus

