/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:07:41 by dborysen          #+#    #+#             */
/*   Updated: 2018/01/23 13:07:42 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_which_output(char type, void (**ft_output)(t_flags *, long long))
{
	if (type == 's')
		*ft_output = &ft_output_s;
	else if (type == 'S')
		*ft_output = &ft_output_sbig;
	else if (type == 'p')
		*ft_output = &ft_output_p;
	else if (type == 'D')
		*ft_output = &ft_output_dbig;
	else if (type == 'i' || type == 'd')
		*ft_output = &ft_output_d;
	else if (type == 'o')
		*ft_output = &ft_output_o;
	else if (type == 'O')
		*ft_output = &ft_output_obig;
	else if (type == 'x')
		*ft_output = &ft_output_x;
	else if (type == 'X')
		*ft_output = &ft_output_xbig;
	else if (type == 'c')
		*ft_output = &ft_output_c;
	else if (type == 'C')
		*ft_output = &ft_output_cbig;
}

void	ft_which_output_u(char type, void (**ft_outputu)
	(t_flags *, unsigned long long))
{
	if (type == 'u')
		*ft_outputu = &ft_output_u;
	else if (type == 'U')
		*ft_outputu = &ft_output_ubig;
	else if (type == 'b')
		*ft_outputu = &ft_output_b;
}

void	fill_flags(t_flags **flags, t_phelp **help)
{
	*help = (t_phelp*)malloc(sizeof(t_phelp));
	*flags = (t_flags*)malloc(sizeof(t_flags));
	(*help)->i = 0;
	(*flags)->precision = 0;
	(*flags)->width = 0;
	(*flags)->bnum = 0;
}

void	free_lists(t_flags **flags, t_phelp **help)
{
	free(*flags);
	free(*help);
}

int		free_help(const char *s, t_flags **flags, t_phelp **help)
{
	if (ft_count_flags(s) == 0)
	{
		free(*flags);
		free(*help);
		return (-1);
	}
	return (0);
}
