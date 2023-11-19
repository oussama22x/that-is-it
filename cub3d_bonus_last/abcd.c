/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 05:19:14 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 05:19:26 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	get_longest_line(t_all *all)
{
	char	**tmp;
	int		i;
	int		x;

	x = 0;
	tmp = all->map;
	i = 0;
	all->longestline = ft_strlen(all->map[0]);
	while (tmp[x])
	{
		i = 0;
		while (tmp[x][i])
		{
			i++;
		}
		if (i > all->longestline)
			all->longestline = i;
		x++;
	}
}

int	check_final(t_textr *txtr)
{
	if (count_pinter(txtr->colorc) > 2 || count_pinter(txtr->colorf) > 2)
		return (-1);
	if (count(txtr->colorc) == -1 || count(txtr->colorf) == -1)
		return (-1);
	return (0);
}

int	aqp(t_all **all, t_textr **txtr)
{
	if (check_errors((*all)->map))
	{
		printf("unvalid map:\nERROR 2 ");
		return (-1);
	}
	if (!(*txtr)->colorc || !(*txtr)->colorf || !(*txtr)->ea || !(*txtr)->no
		|| !(*txtr)->so || !(*txtr)->we)
	{
		printf("unvalid map:\nERROR 3");
		return (-1);
	}
	if (extra_condtion(txtr, all) == -1)
		return (-1);
	return (0);
}

void	init_new(t_all **all, char **new_map)
{
	int	i;
	int	x;

	i = 0;
	while (i < (*all)->yofmap)
	{
		x = 0;
		while ((*all)->map[i][x])
		{
			new_map[i][x] = (*all)->map[i][x];
			x++;
		}
		new_map[i][x] = '\0';
		i++;
	}
}

int	check_for_valid_map(char **map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][x] == '0')
				ok(map, i, x);
			x++;
		}
		i++;
	}
	if (extra_check(map) == -1)
		return (-1);
	if (ft_strchr(map[i - 1], '0'))
		return (-1);
	return (0);
}
