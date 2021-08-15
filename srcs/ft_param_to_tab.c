#include "../includes/ft.h"
#include <stdlib.h>

int detect_nbr(char *str)
{
    int i;
    int j;
    int flag;
    int len;
    char *final_str;

    i = 0;
    j = 0;
    flag = 0;
    len = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '0' && flag == 0)
        {
            i++;
            flag = 1;
        }
        if(str[i] >= '0' && str[i] <= '9')
        {
            len++;
            i++;
        }
        else
        {
            str++;
        }
    }
    i = 0;
    final_str = malloc(sizeof(char) * len + 1); 
    while(str[i] != '\0')
    {
        if(str[i] == '0' && flag == 0)
        {
            i++;
            flag = 1;
        }
        if(str[i] >= '0' && str[i] <= '9')
        {
            final_str[j] = str[i];
            j++;
            i++;
        }
        else
        {
            str++;
        }
    }
    final_str[j] = '\0';
    return(ft_atoi(final_str));
}

int ft_is_flag(char to_find, char *str)
{
    while (*str)
    {
        if (to_find == *str++)
            return (1);
    }
    return (0);
}

struct s_flags *ft_param_to_tab(char** str)
{
    int				i;
    t_flags		*struct_flag;

    i = 0;
    if ((struct_flag = (t_flags *)malloc(sizeof(t_flags) * (sizeof(int) * 6))) == ((void *)0))
        return ((void *)0);
    while (str[i] != 0)
    {
        if(ft_is_flag('+',str[i]))
            struct_flag[i].plus = 1;
        if(ft_is_flag('-',str[i]))
            struct_flag[i].minus = 1;
        if(ft_is_flag(' ',str[i]))
            struct_flag[i].space = 1;
        if(ft_is_flag('0',str[i]))
            struct_flag[i].zero = 1;
        struct_flag[i].number = detect_nbr(str[i]);
        i++;
    }
    struct_flag[i].plus = -1;
    struct_flag[i].minus = -1;
    struct_flag[i].space = -1;
    struct_flag[i].zero = -1;
    struct_flag[i].number = -1;
    return (struct_flag);
}