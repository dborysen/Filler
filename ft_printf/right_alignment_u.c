/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_alignment_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:19:34 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/18 15:19:35 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extra_sign_u(t_flags *flags, unsigned long long argptr)
{
	int n;
	int zero_num;

	n = 0;
	zero_num = 0;
	if (flags->precision != 0)
		zero_num = flags->precision - ft_count_digit_u(argptr);
	flags->width = flags->width - 1;
	if (flags->zero == '0' && flags->plus == '+')
		flags->bnum += ft_putchar('+');
	else if (flags->zero == '0' && flags->space == ' ')
		flags->bnum += ft_putchar(' ');
	else if (flags->zero != '0' && flags->space == ' ' && flags->plus != '+')
		flags->bnum += ft_putchar(' ');
}

void	kostil_right_u(t_flags *flags, unsigned long long argptr)
{
	int n;
	int zero_num;

	n = 0;
	zero_num = 0;
	if (flags->precision != 0)
		zero_num = flags->precision - ft_count_digit_u(argptr);
	if (flags->zero != '0' && flags->plus == '+')
		flags->bnum += ft_putchar('+');
	if (flags->precision != 0)
	{
		while (n++ < zero_num)
			flags->bnum += ft_putchar('0');
		flags->bnum += ft_putllu(argptr);
	}
	else
		flags->bnum += ft_putllu(argptr);
}

void	right_alignment_u(t_flags *flags, unsigned long long argptr)
{
	int n;
	int zero_num;

	zero_num = 0;
	n = 0;
	if (flags->precision != 0)
		zero_num = flags->precision - ft_count_digit_u(argptr);
	if (flags->plus == '+' || flags->space == ' ')
		extra_sign_u(flags, argptr);
	while (n++ < (flags->width - ft_count_digit_u(argptr) - zero_num))
	{
		if (flags->zero != '0' || flags->precision != 0)
			flags->bnum += ft_putchar(' ');
		else if (flags->precision == 0)
			flags->bnum += ft_putchar('0');
	}
	kostil_right_u(flags, argptr);
}
