/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_main.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:06:22 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:31:34 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int				solve(t_all *t, int pos, int a)
{
	int x;
	int y;

	if (a == t->nb)
		return (1);
	while (pos < t->size * t->size)
	{
		x = pos / t->size;
		y = pos % t->size;
		if (checkplace(t, x, y, a))
		{
			place_tetris(t, x, y, a);
			if (solve(t, 0, a + 1))
				return (1);
			del_tetris(t, a);
		}
		pos++;
	}
	return (0);
}

int				error_fillit(char *str, t_all *t)
{
	int		x;

	x = 0;
	if (!(checkfile(str)))
	{
		free(str);
		return (0);
	}
	else
	{
		fill_all(t, str);
		while (x < t->nb)
		{
			if (!(checkblock(t, x, 0)) && !(square(t, x, 0)))
				return (0);
			x++;
		}
		x = 0;
		while (x < t->nb)
		{
			fill_xy(t, x);
			x++;
		}
	}
	return (1);
}

int				main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		si;
	t_all	t;

	si = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit tetriminos_file\n");
		return (0);
	}
	str = ft_strnew(0);
	fd = open(av[1], O_RDONLY);
	str = readfile(fd, str);
	if (!(error_fillit(str, &t)))
		ft_putstr("error\n");
	else
	{
		init_map(&t, si);
		while (!(solve(&t, 0, 0)))
			init_map(&t, si++);
		display(&t);
	}
	close(fd);
	return (0);
}
