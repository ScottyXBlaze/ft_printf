/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:44:23 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/13 14:12:10 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	int_putchar(char c);
int	int_putstr(const char *str);
int	int_utoa(unsigned int n);
int	int_puthex(unsigned int n, char format);
int	int_putptr(void *ptr);
int	check_validity(va_list args, const char *str, int *i);
int	safe_write(int fd, const void *buf, size_t count);
int	handle_format(va_list args, char format);

#endif
