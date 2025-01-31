#include "../../cub3d.h"

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
	res = ft_split(temp, ' ');
	free(temp);
	if (!res)
		return (NULL);
	return (res);
}
