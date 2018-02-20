/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:21:16 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/18 11:21:20 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	right_alignment_s(t_flags *flags, long long argptr)
{
	int k;

	k = 0;
	if ((unsigned long)flags->width >
		ft_strlen((char*)argptr) - flags->precision)
	{
		while ((unsigned long)flags->width-- >
		ft_strlen((char*)argptr) - flags->precision)
		{
			if (flags->zero == '0')
				flags->bnum += ft_putchar('0');
			else
				flags->bnum += ft_putchar(' ');
		}
	}
	if (flags->precision != 0)
	{
		if (ft_strlen((char*)argptr) == 0)
			return ;
		while (k < flags->precision)
			flags->bnum += ft_putchar(((char*)argptr)[k++]);
	}
	else
		(flags->bnum += ft_putstr((char*)argptr));
}

void	left_alignment_s(t_flags *flags, long long argptr)
{
	int k;

	k = 0;
	if (flags->precision != 0)
		while (k < flags->precision)
			(flags->bnum += ft_putchar(((char*)argptr)[k++]));
	else
		flags->bnum += ft_putstr((char*)argptr);
	if ((unsigned long)flags->width >
	ft_strlen((char*)argptr) - flags->precision)
		while (flags->width-- > flags->precision)
			flags->bnum += ft_putchar(' ');
}

void	ft_output_s(t_flags *flags, long long argptr)
{
	int *m;
	int k;

	k = 0;
	m = 0;
	if (flags->size_flag == 'l')
	{
		ft_output_sbig(flags, argptr);
		return ;
	}
	if ((char*)argptr == NULL)
	{
		flags->bnum += ft_putstr("(null)");
		return ;
	}
	if (ft_strlen((char*)argptr) == 0)
		flags->precision = 0;
	if (flags->minus == '-')
		left_alignment_s(flags, argptr);
	else
		right_alignment_s(flags, argptr);
}
