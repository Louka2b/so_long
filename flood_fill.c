/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:47:29 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/16 12:33:02 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill(char **map, int x, int y, char **visited)
{
	if (map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	ft_flood_fill(map, x + 1, y, visited);
	ft_flood_fill(map, x - 1, y, visited);
	ft_flood_fill(map, x, y + 1, visited);
	ft_flood_fill(map, x, y - 1, visited);
}

static void	ft_find_start(t_map map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.map[i][j] == 'P')
			{
				*y = i;
				*x = j;
			}
			j++;
		}
		i++;
	}
}

void			ft_check_can_exit(t_map **map)
{
	char	**visited;
	int		x;
	int		y;
	int		i;
	int		j;

	visited = (char **)ft_malloc_c(((*map)->y) * sizeof(char *));
	i = -1;
	while (++i < (*map)->y)
		visited[i] = ft_malloc_cc(visited[i], ((*map)->x + 1) * sizeof(char));
	ft_find_start(**map, &x, &y);
	ft_flood_fill((*map)->map, x, y, visited);
	i = -1;
	while (++i < (*map)->y)
	{
		j = -1;
		while (++j < (*map)->x)
			if (((*map)->map[i][j] == 'C' || (*map)->map[i][j] == 'E')
				&& !visited[i][j])
				ft_error_free(8, map);
	}
	i = -1;
	while (++i < (*map)->y)
		free(visited[i]);
	free(visited);
}
