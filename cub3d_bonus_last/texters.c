/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 05:06:52 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 05:06:53 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "file.h"

void	fill_the_rest_of_the_map(t_all **all)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	get_longest_line(*all);
	while (i < (*all)->yofmap)
	{
		x = 0;
		while (x < (*all)->longestline)
		{
			if ((*all)->map[i][x] == 32 || (*all)->map[i][x] == 0)
				(*all)->map[i][x] = '1';
			x++;
		}
		i++;
	}
}

void	fix_map(t_all **all, int len)
{
	char	**new_map;
	int		i;
	int		x;

	i = 0;
	x = 0;
	new_map = calloc(sizeof(char *), (*all)->yofmap + 2);
	ft_lst_add_back(&(*all)->garb, ft_lst_new(new_map));
	while (i < (*all)->yofmap)
	{
		new_map[i] = calloc(sizeof(char), len + 2);
		ft_lst_add_back(&(*all)->garb, ft_lst_new(new_map[i]));
		i++;
	}
	init_new(all, new_map);
	new_map[i] = NULL;
	(*all)->map = new_map;
	i = 0;
	if (check_if_close((*all)->map) != -1)
	{
		if (check_for_valid_map((*all)->map) != -1)
			fill_the_rest_of_the_map(all);
	}
	else
		exit(1);
}

int	ft_atoi_num(t_textr *txt)
{
	if (helper(txt->f, txt->colorf[1], &txt->garb) == -1 || helper(txt->c,
			txt->colorc[1], &txt->garb) == -1)
		return (-1);
	return (0);
}

unsigned int	rgbtouint8(int R, int G, int B)
{
	return ((R << 16) | (G << 8) | B);
}

void	get_colers(t_textr *txtr)
{
	txtr->cclor = rgbtouint8(txtr->c[0], txtr->c[1], txtr->c[2]);
	txtr->fclor = rgbtouint8(txtr->f[0], txtr->f[1], txtr->f[2]);
}
