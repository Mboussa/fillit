/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 11:15:44 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 19:42:03 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			init_map(t_all *t, int si)
{
	int		i;

	i = 0;
	t->size = ft_sqrt(4 * t->nb) + si;
	if (!(t->map = (char **)malloc(sizeof(char *) * t->size + 1)))
		return ;
	while (i < t->size)
	{
		t->map[i] = ft_strnew(t->size);
		i++;
	}
	t->map[i] = 0;
	dot_map(t);
}

void			free_map(t_all *m)
{
	int i;

	i = 0;
	while (i < m->size)
	{
		free(m->map[i]);
		i++;
	}
	free(m->map);
}

void			del_tetris(t_all *m, int a)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
		{
			if (m->map[i][j] == 'A' + a)
				m->map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int				ft_sqrt(int nb)
{
	int		i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

void			display(t_all *m)
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
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	free_map(m);
}
