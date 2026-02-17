/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:48:15 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/10 14:48:15 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_load_images_next_next(void *mlx, t_map *map, int width,
		int height)
{
	map->wall2_img = mlx_xpm_file_to_image(mlx, "asset/wall2.xpm", &width,
			&height);
	if (!map->wall2_img)
	{
		ft_printf("Error\n cannot load wall2.xpm\n");
		ft_free_window_and_map(&map);
		exit(1);
	}
	map->player_img = mlx_xpm_file_to_image(mlx, "asset/player.xpm", &width,
			&height);
	if (!map->player_img)
	{
		ft_printf("Error\n cannot load player.xpm\n");
		ft_free_window_and_map(&map);
		exit(1);
	}
}

static void	ft_load_images_next(void *mlx, t_map *map, int width, int height)
{
	map->collec_img = mlx_xpm_file_to_image(mlx, "asset/collectible.xpm",
			&width, &height);
	if (!map->collec_img)
	{
		ft_printf("Error\ncannot load collectible.xpm\n");
		ft_free_window_and_map(&map);
		exit(1);
	}
	map->exit_img = mlx_xpm_file_to_image(mlx, "asset/exit.xpm", &width,
			&height);
	if (!map->exit_img)
	{
		ft_printf("Error\n cannot load exit.xpm\n");
		ft_free_window_and_map(&map);
		exit(1);
	}
	map->start_img = mlx_xpm_file_to_image(mlx, "asset/start.xpm", &width,
			&height);
	if (!map->start_img)
	{
		ft_printf("Error\n cannot load start.xpm\n");
		ft_free_window_and_map(&map);
		exit(1);
	}
	ft_load_images_next_next(mlx, map, width, height);
}

void	ft_load_images(void *mlx, t_map *map)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	map->floor_img = mlx_xpm_file_to_image(mlx, "asset/floor.xpm", &width,
			&height);
	if (!map->floor_img)
	{
		ft_printf("Error\n Cannot load floor.xpm\n");
		ft_free_window_and_map(&map);
		exit(1);
	}
	map->wall_img = mlx_xpm_file_to_image(mlx, "asset/wall.xpm", &width,
			&height);
	if (!map->wall_img)
	{
		ft_printf("Error\n Cannot load wall.xpm\n");
		ft_free_window_and_map(&map);
		exit(1);
	}
	ft_load_images_next(mlx, map, width, height);
}
