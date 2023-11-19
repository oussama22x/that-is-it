/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 01:59:50 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 01:59:52 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	get_x_y_of_the_player(t_all **all)
{
	char	c;

	while ((*all)->map[(*all)->x])
	{
		(*all)->y = 0;
		while ((*all)->map[(*all)->x][(*all)->y])
		{
			c = (*all)->map[(*all)->x][(*all)->y];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return ;
			(*all)->y++;
		}
		(*all)->x++;
	}
}

int	count_pinters(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	make_duble(t_textr *txtr, t_all *all)
{
	txtr->s = malloc(sizeof(char *) * 6);
	ft_lst_add_back(&all->garb, ft_lst_new(txtr->s));
	txtr->s[0] = txtr->no[1];
	txtr->s[1] = txtr->so[1];
	txtr->s[2] = txtr->we[1];
	txtr->s[3] = txtr->ea[1];
	txtr->s[4] = txtr->dor[1];
	txtr->s[5] = NULL;
}

int	check_errors(char **map)
{
	int	i;
	int	plr;
	int	x;

	plr = 0;
	i = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][x] != 'N' && map[i][x] != 'E' && map[i][x] != 'S'
				&& map[i][x] != 'W' && map[i][x] != '0' && map[i][x] != '1'
				&& map[i][x] != ' ' && map[i][x] != 'D' && map[i][x] != 'A')
				return (1);
			if (map[i][x] == 'N' || map[i][x] == 'E' || map[i][x] == 'S'
				|| map[i][x] == 'W')
				plr++;
			x++;
		}
		i++;
	}
	if (plr > 1 || plr == 0)
		return (1);
	return (0);
}
