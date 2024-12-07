/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t07p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/07 14:50:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t07.h"

int	test_format_str_with_unsigned_specifier_return_value_t0(void)
{
	int			ret;
	char		*format;

	format = "%u";
	ret = PRINTF(format, 0);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_unsigned_specifier_return_value_t1(void)
{
	int			ret;
	char		*format;

	format = "%u%u%u%u%u%u";
	ret = PRINTF(format, 0, 10, 1000, 1001, 0xFFFFFFFF, 0xFFFFFFFFl + 2);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_unsigned_specifier_return_value_t2(void)
{
	int			ret;
	char		*format;

	format = "\r%u\xa%u\xb%u\t%u\n%u\x7f%u.%u?%u";
	ret = PRINTF(format, -2147483648, -500, -10, 0, 10, 42, 2147483647,
			2147483647l + 1);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_format_str_with_unsigned_specifier_return_value_t0();
	test_format_str_with_unsigned_specifier_return_value_t1();
	test_format_str_with_unsigned_specifier_return_value_t2();
	return (0);
}
