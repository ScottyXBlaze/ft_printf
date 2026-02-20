/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:09:12 by nyramana          #+#    #+#             */
/*   Updated: 2026/01/30 12:52:09 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*malloc_char(int len)
{
	char	*ptr;

	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	return (ptr);
}

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

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = malloc_char(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}
