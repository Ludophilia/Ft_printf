/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/06 16:42:49 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t01.h"

int	test_empty_str_output0(void)
{
	int			ret;
	const char	*format;

	format = "\0";
	ret = PRINTF(format);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	if (test_empty_str_output0())
		return (0);
	return (1);
}
