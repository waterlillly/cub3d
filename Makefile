CC = cc

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -pthread

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
		raycasting2.c doors.c mlx_handle_input.c \
) $(addprefix $(UTILS_DIR), \
		init.c append_line_to_map.c validate_and_set_rgb.c \
		only_digits.c max_line_len.c validate_color_element.c \
		split_line_into_words.c is_line_empty.c validate_texture_element.c \
		is_texture_identifier.c is_color_identifier.c \
		ft_strlen_skip_space.c get_player_orientation.c \
		is_rgb_valid_format.c split_map_into_grid.c \
) $(addprefix $(PARSE_DIR), \
		args_handler.c validate_game.c \
		parse_map_file.c validate_input_file.c \
		is_valid_map.c validate_border.c \
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