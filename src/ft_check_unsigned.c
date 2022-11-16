/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:11:12 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 08:12:20 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_unsigned(char **str, va_list args)
{
	if (*(*str + 1) == 'u')
	{
		unsigned int num;
		num = va_arg(args, unsigned int);
		ft_unsigned_putnbr(num);
		(*str) += 2;
	}
}

