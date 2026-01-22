/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:10:54 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/22 15:40:36 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_more_wall(t_map **map, int i)
{
	while (i != (*map)->y)
	{
		if ((*map)->map[i][(*map)->x] != '1' && (*map)->map[i][(*map)->x] != 0)
			ft_error_free(1, map);
		i++;
	}
	i = 0;
	while ((*map)->map[(*map)->y][i])
	{
		if ((*map)->map[0][i] != '1' && (*map)->map[0][i] != 0)
			ft_error_free(1, map);
		i++;
	}
}

static void	ft_check_wall(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->map[0][i])
	{
		if ((*map)->map[0][i] != '1' && (*map)->map[0][i] != 0)
			ft_error_free(1, map);
		i++;
	}
	i = 0;
	while (i != (*map)->y)
	{
		if ((*map)->map[i][0] != '1' && (*map)->map[i][0] != 0)
			ft_error_free(1, map);
		i++;
	}
	i = 0;
	ft_check_more_wall(map ,1);
}

void	ft_check_map(t_map **map)
{
	ft_check_wall(map);
}