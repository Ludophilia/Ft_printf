/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t00p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/29 15:30:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <assert.h>

#ifndef DEBUG
# define DEBUG 0
#endif
// #define NB "00-00"
// #define TITLE "null check, return values"
// #define OK_STATUS "[OK]"

int	test_null(void)
{
	int	ret[2];

	ret[0] = ft_printf(NULL);
	ret[1] = printf(NULL);
	if (DEBUG
		&& printf("ft_printf -> %i\n", ret[0])
		&& printf("printf -> %i\n", ret[1]))
		;
	assert(ret[0] == ret[1]);
	// printf("\033[1m"NB"\033[0m\t"TITLE"\t\t\033[1;32m"OK_STATUS"\033[0m\n");
	return (1);
}

int	main(void)
{
	if (test_null() == 1)
		return (0);
	return (1);
}
