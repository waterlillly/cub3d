CC = cc

CFLAGS = -Wextra -Wall -Werror 

NAME = cub3d

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

SRC_DIR = cub3D/src/

CFILES = $(addprefix $(SRC_DIR), \
		main.c check_file_line.c check_map.c \
		map.c open_and_init.c texture_color.c \
		utils.c \
)

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	($(MAKE) -C ./cub3D/lib)
	$(CC) $(CFLAGS) -o $@ $^ ./cub3D/lib/libft.a

clean:
	($(MAKE) -C ./cub3D/lib clean)
	rm -f $(OFILES)

fclean: clean
	($(MAKE) -C ./cub3D/lib fclean)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re