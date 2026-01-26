/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:18 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/26 14:09:20 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	t_map	*ft_check_line(int fd, int j, int y)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->map = (char **)malloc(y + 1);
	map->map[0] = malloc((j + 1) * sizeof (char));
	map->map[0] = get_next_line(fd);
	map->x = ft_strlen(map->map[i]);
	while (ft_strlen(map->map[i]) > (size_t)j)
	{
		i++;
		map->map[i] = malloc((j + 1) * sizeof (char));
		map->map[i] = get_next_line(fd);
		map->x = ft_strlen(map->map[i]);
	}
	map->y = y;
	return (map);
}

static void	ft_check_len_x_two(int *fd, char **line, char *path)
{
	(*fd) = open(path, O_RDONLY);
	if ((*fd) == -1)
		ft_error(1);
	(*line) = get_next_line((*fd));
	if (!(*line) || ft_strlen((*line)) == 0)
		ft_error(2);
}

static int	ft_check_len_x(char *path)
{
	int		fd;
	char	*line;
	int		j;
	int		i;

	ft_check_len_x_two(&fd, &line, path);
	j = ft_remove_newline(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		i = ft_remove_newline(line);
		if (i != j)
		{
			free(line);
			close(fd);
			ft_error(3);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (j);
}

static int	ft_get_len_y(char *path)
{
	int	fd;
	int	i;
	int	y;

	i = 0;
	y = 0;
	fd = open(path, O_RDONLY);
	i = ft_strlen(get_next_line(fd));
	while ((i) > 0)
	{
		i = ft_strlen(get_next_line(fd));
		y++;
	}
	close(fd);
	return (y);
}

t_map	*ft_parsing(char *map_path)
{
	t_map	*map;
	int		fd;
	int		x;
	int		y;

	x = ft_check_len_x(map_path);
	y = ft_get_len_y(map_path);
	fd = open(map_path, O_RDONLY);
	map = ft_check_line(fd, x, y);
	ft_check_wall(&map);
	ft_check_entry(&map);
	ft_check_exit(&map);
	ft_check_collec(&map);
	ft_check_caractere_ko(&map);
	ft_check_can_exit(&map);
	return (map);
}
