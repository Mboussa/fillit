/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 09:30:20 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/26 13:47:17 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1
# include "./libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# define MAX_X  4
# define MAX_Y  4
# define MAX_TETRIS 26

typedef struct		s_tetriminos
{
	int				errorquiseg;
	int				x;
	int				y;
	char			tetris[MAX_X][MAX_Y];
}					t_tetriminos;

typedef struct		s_all
{
	int				nb;
	t_tetriminos	t[MAX_TETRIS];
}					t_all;

typedef struct		s_map
{
	char			**map;
	int				size;
	int				x;
	int				y;
}					t_map;

int					ft_sqrt(int nb);
int					checkfile(char *str);
int					countblock(char *str);
int					checkblock(t_all tet, int x);
t_all				fill_all(char *str);
char				*readfile(int fd, char *str);
t_tetriminos		init_tetris(char *str, int *x);
void				init_map(t_all tet, t_map *m);
void				dot_map(t_map *m);
void				print_map(t_map *m);
void				place_tetris(t_all t, t_map *m, int line, int col, int a);
int					checkplace(t_all t, t_map *m, int line, int col, int a);
int					check_place2(t_map *m, int line, int col);
int					solve(t_all t, t_map *m, int pos, int a);
void				display(t_map *m);
t_all				fill_xy(int a);

#endif
