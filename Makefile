CC = cc

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

MATH_DIR = src/math/
SRC_DIR = src/

CFILES = $(addprefix $(SRC_DIR), \
		main.c \
) $(addprefix $(MATH_DIR), \
		init_cub.c pixel.c \
		player.c exit.c \
)

#check_file_line.c check_map.c \
		map.c open_and_init.c texture_color.c \
		utils.c \

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	($(MAKE) -C ./lib)
	$(CC) $(OFILES) ./lib/libft.a ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -o $(NAME)
#for @school: use ./lib/libft.a -lmlx -lXext -lX11 -lm -o

clean:
	($(MAKE) -C ./lib clean)
	rm -f $(OFILES)

fclean: clean
	($(MAKE) -C ./lib fclean)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re