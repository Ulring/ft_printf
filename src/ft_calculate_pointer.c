/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:55:28 by ansoulim          #+#    #+#             */
/*   Updated: 2022/12/02 00:55:37 by ansoulim         ###   ########.fr       */
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
