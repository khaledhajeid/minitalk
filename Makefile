
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME1 = client
NAME2 = server
LIBFT_DIR = libft
NAMELIB = $(LIBFT_DIR)/libft.a

all: $(NAME1) $(NAME2)

$(NAME1): $(NAMELIB)
	$(CC) $(CFLAGS) client.c $(NAMELIB) -o $@

$(NAME2): $(NAMELIB)
	$(CC) $(CFLAGS) server.c $(NAMELIB) -o $@


$(NAMELIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME1) $(NAME2)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re

