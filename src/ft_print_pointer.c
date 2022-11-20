/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:20:05 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/20 23:31:09 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_calculate_pointer(size_t nbr)
{	
	if (nbr > 15)
	{
		ft_calculate_pointer(nbr / 16);
		ft_calculate_pointer(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar(nbr + 48);
		else
			ft_putchar(nbr - 10 + 'a');
	}
}

static size_t ft_pointer_length(size_t nbr)
{
	size_t	length;

	if(!nbr)
		return (1);
	length = 0;
	while (nbr)
	{
		nbr /= 16;
		length++;
	}
	return (length);
}

int	ft_print_pointer(va_list args)
{
	size_t	nbr;

	ft_putstr("0x");
	nbr = va_arg(args, unsigned long long);
	ft_calculate_pointer(nbr);
	return (ft_pointer_length(nbr) + 2);
}

