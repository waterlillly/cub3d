#include "../../cub3d.h"

static void validate_border(t_game *game);
static void validate_row_and_column(t_game *game);
static void validate_space(t_game *game);
static void validate_element(t_game *game);
static void validate_player(t_game *game);

void	is_valid_map(t_game *game)
{
	validate_border(game);
    validate_row_and_column(game);
    validate_space(game);
    validate_element(game);
    validate_player(game);
}

static void validate_border(t_game *game)
{
    puts("VALIDATING BORDER");
    (void)game;
}

static void validate_row_and_column(t_game *game)
{
    puts("VALIDATING ROW AND COLUMN");
    (void)game;
}

static void validate_space(t_game *game)
{
    puts("VALIDATING SPACE");
    (void)game;
}

static void validate_element(t_game *game)
{
    puts("VALIDATING ELEMENT");
    (void)game;
}

static void validate_player(t_game *game)
{
    puts("VALIDATING PLAYER");
    (void)game;
}