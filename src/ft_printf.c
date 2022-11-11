#include "../include/ft_printf.h"

int test_ft_printf(char *str, ...)
{
    int i;
    int j;
    int len_number;
    int len_width;
    struct s_flags *to_be_cut;
    va_list args;
    va_start(args, str);

    i = 0;
    j = 0;
    len_number = 0;
    len_width = 0;
    to_be_cut = ft_param_to_tab(ft_split(str));
    while (*str != '\0')
    {
        if(*str == '%' && *(str+1) == '%')
        {
            ft_putchar(*(str+1));
            str++;
            str++;
        }
        if(*str == '%' && *(str+1) != '%')
        {
            i = va_arg(args, int);
            if(to_be_cut[j].minus == 1)
                str++;
            if(to_be_cut[j].space == 1)
                str++;
            if(to_be_cut[j].zero == 1)
                str++; 
            if(to_be_cut[j].format == 'c' || to_be_cut[j].format == 's'
                    || to_be_cut[j].format == 'p' || to_be_cut[j].format == 'd'
                    ||to_be_cut[j].format == 'i' || to_be_cut[j].format == 'u'
                    ||to_be_cut[j].format == 'x' || to_be_cut[j].format == 'X')
                str++;
            len_number = ft_strlen(ft_itoa(to_be_cut[j].number));
            while(len_number >= 0)
            {
                str++;
                len_number--;
            }
            len_width = ft_strlen(ft_itoa(i)) - len_number;
            if(to_be_cut[j].plus == 1)
                len_width--;    
            if(to_be_cut[j].minus == 1)
            {
                if(to_be_cut[j].plus == 1)
                {
                    if(i >= 0)
                        ft_putchar('+');
                    str++;
                }
                ft_putnbr(i);
                while(len_width > 0)
                {
                    ft_putchar(' ');
                    len_width--;
                }
            }
            else if(to_be_cut[j].minus != 1)
            {
                while(len_width > 0)
                {
                    if(to_be_cut[j].zero == 1)
                        ft_putchar('0');
                    else
                        ft_putchar(' ');
                    len_width--;
                }
                if(to_be_cut[j].plus == 1)
                {
                    if(i >= 0)
                        ft_putchar('+');
                    str++;
                }
                ft_putnbr(i);
            }
            j++;
            i++;
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

/*
int main(void)
{
    int i,age,i_a,i_b,i_c;
    unsigned int unsigned_a;
    int hex_a;
    char letter;
    char *word;
    void *ptr;

    i = 0;
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
    char **test = ft_split("abcd%+-0123d%-+02d\n");
    printf("test[0]:\%s,test[1]:%s\n",test[0],test[1]);
    struct s_flags *to_be_cut;
    to_be_cut = ft_param_to_tab(test);
    while(to_be_cut[i].plus != -1)
    {
        printf("===========\n");
        printf("plus:  %d\n",to_be_cut[i].plus);
        printf("minus: %d\n",to_be_cut[i].minus);
        printf("space: %d\n",to_be_cut[i].space);
        printf("zero:  %d\n",to_be_cut[i].zero);
        printf("number:%d\n",to_be_cut[i].number);
        printf("format:%c\n",to_be_cut[i].format);
        i++;
    }
    //PLAN(Anass) : Fix All flags bugs,combine test_ft_printf with ft_printf,
    //Treat floating numbers, Add bonus part
    ft_putstr("It should print:\n");
    printf("%05d\n",age);
    ft_putstr("It is printing:\n");
    test_ft_printf("%05d\n",age);
}
*/
