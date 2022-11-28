/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_lower_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 05:27:46 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 08:42:06 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_calculate_pointer(unsigned long long nbr)
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
