/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01p01-1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/03 14:27:16 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>

#ifndef DEBUG
# define DEBUG 0
#endif

int	test_empty_str_output1(void)
{
	int			ret;
	const char	*format;

	format = "\0";
	ret = ft_printf(format);
	if (DEBUG
			&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	if (test_empty_str_output1() == 1)
		return (0);
	return (1);
}
