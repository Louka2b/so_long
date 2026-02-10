/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/02/04 15:23:27 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 15:23:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map_next_next(void *mlx, void *mlx_win, t_map *map,
		int y)
{
	int	x;

	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == '1')
			{
				if (y == 0)
					mlx_put_image_to_window(mlx, mlx_win, map->wall2_img, x
						* 64, y * 64);
				else if (map->map[y - 1][x] != '1')
					mlx_put_image_to_window(mlx, mlx_win, map->wall_img, x
						* 64, y * 64);
				else
					mlx_put_image_to_window(mlx, mlx_win, map->wall2_img, x
						* 64, y * 64);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, map->player_img, map->player_x
		* 64, map->player_y * 64);
}

void	ft_draw_map_next(void *mlx, void *mlx_win, t_map *map)
{
	int	x;
	int	y;
	int	tile_size;

	tile_size = 64;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, map->exit_img, x
					* tile_size, y * tile_size);
			if (map->map[y][x] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, map->start_img, x
					* tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}

void	ft_draw_map(void *mlx, void *mlx_win, t_map *map)
{
	int	x;
	int	y;
	int	tile_size;

	tile_size = 64;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == '0')
				mlx_put_image_to_window(mlx, mlx_win, map->floor_img, x
					* tile_size, y * tile_size);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, map->collec_img, x
					* tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}
