/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_lower_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:02:53 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 09:03:01 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_calculate_lower_hex(unsigned int nbr)
{	
	if (nbr > 15)
	{
		ft_calculate_lower_hex(nbr / 16);
		ft_calculate_lower_hex(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar(nbr + 48);
		else
			ft_putchar(nbr - 10 + 'a');
	}
}
