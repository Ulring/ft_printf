/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:39:58 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/09 03:22:30 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count(int n)
{
	long	num;
	int		i;

	num = n;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		num *= -1;
	}
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;

	num = (long)n;
	i = count(n) - 1;
	str = (char *)malloc(sizeof(char) * (count(n) + 1));
	if (str == 0)
		return (NULL);
	if (n == -2147483648)
		num = 2147483648;
	else if (num < 0)
		num *= -1;
	str[count(n)] = '\0';
	while (i >= 0)
	{
		str[i] = (num % 10) + 48;
		num = num / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
