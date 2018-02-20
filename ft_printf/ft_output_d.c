/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:21:49 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/11 16:21:50 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_d(t_flags *flags, long long argptr)
{
	if (flags->size_flag == 'H')
		(flags->minus == '-') ? left_alignment_d(flags, (signed char)argptr) :
		right_alignment_d(flags, (signed char)argptr);
	else if (flags->size_flag == 'h')
		(flags->minus == '-') ? left_alignment_d(flags, (short int)argptr) :
		right_alignment_d(flags, (short int)argptr);
	else if (flags->size_flag == 'j')
		(flags->minus == '-') ? left_alignment_d(flags, (intmax_t)argptr) :
		right_alignment_d(flags, (intmax_t)argptr);
	else if (flags->size_flag == 'l')
		(flags->minus == '-') ? left_alignment_d(flags, (long int)argptr) :
		right_alignment_d(flags, (long int)argptr);
	else if (flags->size_flag == 'z')
		(flags->minus == '-') ? left_alignment_d(flags, (size_t)argptr) :
		right_alignment_d(flags, (size_t)argptr);
	else if (flags->size_flag == 'L')
		(flags->minus == '-') ? left_alignment_d(flags, argptr) :
		right_alignment_d(flags, argptr);
	else
		(flags->minus == '-') ? left_alignment_d(flags, (int)argptr) :
		right_alignment_d(flags, (int)argptr);
}
