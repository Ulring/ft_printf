/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 03:51:39 by ansoulim          #+#    #+#             */
/*   Updated: 2022/12/02 03:51:45 by ansoulim         ###   ########.fr       */
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
