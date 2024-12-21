/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t17p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/21 18:25:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t17.h"

int	test_xX_bonus_flags_return_values_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%0x %1X %4x%-4X %11x %-15X%-20x\n";
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

int	test_xX_bonus_flags_return_values_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%.x%.0X%.1X %.3X%.9x%.17x %.20x%.20x\n";
	ret[0] = printf(format, 0, 0, -10, -10, -42, -42, 0, 42);
	ret[1] = ft_printf(format, 0, 0, -10, -10, -42, -42, 0, 42);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_xX_bonus_flags_return_values_t2(void)
{
	int			ret[2];
	char		*format;

	format = "%00x%00X%03x|%04X%05x%06X\n";
	ret[0] = printf(format, 0, 10, -10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, -10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_xX_bonus_flags_return_values_t3(void)
{
	int			ret[2];
	char		*format;

	format = "%-00X%-00X%0-3X|%-04x%-05x%-06x\n";
	ret[0] = printf(format, 0, 10, -10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, -10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_xX_bonus_flags_return_values_t4(void)
{
	int			ret[2];
	char		*format;

	format = "%00.X%00.X|%00.3X|%03.x|%04.x%05.x%06.x\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_xX_bonus_flags_return_values_t5(void)
{
	int			ret[2];
	char		*format;

	format = "%-00.x%-00.x|%0-0.3X|%0-3.X|%0-4.x%-05.x%0-6.X\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_xX_bonus_flags_return_values_t6(void)
{
	int			ret[2];
	char		*format;

	format = "%-#00x%-#00x|%-#00.x%-#00.X%-0#0.x|%#0-0.3X"
		"|%0-#3.X|%#0-4.x%-#05.x%0-#6.X\n";
	ret[0] = printf(format, 0, 0, 0, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 0, 0, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_xX_bonus_flags_return_values_t0();
	test_xX_bonus_flags_return_values_t1();
	test_xX_bonus_flags_return_values_t2();
	test_xX_bonus_flags_return_values_t3();
	test_xX_bonus_flags_return_values_t4();
	test_xX_bonus_flags_return_values_t5();
	test_xX_bonus_flags_return_values_t6();
	return (0);
}
