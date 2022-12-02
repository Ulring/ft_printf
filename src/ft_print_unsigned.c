/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:55:30 by ansoulim          #+#    #+#             */
/*   Updated: 2022/12/02 03:55:40 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_unsigned_putnbr(unsigned int num)
{
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num + '0');
}

static int	ft_count_digits_unsigned(unsigned int nbr)
{
	int	nbr_chars_written;

	if (nbr == 0)
		return (1);
	if (nbr >= 0)
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

int	ft_print_unsigned(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_unsigned_putnbr(num);
	return (ft_count_digits_unsigned(num));
}
