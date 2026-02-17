/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:54:58 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/17 12:08:31 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map **map, int i)
{
	int	j;

	j = 0;
	(void)i;
	while (j != (*map)->y)
	{
		free((*map)->map[j]);
		j++;
	}
	free((*map)->map);
	free((*map));
}

void	ft_free_window(t_map *map)
{
	if (!map || !map->mlx)
		return ;
	if (map->floor_img)
		mlx_destroy_image(map->mlx, map->floor_img);
	if (map->wall_img)
		mlx_destroy_image(map->mlx, map->wall_img);
	if (map->collec_img)
		mlx_destroy_image(map->mlx, map->collec_img);
	if (map->exit_img)
		mlx_destroy_image(map->mlx, map->exit_img);
	if (map->start_img)
		mlx_destroy_image(map->mlx, map->start_img);
	if (map->wall2_img)
		mlx_destroy_image(map->mlx, map->wall2_img);
	if (map->player_img)
		mlx_destroy_image(map->mlx, map->player_img);
}

void	ft_free_calloc(t_map **map)
{
	ft_free_map(map, 1);
	exit(1);
}

void	ft_free_window_and_map(t_map **map)
{
	if (!map || !*map)
		return ;
	ft_free_window(*map);
	ft_free_map(map, 0);
}
