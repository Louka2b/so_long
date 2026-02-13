/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:04 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/13 16:49:26 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 1)
	{
		ft_printf("Error\nerror map does not exist\n");
		exit(1);
	}
	if (i == 2)
	{
		ft_printf("Error\nempty map\n");
		exit(1);
	}
	if (i == 3)
	{
		ft_printf("Error\nthe map is not rectangular\n");
		exit(1);
	}
}

static void	ft_error_free_two(int i, t_map **map)
{
	if (i == 5)
	{
		ft_printf("Error\nthe map dosen't have any exit\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 6)
	{
		ft_printf("Error\nthe map dosen't have any collectible\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 7)
	{
		ft_printf("Error\nbad carectere in the map\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 8)
	{
		ft_printf("Error\nthe map can't be finish\n");
		ft_free_map(map, 1);
		exit(1);
	}
}

void	ft_error_free(int i, t_map **map)
{
	if (i == 1)
	{
		ft_printf("Error\nbad wall\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 2)
	{
		ft_printf("Error\nwe need 1 entry only in the map\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 3)
	{
		ft_printf("Error\nthe map dosen't have any entry\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 4)
	{
		ft_printf("Error\nwe need 1 exit only in the map\n");
		ft_free_map(map, 1);
		exit(1);
	}
	ft_error_free_two(i, map);
}
