/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:18 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/21 15:16:08 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static	int	ft_check_line()

int	ft_parsing(char *map)
{
	int fd;

	fd = open(fd, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	ft_check_line(fd);
}