/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 05:00:45 by oelboukh          #+#    #+#             */
/*   Updated: 2023/11/19 05:00:48 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "get_line/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}						t_garbage;
t_garbage				*ft_lst_new(void *ptr);
typedef struct s_go
{
	int					i;
	int					x;
	int					arr[7];
	char				*tmp;
}						t_go;
void					ft_lst_add_back(t_garbage **head, t_garbage *new);
typedef struct s_textr
{
	char				**no;
	char				**so;
	char				**we;
	char				**ea;
	char				**dor;
	char				**s;
	char				**colorf;
	char				**colorc;
	long long			*f;
	long long			*c;
	long long			cclor;
	long long			fclor;
	t_garbage			*garb;
}						t_textr;

typedef struct s_all
{
	char				**map;
	char				*line;
	int					numptr;
	int					lon;
	void				*img;
	char				*addrs;
	int					endian;
	int					fd;
	int					y;
	int					x;
	int					xofmap;
	int					yofmap;
	int					longestline;
	t_textr				*txt;
	t_garbage			*garb;
}						t_all;
void					get_map(t_all **all, int fd);
int						check_errors(char **map);
void					init_txters(t_textr **txtr, t_all *all);
int						all_in_one(t_all **all, t_textr **txtr, char **argv,
							t_garbage **garb);
void					init_all(t_all **all);
void					count_x_y_of_the_map(t_all **all);
int						updatemap(t_all *all);
void					fix_map(t_all **all, int len);
int						check_if_close(char **map);
int						check_for_valid_map(char **map);
int						check_extionts(char *argv);
int						count_pinter(char **ptr);
int						count(char **str);
int						check_final(t_textr *txtr);
int						helper(long long *arr, char *str, t_garbage **garb);
int						ft_atoi_num(t_textr *txt);
unsigned int			RGBtoUint8(int R, int G, int B);
void					get_colers(t_textr *txtr);
void					init_befor_init_hh(t_textr **txtr);
int						start_reading_map(char *line);
void					init_txters(t_textr **txtr, t_all *all);
int						check_errors(char **map);
void					get_x_y_of_the_player(t_all **all);
void					get_longest_line(t_all *all);
int						check_for_doors(t_all *all);
void					nor_things(t_all *all, t_go *go, int *x, int i);
void					nor_things2(t_all *all, t_go *go, int *x, int i);
void					nor_things4(t_all *all, t_go *go, int *x, int i);
void					nor_things3(t_all *all, t_go *go, int *x, int i);
char					*remove_char(char *map);
char					*remove_space(char *map);
void					just_check(int x, int *arr);
int						extra_condtion(t_textr **txtr, t_all **all);
int						count_pinters(char **str);
void					init_arr(int *arr);
void					make_duble(t_textr *txtr, t_all *all);
void					get_long_line(t_all **all);
void					copy_to_map(t_all **all);
void					allocate_new_lines(t_all **all);
int						aqp(t_all **all, t_textr **txtr);
void					ok(char **map, int i, int x);
void					init_new(t_all **all, char **new_map);
int						extra_check(char **map);
#endif
