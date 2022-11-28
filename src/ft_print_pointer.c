/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:20:05 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 08:43:14 by ansoulim         ###   ########.fr       */
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
