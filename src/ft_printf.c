/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:41:49 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/09 17:36:47 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(va_list arguments, char format)
{
	if (format == 'c')
		return fd_putchar_fd(va_arg(arguments, char), 1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		lengh;
	va_list	arguments;

	va_start(arguments, str);
	i = 0;
	lengh = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			lengh += handle_format(arguments, str[i + 1]);
	}
	return (0);
}
