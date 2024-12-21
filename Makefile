CC = cc

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

SRC_DIR = src/

CFILES = $(addprefix $(SRC_DIR), \
		main.c args_handler.c map_validator.c read_file.c strappend.c \
)

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	($(MAKE) -C ./lib)
	$(CC) $(OFILES) ./lib/libft.a -o $(NAME)

clean:
	($(MAKE) -C ./lib clean)
	rm -f $(OFILES)

fclean: clean
	($(MAKE) -C ./lib fclean)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re