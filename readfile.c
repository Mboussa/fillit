/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readfile.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 18:40:21 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/27 13:04:07 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char			*readfile(int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

t_tetriminos	init_tetris(char *str, int *x)
{
	int				i;
	int				j;
	t_tetriminos	tet;

	tet.x = 0;
	i = 0;
	j = 0;
	while (j < 4)
	{
		tet.y = 0;
		while (str[i] != '\n' && str[i])
		{
			tet.tetris[tet.x][tet.y] = str[i];
			tet.y++;
			if (str[i] == '\n' && str[i + 1] == '\n')
				break ;
			i++;
		}
		tet.tetris[tet.x][tet.y] = '\0';
		tet.x++;
		i++;
		j++;
	}
	*x = i;
	return (tet);
}

t_all			fill_all(char *str)
{
	int		i;
	int		x;
	t_all	all;

	i = countblock(str);
	all.nb = 0;
	while (all.nb < i)
	{
		all.t[all.nb] = init_tetris(str, &x);
		str = ft_strsub(str, x + 1, ft_strlen(str) - (x - 1));
		all.nb++;
	}
	return (all);
}

t_all			fill_xy(int a)
{
	int i;
	int j;
	int x;
	t_all t;

	t.t[a].x = 1;
	t.t[a].y = 1;
	i = 0;
	x = 0;
	while (i < MAX_X && x < 4)
	{
		j = 0;
		while (j < MAX_Y && x < 4)
		{
			if (t.t[a].tetris[i][j] == '#')
				x++;
			if (t.t[a].tetris[i][j] == '#' && t.t[a].tetris[i][j + 1] == '#')
				t.t[a].x++;
			if (t.t[a].tetris[i][j] == '#' && t.t[a].tetris[i + 1][j] == '#')
				t.t[a].y++;
			j++;
		}
		i++;
	}
	return(t);
}