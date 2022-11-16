/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:27:51 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 08:28:33 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_decimal(char **str, va_list args)
{
	int j;

	j = 0;
	if (*(*str + 1) == 'd')
	{
		j = va_arg(args, int);
		ft_putnbr(j);
		(*str) += 2;
	}
}
