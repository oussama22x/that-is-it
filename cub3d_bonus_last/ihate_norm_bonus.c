/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihate_norm_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:30:47 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 04:30:49 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	collext(t_all **all)
{
	int	i;

	i = 0;
	while ((*all)->map[i])
	{
		ft_lst_add_back(&(*all)->garb, ft_lst_new((*all)->map[i]));
		i++;
	}
}

void	count_new_lines(t_all **all)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while ((*all)->line[i])
	{
		if ((*all)->line[i] == '\n')
		{
			x++;
		}
		i++;
	}
	(*all)->numptr = x;
}

void	get_map(t_all **all, int fd)
{
	char	*tmp;

	tmp = NULL;
	(*all)->line = NULL;
	tmp = get_next_line(fd);
	ft_lst_add_back(&(*all)->garb, ft_lst_new(tmp));
	if (!tmp)
		exit(4);
	while (tmp)
	{
		tmp = ft_strjoin((*all)->line, tmp);
		ft_lst_add_back(&(*all)->garb, ft_lst_new(tmp));
		(*all)->line = ft_strdup(tmp);
		ft_lst_add_back(&(*all)->garb, ft_lst_new((*all)->line));
		tmp = get_next_line(fd);
		ft_lst_add_back(&(*all)->garb, ft_lst_new(tmp));
	}
	count_new_lines(all);
	get_long_line(all);
	allocate_new_lines(all);
	copy_to_map(all);
	ft_lst_add_back(&(*all)->garb, ft_lst_new((*all)->map));
}
