#include "../cub3d.h"

char	*ft_strappend(char **s1, const char *s2)
{
	printf("ft_strappend\n");
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !*s1 || !s2)
		return (NULL);
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, len1 + 1);
	ft_strlcat(str, s2, len1 + len2 + 1);
	free(*s1);
	return (str);
}