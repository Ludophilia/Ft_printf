/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t08p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/07 16:29:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t08.h"

int	test_format_str_with_lowercase_hex_specifier_return_value_t0(void)
{
	int			ret;
	char		*format;

	format = "%x";
	ret = PRINTF(format, 0);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_lowercase_hex_specifier_return_value_t1(void)
{
	int			ret;
	char		*format;

	format = "%x%x%x%x%x%x";
	ret = PRINTF(format, 10, 0, -1, 1001, 0xFFFFFFFF, 0xFFFFFFFFl + 42);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_lowercase_hex_specifier_return_value_t2(void)
{
	int			ret;
	char		*format;

	format = "\r%x\xa%x\xb%x\t%x\n%x\x7f%x.%x?%x";
	ret = PRINTF(format, -2147483648, -500, -10, 0, 10, 42, 2147483647,
			2147483647l + 1);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_format_str_with_lowercase_hex_specifier_return_value_t0();
	test_format_str_with_lowercase_hex_specifier_return_value_t1();
	test_format_str_with_lowercase_hex_specifier_return_value_t2();
	return (0);
}
