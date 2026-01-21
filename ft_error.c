/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:04 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/21 17:28:38 by ldeplace         ###   ########.fr       */
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
