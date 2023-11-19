/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:41:52 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 04:41:54 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	init_all(t_all **all)
{
	(*all)->x = 0;
	(*all)->y = 0;
	(*all)->xofmap = 0;
	(*all)->yofmap = 0;
	(*all)->map = NULL;
	(*all)->longestline = 0;
	(*all)->numptr = 0;
	(*all)->line = NULL;
	(*all)->lon = 0;
}

void	count_x_y_of_the_map(t_all **all)
{
	while ((*all)->map[(*all)->yofmap])
	{
		(*all)->xofmap = 0;
		while ((*all)->map[(*all)->yofmap][(*all)->xofmap])
			(*all)->xofmap++;
		(*all)->yofmap++;
	}
}

int	updatemap(t_all *all)
{
	int	x;
	int	i;
	int	len;

	len = 0;
	i = 0;
	x = 0;
	len = ft_strlen(all->map[0]);
	while (all->map[i])
	{
		x = 0;
		while (all->map[i][x])
			x++;
		if (x > len)
			len = x;
		i++;
	}
	return (len);
}

void	call_me(void)
{
	printf("unvalid file extiontsion\nERRROR");
	exit(1);
}

int	check_extionts(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '.')
		i++;
	if (argv[1] == '.')
		i++;
	while (argv[i])
	{
		if (argv[i] == '.')
			if (strcmp((argv + i + 1), "cub"))
				call_me();
		i++;
	}
	return (0);
}
