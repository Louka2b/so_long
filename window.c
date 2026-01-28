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

static void	ft_load_images_next(void *mlx, t_map *map, int width, int height)
{
	map->collec_img = mlx_xpm_file_to_image(mlx, "asset/collectible.xpm",
			&width, &height);
	if (!map->collec_img)
	{
		perror("Error: cannot load collection.xpm\n");
		ft_free_map(&map, 1);
		exit(1);
	}
	map->exit_img = mlx_xpm_file_to_image(mlx, "asset/exit.xpm", &width,
			&height);
	if (!map->exit_img)
	{
		perror("Error: cannot load exit.xpm\n");
		ft_free_map(&map, 1);
		exit(1);
	}
}

static void	ft_load_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	map->floor_img = mlx_xpm_file_to_image(mlx, "asset/floor.xpm", &width,
			&height);
	if (!map->floor_img)
	{
		perror("Error: Cannot load floor.xpm\n");
		ft_free_map(&map, 1);
		exit(1);
	}
	map->wall_img = mlx_xpm_file_to_image(mlx, "asset/wall.xpm", &width,
			&height);
	if (!map->wall_img)
	{
		perror("Error: Cannot load wall.xpm\n");
		ft_free_map(&map, 1);
		exit(1);
	}
	ft_load_images_next(mlx, map, width, height);
}

static void	ft_draw_map_next(void *mlx, void *mlx_win, t_map *map)
{
	int	x;
	int	y;
	int	tile_size;

	tile_size = 32;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, map->exit_img, x
					* tile_size, y * tile_size);
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

	tile_size = 32;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == '0')
				mlx_put_image_to_window(mlx, mlx_win, map->floor_img, x
					* tile_size, y * tile_size);
			else if (map->map[y][x] == '1')
				mlx_put_image_to_window(mlx, mlx_win, map->wall_img, x
					* tile_size, y * tile_size);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, map->collec_img, x
					* tile_size, y * tile_size);
			x++;
		}
		y++;
	}
}

void	ft_initwindow(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;

	window_width = map->x * 32;
	window_height = map->y * 32;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_width, window_height, "so_long");
	ft_load_images(mlx, map);
	ft_draw_map(mlx, mlx_win, map);
	ft_draw_map_next(mlx, mlx_win, map);
	mlx_loop(mlx);
}