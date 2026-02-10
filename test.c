/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyramana <nyramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:39:02 by nyramana          #+#    #+#             */
/*   Updated: 2026/02/10 17:04:16 by nyramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	len;
	int	len2;
	int	saved_stdout;
	int	err1;
	int	err2;

	len = printf("Hello, %s! This is a number: %d\n", "world", 42);
	len2 = ft_printf("Hello, %s! This is a number: %d\n", "world", 42);
	printf("length Original: %d characters.\n", len);
	printf("length ft_printf: %d characters.\n", len2);

	saved_stdout = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	err1 = printf("This should fail: %d\n", 123);
	err2 = ft_printf("This should fail: %d\n", 123);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	printf("printf error return: %d\n", err1);
	printf("ft_printf error return: %d\n", err2);
	return (0);
}	