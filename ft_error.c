/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:04 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/26 14:04:33 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 1)
	{
		perror("error map does not exist\n");
		exit(1);
	}
	if (i == 2)
	{
		perror("empty map\n");
		exit(1);
	}
	if (i == 3)
	{
		perror("the map is not rectangular\n");
		exit(1);
	}
}

static void	ft_error_free_two(int i, t_map **map)
{
	if (i == 5)
	{
		perror("the map dosen't have any exit\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 6)
	{
		perror("the map dosen't have any collectible\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 7)
	{
		perror("bad carectere in the map\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 8)
	{
		perror("the map can't be finish\n");
		ft_free_map(map, 1);
		exit(1);
	}
}

void	ft_error_free(int i, t_map **map)
{
	if (i == 1)
	{
		perror("bad wall\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 2)
	{
		perror("we need 1 entry only in the map\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 3)
	{
		perror("the map dosen't have any entry\n");
		ft_free_map(map, 1);
		exit(1);
	}
	if (i == 4)
	{
		perror("we need 1 exit only in the map\n");
		ft_free_map(map, 1);
		exit(1);
	}
	ft_error_free_two(i, map);
}
