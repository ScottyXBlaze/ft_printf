/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:41:49 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/10 17:23:52 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	int_putchar(char str)
{
	return (write(1, &str, 1));
}

int	int_putstr(const char *str)
{
	if (!str)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}

int	int_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	handle_format(va_list args, char format)
{
	if (!format)
		return (-1);
	if (format == 's')
		return (int_putstr(va_arg(args, char *)));
	else if (format == 'c')
		return (int_putchar(va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (int_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (int_utoa(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (int_puthex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (int_putptr(va_arg(args, void *)));
	else if (format == '%')
		return (int_putchar('%'));
	return (int_putchar(format));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		err;

	va_start(args, str);
	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			err =  handle_format(args, str[i + 1]);
			if (err == -1)
				return (-1);
			len += err;
			i++;
		}
		else
		{
			if ((len += int_putchar(str[i])) == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
