/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 11:59:03 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/16 14:21:24 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_remove_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
		return (len - 1);
	}
	return (len);
}

void	ft_check_caractere_ko(t_map **map)
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
			if ((*map)->map[i][j] != 'E' && (*map)->map[i][j] != '0'
			&& (*map)->map[i][j] != 'P'
			&& (*map)->map[i][j] != '1' && (*map)->map[i][j] != 'C')
			{
				tmp++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (tmp > 0)
		ft_error_free(7, map);
}

int	ft_count_collec(t_map **map)
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
	return (tmp);
}

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
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
