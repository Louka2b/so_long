/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:18 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/16 12:44:39 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	t_map	*ft_check_line(int fd, int j, int y)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
	map->map = malloc((y + 1) * sizeof(char *));
	if (!map->map)
		exit(0);
	i = 0;
	while (i < y)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
		{
			ft_free_map(&map, 1);
			exit(1);
		}
		ft_remove_newline(map->map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->x = j;
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
	int		fd;
	int		y;
	char	*line;

	y = 0;
	fd = open(path, O_RDONLY);
	if (!fd)
		exit(0);
	line = get_next_line(fd);
	if (line && ft_strlen(line) > 0)
		y = 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		y++;
		free(line);
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
