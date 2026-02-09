/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:11:42 by nyramana          #+#    #+#             */
/*   Updated: 2026/01/30 14:46:45 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if ((!dst || !src) && n == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = dst_len;
	i = 0;
	if (n == 0 || n <= dst_len)
		return (src_len + n);
	if (dst_len < n - 1 && n > 0)
	{
		while (dst_len + i + 1 < n && src[i])
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (dst_len + src_len);
}
