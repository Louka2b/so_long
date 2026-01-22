/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:36:46 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/22 11:59:46 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

t_map	*ft_parsing(char *map);
char	*get_next_line(int fd);
void	ft_error(int i);
int		ft_remove_newline(char *str);

#endif