/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:36:17 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/10 11:42:26 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_len(long nbr)
{
	int	lengh;

	lengh = 0;
	if (nbr < 0)
		lengh++;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		lengh++;
	while (nbr != 0)
	{
		nbr /= 10;
		lengh++;
	}
	return (lengh);
}

int	int_utoa(unsigned int n)
{
	int		len;
	int	i;
	char 	*str;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[0] = '0';
	str[len] = 0;
	i = len - 1;
	while (nbr != 0)
	{
		str[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	write(1, str, len);
	free(str);
	return (len);
}