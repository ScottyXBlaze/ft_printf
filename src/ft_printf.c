/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:41:49 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/13 14:18:55 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(va_list args, char format)
{
	int	ret;

	if (format == 's')
		return (int_putstr(va_arg(args, char *)));
	if (format == 'c')
		return (int_putchar(va_arg(args, int)));
	if (format == 'd' || format == 'i')
		return (int_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (int_utoa(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (int_puthex(va_arg(args, unsigned int), format));
	if (format == 'p')
		return (int_putptr(va_arg(args, void *)));
	if (format == '%')
		return (int_putchar('%'));
	ret = int_putchar('%');
	if (ret == -1)
		return (-1);
	return (ret + int_putchar(format));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		err;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		err = check_validity(args, str, &i);
		if (err == -1)
			return (-1);
		len += err;
	}
	va_end(args);
	return (len);
}
