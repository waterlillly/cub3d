int	ft_strlen_skip_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (i > j)
	{
		if (str[i] == ' ' || str[i] == '\n')
			i--;
		else
			break ;
	}
	return (i);
}
