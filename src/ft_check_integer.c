/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:12:52 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 08:13:26 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_integer(char **str, va_list args)
{
	if (*(*str+1) == 'i')
	{
		long num;
		num = va_arg(args, long);
		char *str_i = ft_itoa(num);
		if (str_i[0] == '0')
			ft_putstr(ft_convert_base(ft_itoa(num), "0123456789", "01234567"));
		else if (str_i[0] == '0' && str_i[1] == 'x')
		{
			ft_putstr("0x");
			ft_putstr(ft_convert_base(ft_itoa(num), "0123456789", "01234567"));
		}
		else
			ft_putnbr(num);
		(*str) += 2;
	}
}

