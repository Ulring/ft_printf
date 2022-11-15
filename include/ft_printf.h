/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:12:00 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/15 01:41:29 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Note (Anass) : delete test_printf before final push

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_flags.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int 	ft_printf(const char *str, ...);
int		test_ft_printf(char *str, ...);
void    ft_putstr(char *str);
void    ft_putchar(char c);
char	*ft_strdup(const char *s1);
void    ft_putnbr(int n);
void    ft_unsigned_putnbr(unsigned int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
long    display(long nb, char *str, char *result, int index);
long    get_number_length(long number, char *base);
long    get_nb(char c, char *base);
long    ft_atoi_base(char *str, char *base);
char    *ft_convert_base(char *nbr, char *base_from, char *base_to);
int     ft_atoi(const char *str);
char	*ft_itoa(int n);
char    *ft_strjoin(char const *s1, char const *s2);
int     word_length(char *str, int i);
char    **ft_split(char *str);
int     detect_nbr(char *str);
int     ft_is_flag(char to_find, char *str);
struct  s_flags *ft_param_to_tab(char** str);

#endif