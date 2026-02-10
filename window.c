/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/01/28 00:54:01 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/28 00:54:01 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	ft_enter_player_pos(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (1)
	{
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->player_y = y;
				map->player_x = x;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_initwindow(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;

	window_width = map->x * 64;
	map->player_move = 0;
	ft_enter_player_pos(map);
	window_height = map->y * 64;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_width, window_height, "so_long");
	ft_load_images(mlx, map);
	ft_draw_map(mlx, mlx_win, map);
	ft_draw_map_next(mlx, mlx_win, map);
	ft_draw_map_next_next(mlx, mlx_win, map, 0);
	map->mlx = mlx;
	map->mlx_win = mlx_win;
	mlx_hook(map->mlx_win, 17, 0, close_window, map);
	mlx_key_hook(map->mlx_win, handle_keypress, map);
	mlx_loop_hook(mlx, ft_refresh, map);
	mlx_loop(mlx);
}
