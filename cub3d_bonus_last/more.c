/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:20:43 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 05:01:14 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	if_conditio(char **map, int i)
{
	if (i == 0 && (ft_strnstr(map[i], "0", strlen(map[i]) - 1)
			|| ft_strnstr(map[i], "N", strlen(map[i]) - 1) || ft_strnstr(map[i],
				"S", strlen(map[i]) - 1) || ft_strnstr(map[i], "E",
				strlen(map[i]) - 1) || ft_strnstr(map[i], "W", strlen(map[i])
				- 1)))
	{
		printf("not close\nERRROR");
		return (-1);
	}
	return (0);
}

int	else_condition(char **map, int i)
{
	i--;
	if ((ft_strnstr(map[i], "0", strlen(map[i])) || ft_strnstr(map[i], "N",
				strlen(map[i])) || ft_strnstr(map[i], "S", strlen(map[i]))
			|| ft_strnstr(map[i], "E", strlen(map[i])) || ft_strnstr(map[i],
				"W", strlen(map[i]))))
	{
		printf("not close\nERRROR");
		return (-1);
	}
	return (0);
}

void	print_and_exit(void)
{
	printf("not close\nERRROR");
	exit(1);
}

int	just_for_norm_thing(char **map, int i)
{
	if (map[i][ft_strlen(map[i]) - 1] == 'N' || map[i][ft_strlen(map[i])
		- 1] == 'E' || map[i][ft_strlen(map[i]) - 1] == 'S'
		|| map[i][ft_strlen(map[i]) - 1] == 'W' || map[i][ft_strlen(map[i])
		- 1] == '0')
		return (-1);
	return (0);
}

int	check_if_close(char **map)
{
	int	i;
	int	x;

	i = 0;
	if (if_conditio(map, i) == -1)
		return (-1);
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][0] == 'N' || map[i][0] == 'E' || map[i][0] == 'S'
				|| map[i][0] == 'W' || map[i][0] == '0')
				print_and_exit();
			if (just_for_norm_thing(map, i) == -1)
				print_and_exit();
			x++;
		}
		i++;
	}
	if (else_condition(map, i) == -1)
		return (-1);
	return (0);
}
