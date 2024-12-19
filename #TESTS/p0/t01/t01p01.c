/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 17:36:04 by jegerman         ###   ########.fr       */
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
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	if (test_empty_str_output0())
		return (0);
	return (1);
}
