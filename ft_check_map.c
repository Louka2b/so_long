/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:10:54 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/04 18:26:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall(t_map **map)
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

void	ft_check_entry(t_map **map)
{
	int	i;
	int	tmp;
	int	j;

	tmp = 0;
	j = 0;
	i = 0;
	while (i < (*map)->y)
	{
		while (j < (*map)->x && (*map)->map[i][j])
		{
			if ((*map)->map[i][j] == 'P')
				tmp++;
			j++;
		}
		j = 0;
		i++;
	}
	if (tmp > 1)
		ft_error_free(2, map);
	if (tmp < 1)
		ft_error_free(3, map);
}

void	ft_check_exit(t_map **map)
{
	int	i;
	int	tmp;
	int	j;

	tmp = 0;
	j = 0;
	i = 0;
	while (i < (*map)->y)
	{
		while (j < (*map)->x && (*map)->map[i][j])
		{
			if ((*map)->map[i][j] == 'E')
				tmp++;
			j++;
		}
		j = 0;
		i++;
	}
	if (tmp > 1)
		ft_error_free(4, map);
	if (tmp < 1)
		ft_error_free(5, map);
}

void	ft_check_collec(t_map **map)
{
	int	i;
	int	tmp;
	int	j;

	tmp = 0;
	j = 0;
	i = 0;
	while (i < (*map)->y)
	{
		while (j < (*map)->x && (*map)->map[i][j])
		{
			if ((*map)->map[i][j] == 'C')
				tmp++;
			j++;
		}
		j = 0;
		i++;
	}
	if (tmp < 1)
		ft_error_free(6, map);
}
