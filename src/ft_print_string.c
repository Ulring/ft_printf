/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:22:36 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 08:56:30 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_string(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	if (!string)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(string);
	return (ft_strlen(string));
}
