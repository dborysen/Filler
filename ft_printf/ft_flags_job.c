/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_job.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:37:06 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/22 12:37:07 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_search(char *s, t_flags *flags)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] == '0' && (s[i - 1] < '0' || s[i - 1] > '9'))
		{
			m++;
			break ;
		}
		i++;
	}
	if (m > 0)
		flags->zero = '0';
	i = 0;
}

void	ft_width_search(char *s, t_flags *flags)
{
	size_t	i;
	int		k;
	int		m;
	char	*t;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i - 1] != '.' && (s[i] >= '1' && s[i] <= '9'))
			break ;
		i++;
	}
	if (i < ft_strlen(s))
	{
		m = i;
		while (s[m] >= '0' && s[m] <= '9')
		{
			k++;
			m++;
		}
		t = ft_strsub(s, i, k);
		flags->width = ft_atoi(t);
		ft_strdel(&t);
	}
}

void	ft_precision_search(char *s, t_flags *flags)
{
	int		i;
	int		k;
	int		m;
	char	*t;

	k = 0;
	i = 0;
	while (s[i] != '.' && s[i])
		i++;
	i++;
	m = i;
	while (s[m] >= '0' && s[m] <= '9')
	{
		m++;
		k++;
	}
	t = ft_strsub(s, i, k);
	flags->precision = ft_atoi(t);
	ft_strdel(&t);
}

void	ft_is_a_flag(char *s, t_flags *flags)
{
	int i;
	int k;

	k = 0;
	i = 0;
	if (ft_strchr(s, '+'))
		flags->plus = '+';
	if (ft_strchr(s, '-'))
		flags->minus = '-';
	if (ft_strchr(s, '#'))
		flags->hash = '#';
	if (ft_strchr(s, ' '))
		flags->space = ' ';
	if (ft_strchr(s, '*'))
		flags->star = '*';
	flags->type = ft_corrent_type(s);
	if (ft_strchr(s, '.'))
		ft_precision_search(s, flags);
	ft_width_search(s, flags);
	ft_zero_search(s, flags);
	(flags->type != 'c' && flags->type != 's') ?
	(flags->size_flag = ft_priority_flag(s)) :
	(flags->size_flag = ft_char_priority_flag(s));
	if (MB_CUR_MAX == 1 && flags->type == 'C')
		flags->type = 'c';
}

int		ft_count_digit(long long n)
{
	int i;

	i = 0;
	while ((n / 10))
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}
