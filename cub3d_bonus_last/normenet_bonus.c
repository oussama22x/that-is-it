/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normenet_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 05:01:00 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 05:01:02 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	init_txters(t_textr **txtr, t_all *all)
{
	t_go	go;

	go.tmp = NULL;
	init_befor_init_hh(txtr);
	init_arr(go.arr);
	go.x = 0;
	go.i = 0;
	while (all->map[go.i])
	{
		all->map[go.i] = remove_char(all->map[go.i]);
		if (start_reading_map(all->map[go.i]) == -1)
			break ;
		nor_things(all, &go, &go.x, go.i);
		nor_things2(all, &go, &go.x, go.i);
		nor_things3(all, &go, &go.x, go.i);
		nor_things4(all, &go, &go.x, go.i);
		go.i++;
	}
	just_check(go.x, go.arr);
	make_duble(*txtr, all);
	go.x = 0;
	go.i = 0;
	while (all->map[go.x][go.i] == '\0')
		go.x++;
	all->map = &all->map[go.x];
}

int	all_in_one(t_all **all, t_textr **txtr, char **argv, t_garbage **garb)
{
	(*all) = malloc(sizeof(t_all));
	(*txtr) = malloc(sizeof(t_textr));
	(*all)->fd = open(argv[1], O_RDONLY);
	(*all)->txt = (*txtr);
	(*all)->garb = (*garb);
	(*txtr)->garb = (*garb);
	if ((*all)->fd == -1)
	{
		printf("file not exist or unvalid\nERROR 1");
		return (-1);
	}
	init_all(all);
	get_map(all, (*all)->fd);
	init_txters(&(*txtr), (*all));
	if (aqp(all, txtr) == -1)
		return (-1);
	return (0);
}

void	collect(t_garbage **garb, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_lst_add_back(garb, ft_lst_new(str[i]));
		i++;
	}
	ft_lst_add_back(garb, ft_lst_new(str));
}

int	helper(long long *arr, char *str, t_garbage **garb)
{
	char	**spl;
	int		i;

	i = 0;
	spl = ft_split(str, ',');
	collect(garb, spl);
	while (spl[i])
	{
		arr[i] = ft_atoi(spl[i]);
		if (arr[i] > 255 || arr[i] < 0 || arr[i] == INT_MAX
			|| arr[i] == INT_MIN)
		{
			printf("ERROR\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
