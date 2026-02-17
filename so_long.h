/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:36:46 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/17 12:07:24 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <sys/time.h>

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	int			player_y;
	int			player_x;
	int			player_move;
	int			player_has_move;
	void		*floor_img;
	void		*wall_img;
	void		*collec_img;
	void		*exit_img;
	void		*start_img;
	void		*wall2_img;
	void		*player_img;
	void		*mlx;
	void		*mlx_win;
	long long	fps;
}				t_map;

long long		get_time_ms(void);
t_map			*ft_parsing(char *map);
char			**ft_malloc_c(int size);
char			*ft_malloc_cc(char *str, int size);
void			ft_initwindow(t_map *map);
void			ft_error(int i);
void			ft_free_map(t_map **map, int i);
void			ft_error_free(int i, t_map **map);
void			ft_check_map(t_map **map);
void			ft_check_can_exit(t_map **map);
void			ft_free_calloc(t_map **map);
void			ft_free_window_and_map(t_map **map);
void			ft_check_wall(t_map **map);
void			ft_find_start(t_map map, int *x, int *y);
void			ft_flood_fill(t_map *map_struct, int x, int y, char **visited);
void			ft_check_entry(t_map **map);
void			ft_check_exit(t_map **map);
void			ft_check_collec(t_map **map);
void			ft_draw_map(void *mlx, void *mlx_win, t_map *map);
void			ft_draw_map_next(void *mlx, void *mlx_win, t_map *map);
void			ft_draw_map_next_next(void *mlx, void *mlx_win, t_map *map,
					int y);
void			ft_check_caractere_ko(t_map **map);
void			ft_free_window(t_map *map);
void			ft_press_w(t_map *map);
void			ft_press_a(t_map *map);
void			ft_press_s(t_map *map);
void			ft_check_la_map(t_map *map);
void			ft_press_d(t_map *map);
void			ft_load_images(void *mlx, t_map *map);
int				handle_keypress(int keysym, t_map *map);
int				close_window(t_map *map);
int				ft_count_collec(t_map **map);
int				ft_remove_newline(char *str);
int				ft_refresh(t_map *map);

#endif