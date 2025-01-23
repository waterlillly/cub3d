#include "../../cub3d.h"

// static char *texture_path(char *line, int column)
// {
//     int row;
//     int length;
//     char *path_to_texture;

//     while (line[column] && (line[column] == ' ' || line[column] == '\t'))
//         column++;
//     length = column;
//     while (line[length] && (line[length] != ' ' && line[length] != '\t'))
//         length++;
//     path_to_texture = malloc(sizeof(char) * (length - column + 1));
//     if (!path_to_texture)
//         return (NULL);
//     row = 0;
//     while (line[column] && (line[length] != ' ' && line[length] != '\t' && line[length] != '\n'))
//         path_to_texture[row++] = line[column++];
//     path_to_texture[row] = '\0';
//     while (line[column] && (line[column] == ' ' || line[column] == '\t'))
//         column++;
//     if (line[column] && line[column] != '\n')
//     {
//         free(path_to_texture);
//         path_to_texture = NULL;
//     }
//     return (path_to_texture);
// }

static void	get_texture_path(t_game *game, int tex_num, char *line)
{
	char **split;

	split = NULL;
	split = ft_split(line, ' ');
	if (!split)
		exit_failure("wrong texture", game);
	if (!split[0] || !split[1] || split[2])
	{
		ft_free_2d(split);
		exit_failure("also wrong texture", game);
	}
	game->textures[tex_num].name = ft_strtrim(split[1], "\n");
	ft_free_2d(split);
	if (!game->textures[tex_num].name)
		exit_failure("ft_strtrim failed", game);
}

int add_texture(t_game *game, char *line, int column)
{
    if (line[column + 2] && ascii_print(line[column + 2]))
        return (ERR);
    if (line[column] == 'N' && line[column + 1] == 'O')
        get_texture_path(game, 0, line);
    else if (line[column] == 'S' && line[column + 1] == 'O')
        get_texture_path(game, 1, line);
    else if (line[column] == 'W' && line[column + 1] == 'E')
        get_texture_path(game, 2, line);
    else if (line[column] == 'E' && line[column + 1] == 'A')
        get_texture_path(game, 3, line);
	// if (line[column] == 'N' && line[column + 1] == 'O')
    //     game->textures[NORTH].name = texture_path(line, column + 2);
    // else if (line[column] == 'S' && line[column + 1] == 'O')
    //     game->textures[SOUTH].name = texture_path(line, column + 2);
    // else if (line[column] == 'W' && line[column + 1] == 'E')
    //     game->textures[WEST].name = texture_path(line, column + 2);
    // else if (line[column] == 'E' && line[column + 1] == 'A')
    //     game->textures[EAST].name = texture_path(line, column + 2);
    else
        return (ERR);
    return (SUCC);
}