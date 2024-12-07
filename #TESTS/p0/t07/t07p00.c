/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t07p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/07 14:07:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t07.h"

int	test_format_str_with_unsigned_specifier_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%u";
	ret[0] = printf(format, 0);
	ret[1] = ft_printf(format, 0);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_unsigned_specifier_return_value_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%u%u%u%u%u%u";
	ret[0] = printf(format, 0, 10, 1000, 1001, 0xFFFFFFFF, 0xFFFFFFFFl + 2);
	ret[1] = ft_printf(format, 0, 10, 1000, 1001, 0xFFFFFFFF, 0xFFFFFFFFl + 2);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_unsigned_specifier_return_value_t2(void)
{
	int			ret[2];
	char		*format;

	format = "\r%u\xa%u\xb%u\t%u\n%u\x7f%u.%u?%u";
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
	test_format_str_with_unsigned_specifier_return_value_t0();
	test_format_str_with_unsigned_specifier_return_value_t1();
	test_format_str_with_unsigned_specifier_return_value_t2();
	return (0);
}
