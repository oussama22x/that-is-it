/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 02:35:13 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 02:36:29 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	extra_condtion(t_textr **txtr, t_all **all)
{
	if (count_pinters((*txtr)->ea) != 2 || count_pinters((*txtr)->no) != 2
		|| count_pinters((*txtr)->so) != 2 || count_pinters((*txtr)->we) != 2)
		return (-1);
	get_x_y_of_the_player((all));
	return (0);
}

void	init_arr(int *arr)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		arr[i] = 0;
		i++;
	}
}

char	*replce_tab(char *map)
{
	int	i;
	int	x;

	x = 1;
	i = 0;
	while (map[i])
	{
		if (map[i] == ' ')
		{
			map[x++] = map[i];
		}
		i++;
	}
	return (map);
}

char	*remove_char(char *map)
{
	int	i;

	i = 0;
	while ((map[i] && map[i] == ' '))
		i++;
	if (i > 0)
		map = ft_substr(map, i, ft_strlen(map));
	return (map);
}

char	*remove_space(char *map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	map[j++] = map[0];
	map[j++] = ' ';
	while (map[i])
	{
		if (map[i] != ' ')
		{
			map[j++] = map[i];
		}
		i++;
	}
	map[j] = '\0';
	return (map);
}
