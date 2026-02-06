/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:24:32 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 17:24:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_press_w(t_map *map)
{
    if(map->player_y > 0 && map->map[map->player_y - 1][map->player_x] != '1')
    {
        map->player_y = map->player_y - 1;
        map->player_move = map->player_move + 1;
        map->player_has_move = 1;
    }
}

void    ft_press_a(t_map *map)
{
    if(map->player_x > 0 && map->map[map->player_y][map->player_x - 1] != '1')
    {
        map->player_x = map->player_x - 1;
        map->player_move = map->player_move + 1;
        map->player_has_move = 1;
    }
}

void    ft_press_s(t_map *map)
{
    if(map->player_y < map->y && map->map[map->player_y + 1][map->player_x] != '1')
    {
        map->player_y = map->player_y + 1;
         map->player_move = map->player_move + 1;
         map->player_has_move = 1;
    }
}

void    ft_press_d(t_map *map)
{
    if(map->player_x < map->x && map->map[map->player_y][map->player_x + 1] != '1')
    {
        map->player_x = map->player_x + 1;
        map->player_move = map->player_move + 1;
        map->player_has_move = 1;
    }
}