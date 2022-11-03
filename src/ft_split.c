#include "../include/ft.h"
#include <stdlib.h>

int	word_count(char *str)
{
    int	i;
    int	flag;
    int	count;

    i = 0;
    flag = 0;
    count = 0;
    if (str[i] == '\0')
        return (0);
    while(str[i] != '\0')
    {
        if(str[i] == '%')
        {
            flag = 1;
        }
        if(flag == 1 && (str[i] == 'd' || str[i] == 'c' || str[i] == 's'
                    || str[i] == 'p' || str[i] == 'i' || str[i] == 'u' || str[i] == 'x'
                    || str[i] == 'X'))
        {
            count++;
            flag = 0;
        }
        i++;
    }
    return (count);
}

int	word_length(char *str, int i)
{
    int	len;

    len = 1;
    while(str[i] != 'd' && str[i] != 'c' && str[i] != 's'
            && str[i] != 'p' && str[i] != 'i' && str[i] != 'u' && str[i] != 'x'
            && str[i] != 'X')
    {
        i++;
        len++;
    }
    return(len);
}

char	**ft_split(char *str)
{
    char	**array_to_return;
    int		i;
    int		j;
    int		k;
    int		counted_words;

    i = 0;
    j = 0;
    counted_words = word_count(str);
    array_to_return = (char **)malloc(sizeof (char *) * counted_words + 1);
    while (str[i] != '\0' && j < counted_words)
    {
        k = 0;
        while(str[i] != '%')
        {
            i++;
        }
        array_to_return[j] = (char *)malloc(sizeof(char) * word_length(str, i));
        while(str[i] != 'd' && str[i] != 'c' && str[i] != 's'
            && str[i] != 'p' && str[i] != 'i' && str[i] != 'u' && str[i] != 'x'
                && str[i] != 'X' && str[i] != '\0'){
            array_to_return[j][k++] = str[++i];
        }
        array_to_return[j][k] = '\0';
        j++;
    }
    array_to_return[j] = 0;
    return (array_to_return);
}
