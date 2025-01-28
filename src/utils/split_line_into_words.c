#include "../../cub3d.h"

static void rgb_format(char **str, t_game *game);
static void check_len_and_newline(char *line, int len, t_game *game);

char	**split_line_into_words(char *line, t_game *game)
{
	char	*temp;
	char	**res;
	int		len;

	len = ft_strlen(line) - 1;
	check_len_and_newline(line, len, game);
	temp = ft_substr(line, 0, len);//maybe use strtrim
	if (!temp)
	{
		(free(line), line = NULL);
		exit_failure("substr failed", game);
	}
	res = ft_split(temp, ' ');
	(free(temp), temp = NULL);
	if (!res)
		exit_failure("split failed", game);
	rgb_format(res, game);
	return (res);
}

static void check_len_and_newline(char *line, int len, t_game *game)
{
	if (len < 0)
	{
		(free(line), line = NULL);
		exit_failure("Invalid line", game);
	}
	if (line[len] != '\n')
	{
		(free(line), line = NULL);
		exit_failure("Invalid line", game);
	}
}

static void rgb_format(char **str, t_game *game)
{
	int i;
	int j;

	i = -1;
	while (str[++i]){
		if (ft_strchr(str[0], 'C') || ft_strchr(str[0], 'F'))
		{
			j = -1;
			while (str[1][++j])
				is_rgb_valid_format(str[1], game);
		}
	}
}
