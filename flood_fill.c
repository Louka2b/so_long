/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:47:29 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/17 12:05:20 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_visited(char **visited, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

static char	**ft_allocate_visited(t_map **map)
{
	char	**visited;
	int		i;

	visited = (char **)malloc((*map)->y * sizeof(char *));
	if (!visited)
		ft_error_free(8, map);
	i = 0;
	while (i < (*map)->y)
	{
		visited[i] = (char *)malloc((*map)->x * sizeof(char));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			ft_error_free(8, map);
		}
		i++;
	}
	return (visited);
}

static void	ft_free_visited(char **visited, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	ft_check_unreachable_items(t_map **map, char **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map)->y)
	{
		j = 0;
		while (j < (*map)->x)
		{
			if (((*map)->map[i][j] == 'C' || (*map)->map[i][j] == 'E')
				&& !visited[i][j])
			{
				ft_free_visited(visited, (*map)->y);
				ft_error_free(8, map);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_can_exit(t_map **map)
{
	char	**visited;
	int		x;
	int		y;

	visited = ft_allocate_visited(map);
	ft_init_visited(visited, (*map)->y, (*map)->x);
	ft_find_start(**map, &x, &y);
	ft_flood_fill(*map, x, y, visited);
	ft_check_unreachable_items(map, visited);
	ft_free_visited(visited, (*map)->y);
}
