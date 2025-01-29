#include "../../cub3d.h"

// static bool rgb_format(char **str);
static bool check_len_and_newline(char *line, int len);

char	**split_line_into_words(char *line)
{
	char	*temp;
	char	**res;
	int		len;

	len = ft_strlen(line) - 1;
	if (!check_len_and_newline(line, len))
		return (NULL);
	temp = ft_substr(line, 0, len);
	if (!temp)
		return (NULL);
	res = NULL;
	res = ft_split(temp, ' ');
	free(temp);
	if (!res)
		return (NULL);
	// if (!rgb_format(res))
	// 	return (ft_free_2d(res), NULL);
	return (res);
}

static bool check_len_and_newline(char *line, int len)
{
	if (len < 0 || line[len] != '\n')
		return (false);
	return (true);
}

// static bool rgb_format(char **str)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	ft_print_array(str);
// 	while (str[++i])
// 	{
// 		if (ft_strchr(str[0], 'C') || ft_strchr(str[0], 'F'))
// 		{
// 			j = -1;
// 			while (str[1][++j])
// 			{
// 				if (!is_rgb_valid_format(str[1]))
// 					return (false);
// 			}
// 		}
// 	}
// 	return (true);
// }
