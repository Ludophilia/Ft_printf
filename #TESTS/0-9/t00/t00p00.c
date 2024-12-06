/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t00p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/06 16:23:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t00.h"

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
	return (1);
}

int	main(void)
{
	if (test_null() == 1)
		return (0);
	return (1);
}
