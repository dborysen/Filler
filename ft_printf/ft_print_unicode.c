/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:49:46 by dborysen          #+#    #+#             */
/*   Updated: 2017/12/28 17:49:47 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_2bytes(int n, char **line)
{
	if (*line)
	{
		(*line)[0] = 49280 >> 8 | n >> 6;
		(*line)[1] = 128 | (n & 63);
		(*line)[2] = '\0';
	}
}

void	print_3bytes(int n, char **line)
{
	if (*line)
	{
		(*line)[0] = (14712960 >> 16) | (n >> 12);
		(*line)[1] = 128 | ((n >> 6) & 63);
		(*line)[2] = 128 | (n & 63);
		(*line)[3] = '\0';
	}
}

void	print_4bytes(int n, char **line)
{
	if (*line)
	{
		(*line)[0] = 4034953344 >> 24 | n >> 18;
		(*line)[1] = 128 | (n >> 12);
		(*line)[2] = 128 | (((n >> 6) & 63));
		(*line)[3] = 128 | (n & 63);
		(*line)[4] = '\0';
	}
}

void	ft_print_unicode(int n, t_flags *flags)
{
	char	*str;
	int		k;
	char	v;
	void	(*print_bytes)(int, char **);

	k = 0;
	v = n;
	print_bytes = NULL;
	if (n >= 0 && n < 128)
	{
		flags->bnum += ft_putchar(n);
		return ;
	}
	if (n >= 128 && n < 2048 && (k = 3))
		print_bytes = &print_2bytes;
	else if (n >= 2048 && n < 32768 && (k = 4))
		print_bytes = &print_3bytes;
	else if (n >= 32768 && n < 524288 && (k = 5))
		print_bytes = &print_4bytes;
	if ((str = (char*)malloc(sizeof(char) * k)))
	{
		print_bytes(n, &str);
		flags->bnum += ft_putstr(str);
		free(str);
	}
}
