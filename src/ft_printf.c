/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:57:11 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 08:54:38 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_check_format(const char format_specifier, va_list args)
{
	int	nbr_chars_written;

	nbr_chars_written = 0;
	if (format_specifier == 'c')
		nbr_chars_written += ft_print_char(args);
	else if (format_specifier == 's')
		nbr_chars_written += ft_print_string(args);
	else if (format_specifier == 'p')
		nbr_chars_written += ft_print_pointer(args);
	else if (format_specifier == 'd')
		nbr_chars_written += ft_print_decimal(args);
	else if (format_specifier == 'i')
		nbr_chars_written += ft_print_integer(args);
	else if (format_specifier == 'u')
		nbr_chars_written += ft_print_unsigned(args);
	else if (format_specifier == 'x')
		nbr_chars_written += ft_print_lower_hex(args);
	else if (format_specifier == 'X')
		nbr_chars_written += ft_print_upper_hex(args);
	else if (format_specifier == '%')
		nbr_chars_written += ft_print_modulo();
	return (nbr_chars_written);
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

	if (!format)
		return (0);
	nbr_chars_written = 0;
	va_start(args, format);
	nbr_chars_written = ft_vprintf(format, args);
	va_end(args);
	return (nbr_chars_written);
}	
