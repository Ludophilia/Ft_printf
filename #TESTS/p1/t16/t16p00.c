/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t16p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/21 17:44:57 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t16.h"

int	test_u_bonus_flags_return_values_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%0u %1u %4u%-4u %11u %-15u%-20u\n";
	ret[0] = printf(format, -1, -10, -42, -42, 2147483647, 2147483647,
		-2147483648);
	ret[1] = ft_printf(format, -1, -10, -42, -42, 2147483647, 2147483647,
		-2147483648);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_u_bonus_flags_return_values_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%.u%.0u%.1u %.3u%.9u%.17u %.20u%.20u\n";
	ret[0] = printf(format, 0, 0, -10, -10, -42, -42, 0, 42);
	ret[1] = ft_printf(format, 0, 0, -10, -10, -42, -42, 0, 42);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_u_bonus_flags_return_values_t2(void)
{
	int			ret[2];
	char		*format;

	format = "%00u%00u%03u|%04u%05u%06u\n";
	ret[0] = printf(format, 0, 10, -10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, -10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_u_bonus_flags_return_values_t3(void)
{
	int			ret[2];
	char		*format;

	format = "%-00u%-00u%0-3u|%-04u%-05u%-06u\n";
	ret[0] = printf(format, 0, 10, -10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, -10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_u_bonus_flags_return_values_t4(void)
{
	int			ret[2];
	char		*format;

	format = "%00.u%00.u|%00.3u|%03.u|%04.u%05.u%06.u\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_u_bonus_flags_return_values_t5(void)
{
	int			ret[2];
	char		*format;

	format = "%-00.u%-00.u|%0-0.3u|%0-3.u|%0-4.u%-05.u%0-6.u\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_u_bonus_flags_return_values_t0();
	test_u_bonus_flags_return_values_t1();
	test_u_bonus_flags_return_values_t2();
	test_u_bonus_flags_return_values_t3();
	test_u_bonus_flags_return_values_t4();
	test_u_bonus_flags_return_values_t5();
	return (0);
}
