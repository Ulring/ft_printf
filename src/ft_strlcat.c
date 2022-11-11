/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:38:55 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/09 03:24:58 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	i = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	j = dst_len;
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while (src[i] && j + 1 < dstsize)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (dst_len + src_len);
}
