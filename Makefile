CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME1 = client
NAME2 = server
LIBFT_DIR = libft
SRC = client.c \
	server.c
	
NAMELIB = $(LIBFT_DIR)/libft.a
OBJ	= $(SRC:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(NAMELIB) $(OBJ)
	$(CC) $(CFLAGS) -c client.c -o client.o
	$(CC) $(CFLAGS) client.c $(NAMELIB) -o $@

$(NAME2): $(NAMELIB) $(OBJ)
	$(CC) $(CFLAGS) -c server.c -o server.o
	$(CC) $(CFLAGS) server.c $(NAMELIB) -o $@


$(NAMELIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re

