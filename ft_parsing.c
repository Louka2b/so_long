/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:18 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/21 17:48:51 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	t_map	*ft_check_line(int fd, int j, int i)
{
	t_map	*map;

	i = 1;
	map = (t_map *)malloc(sizeof(t_map));
	map->map[0] = malloc(j * sizeof (char));
	map->map[0] = get_next_line(fd);
	map->x = ft_strlen(map->map[i]);
	while (ft_strlen(map->map[i - 1]) != 0)
	{
		map->map[i] = malloc(j * sizeof (char));
		map->map[i] = get_next_line(fd);
		map->x = ft_strlen(map->map[i]);
		i++;
	}
	map->y = i;
	return (map);
}

static int	ft_check_len_x(int path)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	i = ft_strlen(get_next_line(fd));
	if (i == 0)
		ft_error(2);
	while (i == 0)
	{
		j = i;
		i = ft_strlen(get_next_line(fd));
		if (i != j && i != 0)
		{
			close(fd);
			ft_error(3);
		}
	}
	close(fd);
	return (j);
}

static int	ft_get_len_y(char *path, int x)
{
	int	fd;
	int	i;

	i = 0;
	while (i > x)
	{
		i = ft_strlen(get_next_line(fd));
	}
	close(fd);
	return (i);
}

int	ft_parsing(char *map_path)
{
	t_map	*map;
	int		fd;
	int		x;
	int		y;

	x = ft_check_len_x(map_path);
	y = ft_get_len_y(map_path, x);
	if (size == 0)
		ft_error(2);
	fd = open(map_path, O_RDONLY);
	//faut rajouter la len y pour le maloc dans la fct de en dessou quand j'aurai le fct qui donnela len
	map = ft_check_line(fd, size);
	ft_check_map(map);
}
