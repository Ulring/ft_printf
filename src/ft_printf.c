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

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	char	*string;
	va_list	args;

	i = 0;
	j = 0;
	va_start(args, str);
	string = ft_strdup(str);
	while (*string != '\0')
	{
		if (*string != '%')
		{
			ft_putchar(*string);
			string++;
		}
		else if (*string == '%')
		{
			ft_check_modulo(&string);
			ft_check_decimal(&string, args);
			ft_check_char(&string, args);
			ft_check_string(&string, args);
			ft_check_pointer(&string, args);
			ft_check_integer(&string, args);
			ft_check_unsigned(&string, args);
			ft_check_lower_hex(&string, args);
			ft_check_upper_hex(&string, args);
		}
	}
	free(string);
	va_end(args);
	return (1);
}
