/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:53:45 by ansoulim          #+#    #+#             */
/*   Updated: 2022/12/02 03:53:54 by ansoulim         ###   ########.fr       */
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
