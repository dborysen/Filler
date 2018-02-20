/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is4hesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:01:12 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/26 11:35:01 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is4hesh(char *s)
{
	int i;
	int k;
	int d;

	d = 0;
	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			k++;
		if (s[i] == '.' || s[i] == '#')
			d++;
		if ((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0')
		{
			if (k != 4 || d != 16)
				return (0);
			k = 0;
			d = 0;
		}
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	nbhelp(char *s, int i, int tet, int nb)
{
	if (s[i] == '#')
	{
		if (s[i + 1] == '#')
			nb++;
		if (s[i - 1] == '#')
			nb++;
		if (tet + 5 <= 19)
			if (s[i + 5] == '#')
				nb++;
		if (tet - 5 >= 0)
			if (s[i - 5] == '#')
				nb++;
	}
	return (nb);
}

int			ft_isvalid(char *s)
{
	int i;
	int nb;
	int tet;

	i = 0;
	nb = 0;
	tet = 0;
	if (ft_is4hesh(s) != 0)
	{
		while (s[i])
		{
			nb = nbhelp(s, i, tet, nb);
			if ((s[i] == '\n' && s[i + 1] == '\n') || s[i + 1] == '\0')
			{
				if (nb != 6 && nb != 8)
					return (0);
				nb = 0;
				tet = 0;
			}
			i++;
			tet++;
		}
		return (1);
	}
	return (0);
}
