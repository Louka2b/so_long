/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:36:46 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/26 14:19:52 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

t_map	*ft_parsing(char *map);
void	ft_error(int i);
void	ft_free_map(t_map **map, int i);
void	ft_error_free(int i, t_map **map);
void	ft_check_map(t_map **map);
void	ft_check_can_exit(t_map **map);
void	ft_check_wall(t_map **map);
void	ft_check_entry(t_map **map);
void	ft_check_exit(t_map **map);
void	ft_check_collec(t_map **map);
void	ft_check_caractere_ko(t_map **map);
int		ft_remove_newline(char *str);

#endif