/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:57:11 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 22:30:09 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

//static	int	ft_vprintf(const char *format, va_list args);
//static	int ft_check_format(const char format_specifier, va_list args);

/*
   int	test_ft_printf(char *str, ...)
   {
   int		i;
   int		j;
   int		len_number;
   int		len_width;
   struct	s_flags	*to_be_cut;
   va_list	args;
   va_start(args, str);

   i = 0;
   j = 0;
   len_number = 0;
   len_width = 0;
   to_be_cut = ft_param_to_tab(ft_split(str));
   while (str[i] != '\0')
   {
   if (str[i] == '%' && str[i + 1] == '%')
   {
   ft_putchar(str[i + 1]);
   str++;
   str++;
   }
   if (str[i] == '%' && str[i + 1] != '%')
   {
   i = va_arg(args, int);
   if (to_be_cut[j].minus == 1)
   str++;
   if (to_be_cut[j].space == 1)
   str++;
   if (to_be_cut[j].zero == 1)
   str++;
   if (to_be_cut[j].format == 'c' || to_be_cut[j].format == 's'\
   || to_be_cut[j].format == 'p' || to_be_cut[j].format == 'd'\
   ||to_be_cut[j].format == 'i' || to_be_cut[j].format == 'u'\
   ||to_be_cut[j].format == 'x' || to_be_cut[j].format == 'X')
   str++;
   len_number = ft_strlen(ft_itoa(to_be_cut[j].number));
   while (len_number >= 0)
   {
   str++;
   len_number--;
   }
   len_width = ft_strlen(ft_itoa(i)) - len_number;
   if (to_be_cut[j].plus == 1)
   len_width--;
   if (to_be_cut[j].minus == 1)
   {
   if (to_be_cut[j].plus == 1)
   {
   if (i >= 0)
   ft_putchar('+');
   str++;
   }
   ft_putnbr(i);
   while (len_width > 0)
   {
   ft_putchar(' ');
   len_width--;
   }
   }
   else if (to_be_cut[j].minus != 1)
   {
   while (len_width > 0)
   {
   if (to_be_cut[j].zero == 1)
   ft_putchar('0');
   else
   ft_putchar(' ');
   len_width--;
}
if (to_be_cut[j].plus == 1)
{
	if (i >= 0)
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
*/

static	int ft_check_format(const char format_specifier, va_list args)
{
	int	nbr_chars_written;

	nbr_chars_written = 0;
	if(format_specifier == 'c')
		nbr_chars_written += ft_print_char(args);
	else if(format_specifier == 's')
		nbr_chars_written += ft_print_char(args);
	return (nbr_chars_written);
	/*
	   ft_check_modulo(&string);
	   ft_check_decimal(&string, args);
	   ft_check_char(&string, args);
	   ft_check_string(&string, args);
	   ft_check_pointer(&string, args);
	   ft_check_integer(&string, args);
	   ft_check_unsigned(&string, args);
	   ft_check_lower_hex(&string, args);
	   ft_check_upper_hex(&string, args);
	   */
}

static	int	ft_vprintf(const char *format, va_list args)
{
	int	nbr_chars_written;

	nbr_chars_written = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			nbr_chars_written += ft_check_format(*(format + 1), args);
			format += 2;
		}
		else
		{
			ft_putchar(*format);
			nbr_chars_written++;
			format++;
		}
	}
	return (nbr_chars_written);
}


int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		nbr_chars_written;

	if(!format)
		return (0);
	nbr_chars_written = 0;
	va_start(args, format);
	nbr_chars_written = ft_vprintf(format, args);
	va_end(args);
	return (nbr_chars_written);
}	
