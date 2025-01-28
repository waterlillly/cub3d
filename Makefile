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
		main.c maps.c \
) $(addprefix $(MATH_DIR), \
		init.c mlx_events.c pixels.c \
		exit.c movement.c utils.c rotation.c \
		raycasting.c minimap.c checking.c \
		raycasting2.c doors.c \
) $(addprefix $(UTILS_DIR), \
		init.c \
		only_digits.c max_line_len.c \
		split_line_into_words.c is_line_empty.c \
		is_texture_identifier.c is_color_identifier.c \
		ft_strlen_skip_space.c get_player_orientation.c \
) $(addprefix $(PARSE_DIR), \
		args_handler.c validate_game.c \
		parse_map_file.c \
		map_validator.c \
		is_valid_map.c \
)

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