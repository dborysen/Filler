/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:07:52 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/26 13:07:53 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_help(const char *s, t_flags *flags, t_phelp *help,
	unsigned long long argptr)
{
	ft_which_output_u(flags->type, &help->ft_outputu);
	help->ft_outputu(flags, argptr);
	help->i = help->i + ft_count_flags(s + help->i);
}

void	signed_help(const char *s, t_flags *flags, t_phelp *help,
	long long argptr)
{
	ft_which_output(flags->type, &help->ft_output);
	help->ft_output(flags, argptr);
	help->i = help->i + ft_count_flags(s + help->i);
}

void	pf_starhelp(t_flags *flags, t_phelp *help, unsigned long long argptr)
{
	help->temp = argptr;
	if (help->temp)
		flags->width = help->temp;
}

void	string_help(const char *s, t_flags *flags, t_phelp *help)
{
	help->tmp_str = ft_strsub(s, help->i, ft_count_flags(s + help->i));
	ft_is_a_flag(help->tmp_str, flags);
	ft_strdel(&help->tmp_str);
}

int		ft_printf(const char *s, ...)
{
	t_phelp *help;
	t_flags	*flags;

	fill_flags(&flags, &help);
	va_start(help->a, s);
	while (s[help->i])
		if (s[help->i] == '%' && s[help->i + 1] != '%')
		{
			if (free_help(s + help->i, &flags, &help) == -1)
				return (-1);
			string_help(s, flags, help);
			if (flags->star == '*')
				pf_starhelp(flags, help, va_arg(help->a, unsigned long long));
			(flags->type == 'u' || flags->type == 'U' || flags->type == 'b') ?
			unsigned_help(s, flags, help, va_arg(help->a, unsigned long long)) :
			signed_help(s, flags, help, va_arg(help->a, long long));
		}
		else if (s[help->i] == '%' && s[help->i + 1] == '%')
			output_help(s, flags, help);
		else
			flags->bnum += ft_putchar(s[help->i++]);
	va_end(help->a);
	free(help);
	free(flags);
	return (flags->bnum);
}
