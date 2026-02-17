/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:44:24 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/12 16:44:24 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *map)
{
	ft_free_window(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_free_map(&map, 0);
	exit(0);
	return (0);
}

int	ft_refresh(t_map *map)
{
	long long	time;
	char		*tmp;
	char		*tempo;

	time = get_time_ms();
	if (time - map->fps >= 16)
	{
		tmp = ft_itoa(map->player_move);
		tempo = ft_strjoin("player move : ", tmp);
		mlx_clear_window(map->mlx, map->mlx_win);
		ft_draw_map(map->mlx, map->mlx_win, map);
		ft_draw_map_next(map->mlx, map->mlx_win, map);
		ft_draw_map_next_next(map->mlx, map->mlx_win, map, 0);
		mlx_string_put(map->mlx, map->mlx_win, 20, 20, 2000000, tempo);
		map->fps = time;
		free(tmp);
		free(tempo);
	}
	return (0);
}

void	ft_check_la_map(t_map *map)
{
	if (map->map[map->player_y][map->player_x] == 'C')
		map->map[map->player_y][map->player_x] = '0';
	if (map->map[map->player_y][map->player_x] == 'E')
	{
		if (ft_count_collec(&map) == 0)
		{
			ft_printf("bravo tu es sorti\n");
			close_window(map);
			exit(0);
		}
	}
}

static void	printf_move(t_map *map)
{
	if (map->player_has_move == 1)
	{
		ft_printf("%d\n", map->player_move);
	}
}

int	handle_keypress(int keysym, t_map *map)
{
	map->player_has_move = 0;
	if (keysym == 65307 || keysym == 53)
	{
		close_window(map);
		exit(0);
	}
	if (keysym == 119 || keysym == 65362)
	{
		ft_press_w(map);
	}
	if (keysym == 65364 || keysym == 115)
	{
		ft_press_s(map);
	}
	if (keysym == 97 || keysym == 65361)
	{
		ft_press_a(map);
	}
	if (keysym == 100 || keysym == 65363)
	{
		ft_press_d(map);
	}
	printf_move(map);
	ft_check_la_map(map);
	return (0);
}
