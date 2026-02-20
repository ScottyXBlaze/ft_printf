/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:44:23 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/13 14:31:38 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		handle_format(va_list args, char format);
int		ft_printf(const char *str, ...);
int		check_validity(va_list args, const char *str, int *i);
int		safe_write(int fd, const void *buf, size_t count);
int		int_putchar(char str);
int		int_putstr(const char *str);
int		int_putnbr(int n);
int		int_utoa(unsigned int n);
int		int_puthex(unsigned long n, char format);
int		int_putptr(void *ptr);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
