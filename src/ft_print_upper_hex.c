/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 05:43:23 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 08:45:54 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_upper_hex(va_list args)
{
	size_t	nbr;

	nbr = va_arg(args, unsigned int);
	ft_calculate_upper_hex(nbr);
	return (ft_hex_length(nbr));
}
