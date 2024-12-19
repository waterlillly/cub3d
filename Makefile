CC = cc

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

MATH_DIR = cub3d/src/math/
SRC_DIR = cub3d/src/

CFILES = $(addprefix $(SRC_DIR), \
		main.c check_file_line.c check_map.c \
		map.c open_and_init.c texture_color.c \
		utils.c \
), $(addprefix $(MATH_DIR), \
		math/vec.c math/vec2.c math/vec3.c \
		math/vec4.c math/mat4.c \
)

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	($(MAKE) -C ./lib)
	$(CC) $(OFILES) ./lib/libft.a -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	($(MAKE) -C ./lib clean)
	rm -f $(OFILES)

fclean: clean
	($(MAKE) -C ./lib fclean)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re