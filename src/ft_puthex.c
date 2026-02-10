/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:12:02 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/10 12:28:58 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hex_unsigned(unsigned long n, char format)
{
	char		buf[32];
	const char	*digits;
	int			i;
	int			len;

	if (format == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n > 0)
	{
		buf[i++] = digits[n % 16];
		n /= 16;
	}
	len = i;
	while (i-- > 0)
		write(1, &buf[i], 1);
	return (len);
}

int	int_puthex(unsigned int n, char format)
{
	return (write_hex_unsigned(n, format));
}

int	int_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += write_hex_unsigned((unsigned long)ptr, 'x');
	return (len);
}