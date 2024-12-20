/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t06p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/20 16:29:01 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t06.h"

int	test_format_str_with_decimal_specifier_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%d\n";
	ret[0] = printf(format, 0);
	ret[1] = ft_printf(format, 0);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_decimanl_specifier_return_value_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%i\n";
	ret[0] = printf(format, 0);
	ret[1] = ft_printf(format, 0);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_decimanl_specifier_return_value_t2(void)
{
	int			ret[2];
	char		*format;

	format = "%d%i%d%i%d%i%d\n";
	ret[0] = printf(format, -2147483648, -500, -10, 0, 10, 42, 2147483647);
	ret[1] = ft_printf(format, -2147483648, -500, -10, 0, 10, 42, 2147483647);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_decimanl_specifier_return_value_t3(void)
{
	int			ret[2];
	char		*format;

	format = "\r%d\xa%i\xb%d\t%i\n%d\x7f%i.%d?%i\n";
	ret[0] = printf(format, -2147483648, -500, -10, 0, 10, 42, 2147483647,
			2147483647l + 1);
	ret[1] = ft_printf(format, -2147483648, -500, -10, 0, 10, 42, 2147483647,
			2147483647l + 1);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_format_str_with_decimal_specifier_return_value_t0();
	test_format_str_with_decimanl_specifier_return_value_t1();
	test_format_str_with_decimanl_specifier_return_value_t2();
	test_format_str_with_decimanl_specifier_return_value_t3();
	return (0);
}
