CC = cc

CFLAGS = -Wextra -Wall -Werror 

NAME = cub3d

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = main.c src/check_file_line.c src/check_map.c src/map.c src/open_and_init.c src/texture_color.c src/utils.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	($(MAKE) -C ./libft)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

clean:
	($(MAKE) -C ./libft clean)
	rm -f $(OFILES)

fclean: clean
	($(MAKE) -C ./libft fclean)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re