/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:19:14 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/26 11:42:58 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i;

	i = 8;
	res = 0;
	while (i > 0)
	{
		res = res * 2 + octet % 2;
		octet = octet / 2;
		i--;
	}
	return (res);
}
