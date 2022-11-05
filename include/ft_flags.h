/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:11:49 by ansoulim          #+#    #+#             */
/*   Updated: 2022/11/05 19:17:29 by ansoulim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

typedef struct	s_flags
{
   int plus;
   int minus;
   int zero;
   int space;
   int number;
   char format;
}        t_flags;

#endif
