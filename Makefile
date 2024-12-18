CC = cc

CFLAGS = -Wextra -Wall -Werror 

NAME = cub3d

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = main.c check_file_line.c check_map.c map.c open_and_init.c texture_color.c utils.c
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