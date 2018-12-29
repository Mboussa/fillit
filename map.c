#include "fillit.h"

void	init_map(t_all tet, t_map *m)
{
	int		i;

	i = 0;
	m->size = ft_sqrt(tet.nb * 4);
	m->map = (char **)malloc(sizeof(char *) * m->size + 1);
	while (i < m->size)
	{
		m->map[i] = ft_strnew(m->size);
		i++;
	}
	m->map[i] = 0;
}

void	del_map(char **map)
{
	size_t i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

char	**map_new(char **map, int size)
{
	int x;
	int y;

	y = 0;
	if (!(map = (char**)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (y < size)
	{
		if (!(map[y] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = 0;
	return (map);
}

void ft_remove(char a, char **map, int size)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (x < size)
	{
		if (map[x][i] == a)
			map[x][i] = '.';
		i++;
		if (i == size)
		{
			i = 0;
			x++;
		}
	}
}
