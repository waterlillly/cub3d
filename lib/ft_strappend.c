#include "libft.h"

char	*ft_strappend(char **s1, const char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	if (*s1)
		len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	if (*s1)
	{
		ft_memcpy(new_str, *s1, len1);
		free(*s1);
	}
	ft_memcpy(new_str + len1, s2, len2);
	new_str[len1 + len2] = '\0';
	*s1 = new_str;
	return (*s1);
}
