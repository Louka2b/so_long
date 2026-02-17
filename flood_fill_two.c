/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:35:55 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/16 15:20:35 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_map *map_struct, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || y >= map_struct->y || x >= map_struct->x)
		return ;
	if (map_struct->map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	ft_flood_fill(map_struct, x + 1, y, visited);
	ft_flood_fill(map_struct, x - 1, y, visited);
	ft_flood_fill(map_struct, x, y + 1, visited);
	ft_flood_fill(map_struct, x, y - 1, visited);
}

void	ft_find_start(t_map map, int *x, int *y)
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
				return ;
			}
			j++;
		}
		i++;
	}
}
