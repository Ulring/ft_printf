#include <stdio.h>
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
	while (str[i] != '\0')
	{
		if(str[i] == '%' && str[i+1] == '%')
		{
			ft_putchar(str[i+1]);
			str++;
			str++;
		}
		if(str[i] == '%' && str[i+1] != '%')
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

void check_upper_hex(char **str, va_list args)
{
	if(**(str+1) == 'X')
	{
		long num;
		num = va_arg(args, long);
		ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","0123456789ABCDEF"));
		(*str) += 2;
	}
}
void check_lower_hex(char **str, va_list args)
{
	if(**(str+1) == 'x')
	{
		long num;
		num = va_arg(args, long);
		ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","0123456789abcdef"));
		(*str) += 2;
	}
}
void check_unsigned(char **str, va_list args)
{
	if(**(str+1) == 'u')
	{
		unsigned int num;
		num = va_arg(args, unsigned int);
		ft_unsigned_putnbr(num);
		(*str) += 2;
	}
}

void check_integer(char **str, va_list args)
{
	if(**(str+1) == 'i')
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
		(*str) += 2;
	}
}

void check_pointer(char **str, va_list args)
{
	if(**(str+1) == 'p')
	{
		long num;
		num = va_arg(args, long);
		ft_putstr("0x");
		ft_putstr(ft_convert_base(ft_itoa(num),"0123456789","0123456789abcdef"));
		(*str) += 2;
	}
}

void check_string(char **str, va_list args)
{
	char *string;
	if(**(str+1) == 's')
	{
		string = va_arg(args, char*);
		ft_putstr(string);
		(*str) += 2;
	}
}

void check_char(char **str, va_list args)
{
	int j = 0;
	if(**(str+1) == 'c')
	{
		j = va_arg(args, int);
		ft_putchar(j);
		(*str) += 2;
	}
}
void check_decimal(char **str, va_list args)
{
	int j = 0;
	if(**(str+1) == 'd')
	{
		j = va_arg(args, int);
		ft_putnbr(j);
		(*str) += 2;
	}
}

void check_modulo(char **str)
{
	if(**(str+1) == '%')
	{
		ft_putchar(**(str+1));
		(*str) += 2;
	} 
}

int ft_printf(const char *str, ...)
{
	int i, j;
	char* string;

	i = 0;
	j = 0;
	va_list args;
	va_start(args, str);

	string = ft_strdup(str);
	while (*string != '\0')
	{
		printf("%c",*string);
		if(*string == '%')
		{
			check_modulo(&string);
			check_decimal(&string, args);
			check_char(&string, args);
			check_string(&string, args);
			check_pointer(&string, args);
			check_integer(&string, args);
			check_unsigned(&string, args);
			check_lower_hex(&string, args);
			check_upper_hex(&string, args);
		}
		else
		{
			ft_putchar(*string);
			string++;
		}
	}
	va_end(args);
	return (1);
}
