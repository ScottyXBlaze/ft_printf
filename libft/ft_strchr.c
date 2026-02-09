/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:11:20 by nyramana          #+#    #+#             */
/*   Updated: 2026/01/30 14:18:11 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			charc;

	charc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == charc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == charc)
		return ((char *)&s[i]);
	return (NULL);
}
