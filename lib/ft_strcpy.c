#include "libft.h"

char	*ft_strcpy(char *src, int start)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src || start >= (int)ft_strlen(src))
		return (NULL);
	dest = ft_calloc(ft_strlen(src) - start + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (src[start])
		dest[i++] = src[start++];
	return (dest);
}

