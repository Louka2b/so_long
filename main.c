/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:28:25 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/29 19:21:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_map	*map;
	t_mlx	*mlx;

	map = ft_parsing("test.txt");
	if (map)
		ft_printf("Map loaded: %d x %d\n", map->x, map->y);
	ft_initwindow(map);
	return (0);
}
