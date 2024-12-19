/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t14p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 17:34:13 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t14.h"

int	test_p_bonus_flags_return_values_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%0p %1p %3p %11p %-15p\n";
	ret[0] = printf(format, NULL, NULL, NULL, NULL, NULL);
	ret[1] = ft_printf(format, NULL, NULL, NULL, NULL, NULL);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_p_bonus_flags_return_values_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%0p %4p %9p %-12p\n";
	ret[0] = printf(format, (void *)0x12345, (void *)0x12345,
			(void *)0x12345, (void *)0x12345);
	ret[1] = ft_printf(format, (void *)0x12345, (void *)0x12345,
			(void *)0x12345, (void *)0x12345);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_p_bonus_flags_return_values_t0();
	test_p_bonus_flags_return_values_t1();
	return (0);
}
