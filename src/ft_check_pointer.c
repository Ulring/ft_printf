/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:20:05 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 08:21:42 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_pointer(char **str, va_list args)
{
	if (*(*str + 1) == 'p')
	{
		long num;
		num = va_arg(args, long);
		ft_putstr("0x");
		ft_putstr(ft_convert_base(ft_itoa(num), "0123456789", "0123456789abcdef"));
		(*str) += 2;
	}
}

