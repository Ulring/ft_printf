/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:35:04 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/09 03:18:30 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					neg;

	neg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg *= -1;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		if (res > 9223372036854775807 && neg > 0)
			return (-1);
		if (res > 9223372036854775807 && neg < 0)
			return (0);
		str++;
	}
	return ((int)res * neg);
}
