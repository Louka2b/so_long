/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:24:29 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 15:24:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_map *map)
{
    mlx_destroy_window(map->mlx, map->mlx_win);
    exit(0);
    return (0);
}

int ft_refresh(t_map *map)
{
    mlx_clear_window(map->mlx, map->mlx_win);
    ft_draw_map(map->mlx, map->mlx_win, map);
    ft_draw_map_next(map->mlx, map->mlx_win, map);
    ft_draw_map_next_next(map->mlx, map->mlx_win, map, 64);
    return (0);
}

int handle_keypress(int keysym, t_map *map)
{
    if (keysym == 65307 || keysym == 53)
    {
        mlx_destroy_window(map->mlx, map->mlx_win);
        exit(0);
    }
    if (keysym == 119 || keysym == 65362)
    {
        ft_press_w(map);
    }
    return (0);
}