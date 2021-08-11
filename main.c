#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);
char **ft_split(char *str);

void ft_putstr(char *str)
{
    while(*str)
    {
        write(1, str,1);
        str++;
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char		*ft_strcpy(char *dst, const char *src)
{
    size_t	i;

    i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
        dst[i] = '\0';
    }
    return (dst);
}

void		ft_putnbr(int n)
{
    if (n == -2147483648)
        ft_putstr("-2147483648");
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(-n);
    }
    else if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
    else
        ft_putchar(n + '0');
}

void		unsigned_ft_putnbr(unsigned int n)
{
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
    else
        ft_putchar(n + '0');
}


size_t		ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
    int		i;
    int		j;
    char	*str;
    i = 0;
    j = 0;
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (str == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

char		*ft_itoa(long n)
{
    char	*str;

    if (!(str = (char *)malloc(sizeof(char) * 2)))
        return (NULL);
    //if (n == -2147483648)
    //	return (ft_strcpy(str, "-2147483648"));
    if (n < 0)
    {
        str[0] = '-';
        str[1] = '\0';
        str = ft_strjoin(str, ft_itoa(-n));
    }
    else if (n >= 10)
        str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
    else if (n < 10 && n >= 0)
    {
        str[0] = n + '0';
        str[1] = '\0';
    }
    return (str);
}

int ft_printf(const char *str, ...)
{
    int i;
    char* string;

    i = 0;
    va_list args;
    va_start(args, str);
    while (*str != '\0')
    {
        if(*str == '%' && *(str+1) == '%')
        {
            ft_putchar(*(str+1));
            str++;
            str++;
        } 
        else if(*str == '%' && *(str+1) == 'd')
        {
            i = va_arg(args, int);
            ft_putnbr(i);
            str++;
            str++;
        }
        else if(*str == '%' && *(str+1) == 'c')
        {
            i = va_arg(args, int);
            ft_putchar(i);
            str++;
            str++;
        }
        else if(*str == '%' && *(str+1) == 's')
        {
            string = va_arg(args, char*);
            ft_putstr(string);
            str++;
            str++;
        }
        else if(*str == '%' && *(str+1) == 'p')
        {
            long num;
            num = va_arg(args, long);
            ft_putstr("0x");
            ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","0123456789abcdef"));
            str++;
            str++;
        }
        else if(*str == '%' && *(str+1) == 'i')
        {
            long num;
            num = va_arg(args, long);
            char *str_i = ft_itoa(num);
            if(str_i[0] == '0')
                ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","01234567"));
            else if(str_i[0] == '0' && str_i[1] == 'x')
            {
                ft_putstr("0x");
                ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","01234567"));
            }
            else
                ft_putnbr(num);
            str++;
            str++;
        }
        else if(*str == '%' && *(str+1) == 'u')
        {
            unsigned int num;
            num = va_arg(args, unsigned int);
            unsigned_ft_putnbr(num);
            str++;
            str++;
        }
        else if(*str == '%' && *(str+1) == 'x')
        {
            long num;
            num = va_arg(args, long);
            ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","0123456789abcdef"));
            str++;
            str++;
        }
        else if(*str == '%' && *(str+1) == 'X')
        {
            long num;
            num = va_arg(args, long);
            ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","0123456789ABCDEF"));
            str++;
            str++;
        }
        else
        {
            ft_putchar(*str);
            str++;
        }
    }
    va_end(args);
    return (1);
}

int main(void)
{
    /*
       int age,i_a,i_b,i_c;
       unsigned int unsigned_a;
       int hex_a;
       char letter;
       char *word;
       void *ptr;

       age = 21;
       i_a = 12; 
       i_b = 012;
       i_c = 0x12;
       hex_a = 696969;
       unsigned_a = -1;
       letter = 'I';
       word = "old";
       ptr = &age;

       ft_putchar('\n');
       ft_putstr("==>Testing formats specifications:\n"); 
       ft_printf("%c am %d years %s.\n", letter, age, word);
       printf(   "%c am %d years %s.\n", letter, age, word);
       ft_printf("The address of ptr is: %p.\n", ptr);
       printf(   "The address of ptr is: %p.\n", ptr);
       ft_printf("%%i of decimal:%i,%%i of octal:%i,%%i of hexadecimal:%i.\n",i_a,i_b,i_c);
       printf(   "%%i of decimal:%i,%%i of octal:%i,%%i of hexadecimal:%i.\n",i_a,i_b,i_c);
       ft_printf("%%u of unsigned decimal is:%u.\n",unsigned_a);
       printf(   "%%u of unsigned decimal is:%u.\n",unsigned_a);
       ft_printf("The hexadecimal of %d is:%x/%X\n",hex_a,hex_a,hex_a);
       printf(   "The hexadecimal of %d is:%x/%X\n",hex_a,hex_a,hex_a);

       ft_putchar('\n');
       ft_putstr("==>Testing escaping:\n");
       ft_printf("I \\ \' \" %%  am very old.\n");
       printf(   "I \\ \' \" %%  am very old.\n");

       ft_putchar('\n');
       ft_putstr("==>Testing special characters:\n");
       ft_printf("\a^\b^\f^\r^\t^\v^\n");
       printf(   "\a^\b^\f^\r^\t^\v^\n");

       ft_putchar('\n');
       ft_putstr("==>Testing the width option:\n");
       printf("%5.3d", 42);
       */
    char **test = ft_split("abcd%1234d%5678x\n");
    printf("%s,%s",test[0],test[1]);
}
