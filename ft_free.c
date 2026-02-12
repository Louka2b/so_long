/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:54:58 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/12 17:15:14 by ldeplace         ###   ########.fr       */
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
	mlx_destroy_image(map->mlx, map->floor_img);
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_image(map->mlx, map->collec_img);
	mlx_destroy_image(map->mlx, map->exit_img);
	mlx_destroy_image(map->mlx, map->start_img);
	mlx_destroy_image(map->mlx, map->wall2_img);
	mlx_destroy_image(map->mlx, map->player_img);
	// free(map->mlx);
	// free(map->mlx_win);
}
