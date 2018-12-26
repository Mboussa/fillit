/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 15:09:01 by moboussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 19:11:12 by moboussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		countblock(char *str)
{
	int		i;
	int		block;

	block = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			block++;
		i++;
	}
	return (block + 1);
}

int		checkfile(char *str)
{
	int		i;
	int		nbline;
	int		nbcol;

	i = 0;
	nbline = 0;
	nbcol = 0;
	while (str[i])
	{
		if (nbcol == 4)
			nbcol = 0;
		while (str[i] != '\n' && str[i++])
			nbcol++;
		if (str[i] == '\n' || str[i] == '\0')
			nbline++;
		if (str[i] == '\n' && str[i + 1] == '\n' && nbline == 4)
		{
			nbline = 0;
			i++;
		}
		i++;
	}
	if (nbline == 4 && nbcol == 4)
		return (1);
	return (0);
}

int		checkblock(t_all tet, int x)
{
	int		i;
	int		j;
	int		hash;

	i = -1;
	hash = 0;
	while (i++ < MAX_X)
	{
		j = 0;
		while (j < MAX_Y)
		{
			if (tet.t[x].tetris[i][j] == '#')
			{
				hash++;
				if (tet.t[x].tetris[i][j + 1] == '#')
					hash++;
				if (tet.t[x].tetris[i + 1][j] == '#')
					hash++;
			}
			j++;
		}
	}
	if (hash == 8 || hash == 7)
		return (1);
	return (0);
}
