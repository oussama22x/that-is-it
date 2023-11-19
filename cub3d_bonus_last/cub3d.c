/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:11:15 by otamrani          #+#    #+#             */
/*   Updated: 2023/11/18 22:26:49 by otamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	count_pinter(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		i++;
	}
	return (i);
}

int	count(char **str)
{
	int	i;
	int	x;
	int	l;

	l = 0;
	i = 0;
	x = 0;
	if (strcmp(str[0], "F") && strcmp(str[0], "C"))
		return (-1);
	else
		i = 1;
	while (str[i][l])
	{
		if (str[i][l] == ',')
			x++;
		if (str[i][l] != ',' && (str[i][l] < '0' || str[i][l] > '9'))
			return (-1);
		l++;
	}
	if (x > 2 || x < 2)
		return (-1);
	return (0);
}

void	exit_if_error(t_all *all, t_textr *txtr)
{
	if (ft_atoi_num(txtr) == -1)
	{
		printf("unvalid \nERROR 3\n");
		exit(0);
	}
	get_colers(txtr);
	get_longest_line(all);
	show_map(all, txtr);
}

void	exit_error(t_textr *txtr)
{
	if (check_final(txtr) == -1)
	{
		printf("unvalid \nERROR 2\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_all		*all;
	t_textr		*txtr;
	t_garbage	*garb;
	int			len;
	int			i;

	garb = malloc(sizeof(t_garbage));
	garb->next = NULL;
	if (argc > 1)
	{
		if (check_extionts(argv[1]) == -1 || all_in_one(&all, &txtr, argv,
				&garb) == -1)
			return (0);
		len = updatemap(all);
		all->garb = garb;
		count_x_y_of_the_map(&all);
		fix_map(&all, len);
		exit_error(txtr);
		exit_if_error(all, txtr);
	}
	else
		printf("messing file map ☠️ 👽\nERROR");
	return (0);
}
