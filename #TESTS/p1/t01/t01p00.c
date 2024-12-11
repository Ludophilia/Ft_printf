/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/06 15:44:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t01.h"

int	test_empty_str_return_value(void)
{
	int			ret[2];
	const char	*format;

	format = "\0";
	ret[0] = ft_printf(format);
	ret[1] = printf(format);
	if (DEBUG
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	if (test_empty_str_return_value())
		return (0);
	return (1);
}
