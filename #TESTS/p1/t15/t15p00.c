/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t15p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/20 18:41:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t15.h"

int	test_di_bonus_flags_return_values_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%0d %1i %4d%-4d %11i %-15d%-20i\n";
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

int	test_di_bonus_flags_return_values_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%.i%.0d%.1i %.3d%.9i%.17d %.20i%.20d\n";
	ret[0] = printf(format, 0, 0, -10, -10, -42, -42, 0, 42);
	ret[1] = ft_printf(format, 0, 0, -10, -10, -42, -42, 0, 42);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t2(void)
{
	int			ret[2];
	char		*format;

	format = "%00d%00d%03d|%04i%05i%06d\n";
	ret[0] = printf(format, 0, 10, -10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, -10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t3(void)
{
	int			ret[2];
	char		*format;

	format = "%-00d%-00d%0-3d|%-04i%-05i%-06d\n";
	ret[0] = printf(format, 0, 10, -10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, -10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t4(void)
{
	int			ret[2];
	char		*format;

	format = "%00.d%00.d|%00.3d|%03.d|%04.i%05.i%06.d\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t5(void)
{
	int			ret[2];
	char		*format;

	format = "%-00.d%-00.d|%0-0.3d|%0-3.d|%0-4.i%-05.i%0-6.d\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t6(void)
{
	int			ret[2];
	char		*format;

	format = "%-00d%-00d|%0-03d|%0-3d|%0-4i%-05i%0-6d\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t7(void)
{
	int			ret[2];
	char		*format;

	format = "%- 0d% -0d|%- 3d|% -3d|% -4i%- 5i% -6d\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t8(void)
{
	int			ret[2];
	char		*format;

	format = "%- +0d% -0d|%- +3d|% +-3d|% +-4i%- +5i%+ -6d\n";
	ret[0] = printf(format, 0, 10, 0, 10, -10, -10, 10);
	ret[1] = ft_printf(format, 0, 10, 0, 10, -10, -10, 10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_di_bonus_flags_return_values_t9(void)
{
	int			ret[2];
	char		*format;

	format = "%-+ 00.d%-+ 00.d|% +0-0.3d|%+ 0-3.d|%+ 0-4.i%+ -05.i% +0-6.d\n";
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
	test_di_bonus_flags_return_values_t0();
	test_di_bonus_flags_return_values_t1();
	test_di_bonus_flags_return_values_t2();
	test_di_bonus_flags_return_values_t3();
	test_di_bonus_flags_return_values_t4();
	test_di_bonus_flags_return_values_t5();
	test_di_bonus_flags_return_values_t6();
	test_di_bonus_flags_return_values_t7();
	test_di_bonus_flags_return_values_t8();
	test_di_bonus_flags_return_values_t9();
	return (0);
}
