/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:03:45 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 08:05:09 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_upper_hex(char **str, va_list args)
{
	if (*(*str+1) == 'X')
	{
		long num;
		num = va_arg(args, long);
		ft_putstr(ft_convert_base(ft_itoa(num), "0123456789", "0123456789ABCDEF"));
		(*str) += 2;
	}
}
