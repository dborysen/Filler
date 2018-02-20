/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:29:41 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/18 14:29:42 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_u(t_flags *flags, unsigned long long argptr)
{
	if (flags->size_flag == 'H')
		(flags->minus == '-') ? left_alignment_u(flags, (unsigned char)argptr)
		: right_alignment_u(flags, (unsigned char)argptr);
	else if (flags->size_flag == 'h')
		(flags->minus == '-') ? left_alignment_u(flags,
		(unsigned short int)argptr) : right_alignment_u(flags,
		(unsigned short int)argptr);
	else if (flags->size_flag == 'j')
		(flags->minus == '-') ? left_alignment_u(flags, (uintmax_t)argptr) :
		right_alignment_u(flags, (uintmax_t)argptr);
	else if (flags->size_flag == 'l')
		(flags->minus == '-') ? left_alignment_u(flags, (unsigned long)argptr) :
		right_alignment_u(flags, (unsigned long)argptr);
	else if (flags->size_flag == 'z')
		(flags->minus == '-') ? left_alignment_u(flags, (size_t)argptr) :
		right_alignment_u(flags, (size_t)argptr);
	else if (flags->size_flag == 'L')
		(flags->minus == '-') ? left_alignment_u(flags, argptr) :
		right_alignment_u(flags, argptr);
	else
		(flags->minus == '-') ? left_alignment_u(flags, (unsigned int)argptr) :
		right_alignment_u(flags, (unsigned int)argptr);
}
