/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:36:46 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/29 19:23:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_map
{
    char    **map;
    int     x;
    int     y;         
    void    *floor_img;
    void    *wall_img;
	void	*collec_img;
	void	*exit_img;
    void    *start_img;
    void    *wall2_img;
} t_map;

typedef struct s_mlx
{
    void *mlx;
    void *mlx_win;
} t_mlx;

t_map	*ft_parsing(char *map);
t_mlx   *ft_initwindow(t_map *map);
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
void	ft_load_images(void *mlx, t_map *map);
void	ft_map_kaput(t_map *map);
int		ft_remove_newline(char *str);

#endif