/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/28 17:56:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>

#define DEBUG 0
#define NB "01"
#define TITLE "NULL check"

void	test_null(void)
{
	int	ret[2];

	ret[0] = ft_printf(NULL);
	ret[1] = printf(NULL);
	if (DEBUG
		&& printf("ft_printf -> %i\n", ret[0])
		&& printf("printf -> %i\n", ret[1]))
		;
	assert(ret[0] == ret[1]);
	printf("\033[1m"NB".\033[0m\t"TITLE"...\t\033[1;32m[OK]\033[0m\n");
}

int	main(void)
{
	test_null();
}
