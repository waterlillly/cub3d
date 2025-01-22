CC = cc

NAME = cub3d

#MAKEFLAGS = --jobs=16 # Remove for eval

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

SRC_DIR = src/

CFILES = $(addprefix $(SRC_DIR), \
		main.c args_handler.c validator.c read_file.c strappend.c \
		init.c msimic_split.c error.c get_whole_file.c file_data.c add_texture.c \
		add_color.c map_crating.c map_validator.c check_map_elements.c ascii_print.c \
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