/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 12:24:47 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/16 12:34:33 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_malloc_c(int size)
{
	char	**str;

	str = malloc(size);
	if (!str)
	{
		exit(0);
	}
	return (str);
}

char	*ft_malloc_cc(char *str, int size)
{
	str = malloc(size);
	if (!str)
	{
		exit(0);
	}	
	return (str);
}