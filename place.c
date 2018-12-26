/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   place.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 16:09:56 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/26 14:11:22 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
 #include "fillit.h"

void	dot_map(t_map *m)
{
	int		i;
	int		j;


	i = 0;

	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
		{
			m->map[i][j] = '.';
			j++;
		}
		i++;
	}
}
 
int		get_col_pos(t_all t, int x)
{
	int		i;
	int		j;
	int		a;

	i = 0;
	a = 4;
	while (i < MAX_Y)
	{
		j = 0;
		while (j < MAX_X)
		{
			if (t.t[x].tetris[i][j] == '#' && j < a)
				a = j;
			else
				j++;	
		}
		i++;
	}
	return (a);
}

int		get_line_pos(t_all t, int x)
{
	int		i;
	int		j;
	int		b;

	j = 0;
	b = 4;
	while (j < MAX_X)
	{
		i = 0;
		while (i < MAX_Y)
		{
			if (t.t[x].tetris[i][j] == '#' && i < b)
				b = i;
			else
				i++;
		}
		j++;
	}
	return (b);
}

int		checkplace(t_all t, t_map *m, int line, int col, int a)
{
	int i;
	int j;
	int x;
	int y;

	x = get_line_pos(t,a);
	i = line;
	while (i < m->size && x < MAX_X)
	{
		j = col;
		y = get_col_pos(t, a);
		while (j < m->size && y < MAX_Y)
		{
			if (m->map[i][j] != '.' && t.t[a].tetris[x][y] == '#')
				return (0);
			j++;
			y++;
		}
		x++;
		i++;
	}
	return (1);
}

void	place_tetris(t_all t, t_map *m, int line, int col, int a)
{
	int i;
	int j;
	int x;
	int y;

	x = get_line_pos(t,a);
	i = line;
	while (i < m->size && x < MAX_X)
	{
		j = col;
		y = get_col_pos(t, a);
		while (j < m->size && y < MAX_Y)
		{
			if (t.t[a].tetris[x][y] == '#')
				m->map[i][j] = 'A' + a;
			j++;
			y++;
		}
		i++;
		x++;
	}
}

int		check_place2(t_map *m, int line, int col)
{
	int i;
	int j;
	int c;

	c = 0;
	i = line;
	while (i < m->size)
	{
		j = col;
		while (j < m->size)
		{
			if (m->map[i][j] != '.')
				c++;
			j++;
		}
		i++;
	}
	if (c == 4 || c == 0)
		return (1);
	return (0);
}
