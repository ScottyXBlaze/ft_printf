/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:44:23 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/10 12:26:53 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	int_putstr(const char *str);
int	int_utoa(unsigned int n);
int	int_puthex(unsigned int n, char format);
int	int_putptr(void *ptr);

#endif
