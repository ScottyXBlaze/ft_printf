/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:09:20 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/07 11:55:47 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *ptr)
{
	t_list	*last;

	if (!lst || !ptr)
		return ;
	last = ft_lstlast(*lst);
	if (last == NULL)
		ft_lstadd_front(lst, ptr);
	else
		last->next = ptr;
}
