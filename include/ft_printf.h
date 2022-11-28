/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:12:00 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/28 09:26:52 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(va_list args);
int		ft_print_string(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_decimal(va_list args);
int		ft_print_integer(va_list args);
int		ft_print_unsigned(va_list args);
int		ft_print_lower_hex(va_list args);
int		ft_print_upper_hex(va_list args);
int		ft_print_modulo(void);
int		ft_count_digits(int nbr);
void	ft_calculate_pointer(unsigned long long nbr);
void	ft_calculate_lower_hex(unsigned int nbr);
void	ft_calculate_upper_hex(unsigned int nbr);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
size_t	ft_hex_length(size_t nbr);

#endif
