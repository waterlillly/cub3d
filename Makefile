CC = cc

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

SRC_DIR = src/
PARSE_DIR = src/parsing/
UTILS_DIR = src/utils/
MATH_DIR = src/math/

CFILES = $(addprefix $(SRC_DIR), \
		main.c \
) $(addprefix $(MATH_DIR), \
		init.c mlx_events.c pixels.c \
		exit.c movement.c utils.c rotation.c \
		raycasting.c minimap.c checking.c \
		raycasting2.c doors.c \
) $(addprefix $(UTILS_DIR), \
		strappend.c m_split.c error.c \
		ascii_print.c init.c \
) $(addprefix $(PARSE_DIR), \
		args_handler.c validator.c read_file.c \
		get_whole_file.c file_data.c add_texture.c \
		add_color.c map_crating.c map_validator.c \
		check_map_elements.c \
)

# check_file_line.c check_map.c \
# map.c open_and_init.c texture_color.c utils.c \

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	($(MAKE) -C ./lib)
	$(CC) $(OFILES) ./lib/libft.a -lmlx -lXext -lX11 -lm -o $(NAME)
#for @school: $(CC) $(OFILES) ./lib/libft.a -lmlx -lXext -lX11 -lm -o $(NAME)
#for @home: $(CC) $(OFILES) ./lib/libft.a ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -o $(NAME)
clean:
	($(MAKE) -C ./lib clean)
	rm -f $(OFILES)

fclean: clean
	($(MAKE) -C ./lib fclean)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re