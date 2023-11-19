/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 05:19:59 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 05:20:01 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdio.h>

void	get_long_line(t_all **all)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while ((*all)->line[i])
	{
		if ((*all)->line[i] == '\n')
		{
			if (x > (*all)->lon)
				(*all)->lon = x;
			x = 0;
		}
		else
			x++;
		i++;
	}
	if (x > (*all)->lon)
		(*all)->lon = x;
}

void	allocate_new_lines(t_all **all)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	(*all)->map = ft_calloc(sizeof(char *), ((*all)->numptr + 3));
	while ((*all)->line[i])
	{
		if ((*all)->line[i] == '\n')
		{
			(*all)->map[y] = ft_calloc(sizeof(char), (*all)->lon + 1);
			y++;
		}
		i++;
	}
	(*all)->map[y] = ft_calloc(sizeof(char), (*all)->lon + 1);
}

void	copy_to_map(t_all **all)
{
	int	i;
	int	x;
	int	l;

	l = 0;
	i = 0;
	x = 0;
	while ((*all)->line[i])
	{
		if ((*all)->line[i] == '\n')
		{
			(*all)->map[x][l] = '\0';
			x++;
			l = 0;
		}
		else
		{
			(*all)->map[x][l] = (*all)->line[i];
			l++;
		}
		i++;
	}
	(*all)->map[x][l] = '\0';
	x++;
}

void	init_befor_init_hh(t_textr **txtr)
{
	(*txtr)->colorc = NULL;
	(*txtr)->colorf = NULL;
	(*txtr)->ea = NULL;
	(*txtr)->no = NULL;
	(*txtr)->so = NULL;
	(*txtr)->we = NULL;
	(*txtr)->dor = NULL;
	(*txtr)->c = calloc(sizeof(long long), 3);
	(*txtr)->f = calloc(sizeof(long long), 3);
	ft_lst_add_back(&(*txtr)->garb, ft_lst_new((*txtr)->c));
	ft_lst_add_back(&(*txtr)->garb, ft_lst_new((*txtr)->f));
}

int	start_reading_map(char *line)
{
	if (ft_strlen(line) == 0 && line[0] == '\0')
		return (1);
	if (!ft_strnstr(line, "NO", ft_strlen(line)) && !ft_strnstr(line, "SO",
			ft_strlen(line)) && !ft_strnstr(line, "WE", ft_strlen(line))
		&& !ft_strnstr(line, "EA", ft_strlen(line)) && !ft_strnstr(line, "F",
			ft_strlen(line)) && !ft_strnstr(line, "C", ft_strlen(line))
		&& !ft_strnstr(line, "\n", ft_strlen(line)) && !ft_strnstr(line, "DO",
			ft_strlen(line)))
		return (-1);
	return (0);
}
