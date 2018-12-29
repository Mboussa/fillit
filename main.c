/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:06:22 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/27 13:35:00 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

 #include "fillit.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

void	display(t_map *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
		{
			ft_putchar(m->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putendl(" ");
		i++;
	}
}

void display3(t_all t, int a)
{
	printf("%d -- %d\n", t.t[a].x, t.t[a].y);
}

void	display2(t_all t, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAX_X)
	{
		j = 0;
		while (j < MAX_Y)
		{
			ft_putchar(t.t[x].tetris[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putendl(" ");
		i++;
	}
}

int		solve(t_all t, t_map *m, int pos, int a)
{
	int x;
	int y;
	if (a == t.nb)
		return (1);
	while (pos < m->size * m->size)
	{
		x = pos / m->size;
		y = pos % m->size;
		if (checkplace(t, m, x, y, a))
		{
			place_tetris(t, m, x, y, a);
			if (a < t.nb)
				a++;
		}
		pos++;
	}
	if (a == t.nb)
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		pos;
	int		a;
	int 	x;

	pos = 0;
	a = 0;
	x = 0;
	t_all	t;
	t_map	m;
	if (ac != 2)
		return (0);
	str = ft_strnew(0); 
	fd = open (av[1], O_RDONLY);
	str = readfile(fd, str);
	t = fill_all(str);
	while (x < t.nb)
	{
		t = fill_xy(x);
		x++;
	}
	init_map(t, &m);
	dot_map(&m);
	if (solve(t, &m, pos, a))
		display(&m);
	else
		printf("Error\n");
	close(fd);
	return (0);
}