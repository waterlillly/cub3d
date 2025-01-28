int ft_strlen_skip_space(char *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0'){
        i++;
    }
    while (i > j)
    {
        if (str[i] == ' ' || str[i] == '\n')
            i--;
        else
            break;
    }
    return (i);
}