/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:26:18 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 08:27:07 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_char(char **str, va_list args)
{
	int j;

	j = 0;
	if (*(*str + 1) == 'c')
	{
		j = va_arg(args, int);
		ft_putchar(j);
		(*str) += 2;
	}
}
