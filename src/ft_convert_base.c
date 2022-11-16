/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:01:11 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 07:57:33 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long	display(long nb, char *str, char *result, int index)
{
	long	nbr;
	long	str_length;

	str_length = ft_strlen(str);
	if (nb < 0)
	{
		result[index++] = '-';
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= str_length)
		display(nbr / str_length, str, result, index - 1);
	result[index] = str[nbr % str_length];
	return (index);
}

long	get_nbr_length(long number, char *base)
{
	long	length;
	long	base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	length = 0;
	while (number >= base_length)
	{
		++length;
		number /= base_length;
	}
	return (++length);
}

long	get_nb(char c, char *base)
{
	long	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

long	ft_atoi_base(char *str, char *base)
{
	long	s;
	long	i;
	long	res;
	long	negative;
	long	base_length;

	base_length = 0;
	while (base[base_length])
		++base_length;
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' \
				|| str[s] == '\r' || str[s] == '\n' || str[s] == '\v' \
				|| str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) \
				|| (str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	}
	return (res * negative);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	long	number;
	long	last_index;

	if (!nbr || !base_from || !base_to)
		return (0);
	number = ft_atoi_base(nbr, base_from);
	result = malloc(sizeof(char) * get_nbr_length(number, base_to));
	last_index = display(number, base_to,
			result, get_nbr_length(number, base_to) - 1);
	result[last_index + 1] = '\0';
	return (result);
}
