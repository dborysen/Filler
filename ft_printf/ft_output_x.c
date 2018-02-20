/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:22:30 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/19 10:22:32 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_x(t_flags *flags, long long argptr)
{
	char *temp;

	if (flags->size_flag == 'H')
		temp = ft_lowstr(ft_itoa_base((unsigned char)argptr, 16));
	else if (flags->size_flag == 'h')
		temp = ft_lowstr(ft_itoa_base((unsigned short int)argptr, 16));
	else if (flags->size_flag == 'z')
		temp = ft_lowstr(ft_itoa_base((size_t)argptr, 16));
	else if (flags->size_flag == 'j')
		temp = ft_lowstr(ft_itoa_base((uintmax_t)argptr, 16));
	else if (flags->size_flag == 'l')
		temp = ft_lowstr(ft_itoa_base((unsigned long)argptr, 16));
	else if (flags->size_flag == 'L')
		temp = ft_lowstr(ft_itoa_base((unsigned long long)argptr, 16));
	else
		temp = ft_lowstr(ft_itoa_base((unsigned int)argptr, 16));
	if (flags->minus == '-' && (size_t)flags->width >= ft_strlen(temp))
		left_alignment_x(flags, temp);
	else
		right_alignment_x(flags, temp);
	ft_strdel(&temp);
}

void	ft_output_o(t_flags *flags, long long argptr)
{
	char *temp;

	if (flags->size_flag == 'H')
		temp = ft_itoa_base((unsigned char)argptr, 8);
	else if (flags->size_flag == 'h')
		temp = ft_itoa_base((unsigned short int)argptr, 8);
	else if (flags->size_flag == 'z')
		temp = ft_itoa_base((size_t)argptr, 8);
	else if (flags->size_flag == 'l')
		temp = ft_itoa_base((unsigned long)argptr, 8);
	else if (flags->size_flag == 'L')
		temp = ft_itoa_base((unsigned long long)argptr, 8);
	else if (flags->size_flag == 'j')
		temp = ft_itoa_base((uintmax_t)argptr, 8);
	else
		temp = ft_itoa_base((unsigned int)argptr, 8);
	if (flags->minus == '-' && (size_t)flags->width >= ft_strlen(temp))
		left_alignment_o(flags, temp);
	else
		right_alignment_o(flags, temp);
	ft_strdel(&temp);
}
