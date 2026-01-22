/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:04 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/22 22:16:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 1)
	{
		perror("error map does not exist\n");
		exit(2);
	}
	if (i == 2)
	{
		perror("empty map\n");
		exit(2);
	}
	if (i == 3)
	{
		perror("the map is not rectangular\n");
		exit(2);
	}
}

void	ft_error_free(int i, t_map **map)
{
	if (i == 1)
	{
		perror("bad wall\n");
		ft_free_map(map, 1);
		exit(2);
	}
	if(i == 2)
	{
		perror("we need 1 entry only in the map\n");
		ft_free_map(map, 1);
		exit(2);
	}
}
