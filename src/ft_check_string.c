/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:22:36 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/16 08:24:48 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_string(char **str, va_list args)
{
	char *string;
	if (*(*str+1) == 's')
	{
		string = va_arg(args, char*);
		ft_putstr(string);
		(*str) += 2;
	}
}
