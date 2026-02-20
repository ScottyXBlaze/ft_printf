/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:54:34 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/20 13:06:39 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	safe_write(int fd, const void *buf, size_t count)
{
	int		ret;
	size_t	i;

	i = 0;
	while (i < count)
	{
		ret = write(fd, (const char *)buf + i, count - i);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	return (i);
}

int	check_validity(va_list args, const char *str, int *i)
{
	int	err;

	if (str[*i] == '%')
	{
		if (str[*i + 1] == '\0')
			return (-1);
		err = handle_format(args, str[*i + 1]);
		*i += 2;
	}
	else
	{
		err = int_putchar(str[*i]);
		*i += 1;
	}
	if (err == -1)
		return (-1);
	return (err);
}