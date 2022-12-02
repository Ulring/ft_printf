/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:54:47 by ansoulim          #+#    #+#             */
/*   Updated: 2022/12/02 03:54:49 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_pointer(va_list args)
{
	size_t	nbr;

	ft_putstr("0x");
	nbr = va_arg(args, unsigned long long);
	ft_calculate_pointer(nbr);
	return (ft_hex_length(nbr) + 2);
}
