/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:12:52 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 04:27:06 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_integer(va_list args)
{
	long	num;

	num = va_arg(args, long);
	ft_putnbr(num);
	return (ft_count_digits(num));
}
