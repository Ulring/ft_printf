/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:12:52 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/21 00:42:34 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int ft_count_digits(int nbr)
{
	int	nbr_chars_written;

	if (nbr == 0)
		return (1);
	if(nbr >= 0)
		nbr_chars_written = 0;
	else
		nbr_chars_written = 1;
	while (nbr != 0) 
	{
		nbr = nbr / 10;
		nbr_chars_written++;
	}
	return (nbr_chars_written);
}

int	ft_print_integer(va_list args)
{
	long	num;

	num = va_arg(args, long);
	ft_putstr(ft_convert_base(ft_itoa(num), "0123456789", "01234567"));
	/*
	if (str_i[0] == '0')
		ft_putstr(ft_convert_base(ft_itoa(num), "0123456789", "01234567"));
	else if (str_i[0] == '0' && str_i[1] == 'x')
	{
		ft_putstr("0x");
		ft_putstr(ft_convert_base(ft_itoa(num), "0123456789", "01234567"));
	}*/
	ft_putnbr(num);
	return (1); //test
}
