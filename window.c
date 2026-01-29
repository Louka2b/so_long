/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:54:01 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/28 00:54:01 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static void	ft_draw_map_next_next(void *mlx, void *mlx_win, t_map *map, int tile_size)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == '1')
			{
				if (y == 0)
					mlx_put_image_to_window(mlx, mlx_win, map->wall2_img, x * tile_size, y * tile_size);
				else if (map->map[y - 1][x] != '1')
					mlx_put_image_to_window(mlx, mlx_win, map->wall_img, x * tile_size, y * tile_size);
				else
					mlx_put_image_to_window(mlx, mlx_win, map->wall2_img, x * tile_size, y * tile_size);
			}
			x++;
		}
		y++;
	}
}

static void	ft_draw_map_next(void *mlx, void *mlx_win, t_map *map)
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
				mlx_put_image_to_window(mlx, mlx_win, map->exit_img, x * tile_size, y * tile_size);
			if (map->map[y][x] == 'S')
				mlx_put_image_to_window(mlx, mlx_win, map->start_img, x * tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}

static void	ft_draw_map(void *mlx, void *mlx_win, t_map *map)
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

t_mlx	*ft_initwindow(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;
	t_mlx	*mlxall;

	window_width = map->x * 64;
	window_height = map->y * 64;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_width, window_height, "so_long");
	ft_load_images(mlx, map);
	ft_draw_map(mlx, mlx_win, map);
	ft_draw_map_next(mlx, mlx_win, map);
	ft_draw_map_next_next(mlx, mlx_win, map, 64);
	mlxall = malloc(sizeof (t_mlx));
	mlxall->mlx = mlx;
	mlxall->mlx_win = mlx_win;
	mlx_loop(mlx);
	return(mlxall);
}

// ft_refresh(t_map *map, void *mlx_win, void*mlx)
// {
// 	while(la croix et esc)
// 	{
// 		ft_draw_map(mlx, mlx_win, map);
// 		ft_draw_map_next(mlx, mlx_win, map);
// 		ft_draw_map_next_next(mlx, mlx_win, map, 64);
// 	}
// }