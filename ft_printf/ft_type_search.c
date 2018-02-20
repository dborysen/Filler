/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:29:05 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/22 12:29:06 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_place(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_count_flags(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 's' && s[i] != 'S' && s[i] != 'p' && s[i] != 'd' &&
		s[i] != 'D' && s[i] != 'i' && s[i] != 'o' && s[i] != 'O' &&
		s[i] != 'u' && s[i] != 'U' && s[i] != 'x' && s[i] != 'X' &&
		s[i] != 'c' && s[i] != 'C' && s[i] != 'b' && s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	return (i + 1);
}

char	ft_corrent_type(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 's' && s[i] != 'S' && s[i] != 'p' && s[i] != 'd' &&
		s[i] != 'D' && s[i] != 'i' && s[i] != 'o' && s[i] != 'O' &&
		s[i] != 'u' && s[i] != 'U' && s[i] != 'x' && s[i] != 'X' &&
		s[i] != 'c' && s[i] != 'C' && s[i] != 'b' && s[i])
		i++;
	return (s[i]);
}

char	ft_priority_flag(char *s)
{
	if (ft_strchr(s, 'z'))
		return ('z');
	else if (ft_strchr(s, 'j'))
		return ('j');
	else if (ft_strstr(s, "ll"))
		return ('L');
	else if (ft_strchr(s, 'l'))
		return ('l');
	else if (ft_strchr(s, 'h'))
		return ('h');
	else if (ft_strstr(s, "hh"))
		return ('H');
	return (0);
}

char	ft_char_priority_flag(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == 'l')
			count++;
		i++;
	}
	if (count % 2 != 0)
		return ('l');
	return (0);
}
