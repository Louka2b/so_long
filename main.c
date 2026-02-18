/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:28:25 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/17 19:32:26 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_not_ber(void)
{
	ft_printf("Error\nthe map is not in .ber format");
	exit(1);
}

static void	ft_check_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		ft_not_ber();
	i = i - 5;
	if (str[i] == '/')
		ft_not_ber();
	i++;
	if (str[i] != '.')
		ft_not_ber();
	i++;
	if (str[i] != 'b')
		ft_not_ber();
	i++;
	if (str[i] != 'e')
		ft_not_ber();
	i++;
	if (str[i] != 'r')
		ft_not_ber();
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\nso_long needs 1 arguments only");
		return (0);
	}
	ft_check_ber(argv[1]);
	map = ft_parsing(argv[1]);
	if (map)
		ft_printf("Map loaded: %d x %d\n", map->x, map->y);
	ft_initwindow(map);
	return (0);
}
