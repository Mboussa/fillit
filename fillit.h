/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 09:30:20 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 18:06:10 by moboussa    ###    #+. /#+    ###.fr     */
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
	t_tetriminos	t[MAX_TETRIS];
	int				nb;
	char			**map;
	int				size;
	int				x;
	int				y;
}					t_all;

int					ft_sqrt(int nb);
int					checkfile(char *str);
int					countblock(char *str);
int					checkblock(t_all *t, int x, int b);
int					square(t_all *t, int x, int b);
void				*fill_all(t_all *t, char *str);
char				*readfile(int fd, char *str);
t_tetriminos		init_tetris(char *str, int *x);
void				init_map(t_all *tet, int si);
void				dot_map(t_all *m);
void				print_map(t_all *m);
void				place_tetris(t_all *t, int line, int col, int a);
int					checkplace(t_all *t, int line, int col, int a);
int					solve(t_all *t, int pos, int a);
void				display(t_all *m);
void				del_tetris(t_all *m, int a);
void				free_map(t_all *m);
void				*fill_xy(t_all *t, int a);

#endif
