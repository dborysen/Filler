/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:55:24 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/14 17:14:11 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *destptr, const char *srcptr)
{
	int l;
	int i;

	i = 0;
	l = 0;
	while (destptr[l])
		l++;
	while (srcptr[i] && (destptr[l++] = srcptr[i++]))
		;
	destptr[l] = '\0';
	return (destptr);
}
