#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "includes/ft.h"

/*struct s_flags *ft_param_to_tab(char** str)
{
    int				i;
    t_flags		*struct_flag;

    i = 0;
    if ((struct_flag = (t_flags *)malloc(sizeof(t_flags) * (sizeof(int) * 5 + 1))) == ((void *)0))
        return ((void *)0);
    while (i < ac)
    {
        struct_flag[i].plus = 1;
        struct_flag[i].minus = 1;
        struct_flag[i].zero = 1;
        struct_flag[i].space = 1;
        struct_flag[i].number = 1;
        i++;
    }
    struct_flag[i].plus = 0;
    return (struct_flag);
}*/

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
            ft_unsigned_putnbr(num);
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

    //ft_putchar('\n');
    //ft_putstr("==>Testing the width option:\n");
    //printf("%5.3d\n", 42);
    //char **test = ft_split("abcd%1234d%5678x\n");
    //printf("%s,%s",test[0],test[1]);
}
