/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pack1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:23:23 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/22 13:23:24 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_b(t_flags *flags, unsigned long long argptr)
{
	char *temp;

	temp = ft_itoa_base(argptr, 2);
	flags->bnum += ft_putstr(temp);
	ft_strdel(&temp);
}

void	ft_output_cbig(t_flags *flags, long long argptr)
{
	(void)flags;
	ft_print_unicode((int)argptr, flags);
}

void	ft_output_sbig(t_flags *flags, long long argptr)
{
	int *m;
	int k;

	k = 0;
	(void)flags;
	m = (int*)(argptr);
	while (m[k])
	{
		ft_print_unicode(m[k], flags);
		k++;
	}
}

void	ft_output_c(t_flags *flags, long long argptr)
{
	if (flags->size_flag == 'l')
		ft_print_unicode((int)argptr, flags);
	else
		flags->bnum += ft_putchar((unsigned char)(argptr));
}

void	ft_output_dbig(t_flags *flags, long long argptr)
{
	(void)flags;
	ft_putlonglong(argptr);
}
