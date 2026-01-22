/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:10:54 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/22 22:15:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_wall(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	j = (*map)->x - 1;
	if (j < 0)
		j = 0;
	while (i < (*map)->y)
	{
		if ((*map)->map[i][0] != '1')
			ft_error_free(1, map);
		if ((*map)->map[i][j] != '1')
			ft_error_free(1, map);
		i++;
	}
	i = 0;
	while (i < (*map)->x)
	{
		if ((*map)->map[0][i] != '1')
			ft_error_free(1, map);
		if ((*map)->map[(*map)->y - 1][i] != '1')
			ft_error_free(1, map);
		i++;
	}
}

static void	ft_check_entry(t_map **map)
{
	int i;
	int tmp;
	int j;

	tmp = 0;
	j = 0;
	while((*map)->map[i][j] && (*map)->y)
	{
		j = 0
		while((*map)->map[i][j])
		{
			j++;
			if((*map)->map[i][j] == 'E')
				tmp++;
		}
		i++;
	}
	if(tmp != 1)
		ft_error_free(2, map);
}

void	ft_check_map(t_map **map)
{
	ft_check_wall(map);
	ft_check_entry(map);
}