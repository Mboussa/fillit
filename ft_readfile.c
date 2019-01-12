/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readfile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 18:40:21 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 17:50:12 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char			*readfile(int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
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

void			*fill_all(t_all *t, char *str)
{
	int		i;
	int		x;
	char	*tmp;

	i = countblock(str);
	ft_memset(t, 0, sizeof(t));
	t->nb = 0;
	while (t->nb < i)
	{
		t->t[t->nb] = init_tetris(str, &x);
		tmp = str;
		str = ft_strsub(str, x + 1, ft_strlen(str) - (x - 1));
		free(tmp);
		t->nb++;
	}
	free(str);
	return (t);
}

void			fill_for_norm(t_all *t, int a)
{
	int i;
	int j;
	int x;

	x = 0;
	i = -1;
	while (++i < MAX_X && x < 4)
	{
		j = -1;
		while (++j < MAX_Y && x < 4)
		{
			if (t->t[a].tetris[i][j] == '#')
				x++;
			if (t->t[a].tetris[i][j] == '#' && t->t[a].tetris[i][j + 1] == '#')
				t->t[a].x++;
			if (t->t[a].tetris[i][j] == '#' && t->t[a].tetris[i + 1][j] == '#')
				t->t[a].y++;
		}
	}
}

void			*fill_xy(t_all *t, int a)
{
	t->t[a].x = 1;
	t->t[a].y = 1;
	if (square(t, a, 0))
	{
		t->t[a].x = 2;
		t->t[a].y = 2;
	}
	else
		fill_for_norm(t, a);
	return (t);
}
