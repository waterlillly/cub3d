#include "../../cub3d.h"

// static bool	check_len_and_newline(char *line, int len);

char	**split_line_into_words(char *line)
{
	char	*temp;
	char	**res;
	int		len;

	len = (int)ft_strlen(line) - 1;
	if (len <= 0)
		return (NULL);
	temp = ft_substr(line, 0, len);
	if (!temp)
		return (NULL);
	res = NULL;
	res = ft_split(temp, ' ');
	free(temp);
	if (!res)
		return (NULL);
	return (res);
}

// static bool	check_len_and_newline(char *line, int len)
// {
// 	if (len < 0 || line[len] != '\n')
// 		return (false);
// 	return (true);
// }
