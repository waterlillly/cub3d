#include "../../cub3d.h"

char	**split_line_into_words(char *line, t_game *game)
{
	char	*temp;
	char	**res;
	int		len;

	len = ft_strlen(line) - 1;
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
	return (res);
}