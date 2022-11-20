/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:27:51 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/20 23:50:02 by ansoulim         ###   ########.fr       */
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

int	ft_print_decimal(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr(nbr);
	return (ft_count_digits(nbr)); 
}
