/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:44:01 by ldeplace          #+#    #+#             */
/*   Updated: 2026/01/20 11:32:51 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_putnbr_unsigned_fd(unsigned int nb, size_t h);
size_t	ft_puthexx_fd(unsigned int nb, size_t	h);
size_t	ft_puthex_fd(unsigned int nb, size_t	h);
size_t	ft_strlen(const char *str);
size_t	ft_putchar(char c);
size_t	ft_putnbr(int nb, size_t h);
int		ft_printf(const char *s, ...);

#endif