/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 04:19:05 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 09:01:55 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_count_digits(int nbr)
{
	int	nbr_chars_written;

	if (nbr == 0)
		return (1);
	if (nbr >= 0)
		nbr_chars_written = 0;
	else
		nbr_chars_written = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		nbr_chars_written++;
	}
	return (nbr_chars_written);
}
