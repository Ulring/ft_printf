/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 05:22:38 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 09:01:31 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_hex_length(size_t nbr)
{
	size_t	length;

	if (!nbr)
		return (1);
	length = 0;
	while (nbr)
	{
		nbr /= 16;
		length++;
	}
	return (length);
}
