/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:33:29 by dborysen          #+#    #+#             */
/*   Updated: 2018/02/14 13:33:30 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <locale.h>
#include <stdio.h>

void	print_result(char *line)
{
	if (line[3] == 'O')
	{
		printf("\033[22;32m\nRESULT:\n\033[0m");
		printf("%S  = ", L"😈");
		printf("%d\n", ft_atoi(line + 10));
	}
	else
	{
		printf("%S  = ", L"😁");
		printf("%d\n", ft_atoi(line + 10));
		exit(0);
	}
}

void	print_field(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[0] == '=')
			exit(0);
		if (line[i] == 'X' || line[i] == 'x')
			printf("%S ", L"😁");
		else if (line[i] == 'O' || line[i] == 'o')
			printf("%S ", L"😈");
		else if (line[i] == '.')
			printf("%S ", L"🔺");
		else
			printf("%c", line[i]);
		i++;
	}
}

void	replace(char *line)
{
	int i;

	i = 0;
	if (line[0] == '#' || line[0] == 'l' || line[0] == '$' ||
		line[0] == 'P' || line[0] == '.' || line[0] == '*' ||
		line[0] == '<')
		return ;
	else if (line[0] == ' ')
	{
		usleep(80000);
		printf("%c[2J", 27);
	}
	else if (line[0] == '=')
		print_result(line);
	else
		print_field(line);
	printf("\n");
}

int		main(void)
{
	char *line;

	setlocale(LC_ALL, "");
	while (get_next_line(0, &line) > 0)
	{
		replace(line);
		free(line);
		line = NULL;
	}
}
