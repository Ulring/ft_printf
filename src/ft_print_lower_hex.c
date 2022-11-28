/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:06:58 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 08:57:50 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_lower_hex(va_list args)
{
	size_t	nbr;

	nbr = va_arg(args, unsigned int);
	ft_calculate_lower_hex(nbr);
	return (ft_hex_length(nbr));
}
