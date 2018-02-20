/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pack2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:30:04 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/22 13:30:05 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_obig(t_flags *flags, long long argptr)
{
	char *temp;

	(void)flags;
	if (flags->hash == '#')
	{
		ft_putchar('0');
		flags->bnum++;
	}
	temp = ft_itoa_base((unsigned long)argptr, 8);
	ft_putstr(temp);
	ft_strdel(&temp);
}

void	ft_output_xbig(t_flags *flags, long long argptr)
{
	char *temp;

	if (flags->hash == '#')
	{
		ft_putstr("0X");
		flags->bnum = flags->bnum + 2;
	}
	if (flags->size_flag == 'H')
		temp = ft_itoa_base((unsigned char)argptr, 16);
	else if (flags->size_flag == 'h')
		temp = ft_itoa_base((unsigned short int)argptr, 16);
	else if (flags->size_flag == 'z')
		temp = ft_itoa_base((size_t)argptr, 16);
	else if (flags->size_flag == 'j')
		temp = ft_itoa_base((uintmax_t)argptr, 16);
	else if (flags->size_flag == 'l')
		temp = ft_itoa_base((unsigned long)argptr, 16);
	else if (flags->size_flag == 'L')
		temp = ft_itoa_base((unsigned long long)argptr, 16);
	else
		temp = ft_itoa_base((unsigned int)argptr, 16);
	flags->bnum += ft_putstr(temp);
	ft_strdel(&temp);
}

void	ft_output_ubig(t_flags *flags, unsigned long long argptr)
{
	if (flags->size_flag == 'H')
		flags->bnum += ft_putllu((unsigned char)argptr);
	else if (flags->size_flag == 'h')
		flags->bnum += ft_putllu((unsigned short int)argptr);
	else if (flags->size_flag == 'z')
		flags->bnum += ft_putllu((size_t)argptr);
	else if (flags->size_flag == 'j')
		flags->bnum += ft_putllu((uintmax_t)argptr);
	else
		flags->bnum += ft_putllu(argptr);
}

void	ft_output_p(t_flags *flags, long long argptr)
{
	char *temp;

	(void)flags;
	flags->bnum = flags->bnum + 2;
	temp = ft_lowstr(ft_itoa_base(argptr, 16));
	ft_putstr("0x");
	flags->bnum += ft_putstr(temp);
	ft_strdel(&temp);
}

void	output_help(const char *s, t_flags *flags, t_phelp *help)
{
	flags->bnum += ft_putchar(s[help->i]);
	help->i = help->i + 2;
}
