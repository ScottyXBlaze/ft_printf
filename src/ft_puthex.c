/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:12:02 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/13 14:15:55 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_puthex(unsigned long n, char format)
{
	char		buf[32];
	const char	*digits;
	int			i;
	int			len;

	digits = "0123456789abcdef";
	if (format == 'X')
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
		if (safe_write(1, &buf[i], 1) == -1)
			return (-1);
	return (len);
}

int	int_putptr(void *ptr)
{
	int	len;
	int	ret;

	if (!ptr)
		return (safe_write(1, "(nil)", 5));
	len = safe_write(1, "0x", 2);
	if (len == -1)
		return (-1);
	ret = write_hex_unsigned((unsigned long)ptr, 'x');
	if (ret == -1)
		return (-1);
	return (len + ret);
}
