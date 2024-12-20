/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t06p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/20 16:49:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t06.h"

int	test_format_str_with_decimanl_specifier_return_value_t0(void)
{
	int			ret;
	char		*format;

	format = "%d";
	ret = PRINTF(format, 0);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_decimanl_specifier_return_value_t1(void)
{
	int			ret;
	char		*format;

	format = "%i";
	ret = PRINTF(format, 0);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_decimanl_specifier_return_value_t2(void)
{
	int			ret;
	char		*format;

	format = "%i%d";
	ret = PRINTF(format, -1, 0);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
			;
	return (1);
}

int	test_format_str_with_decimanl_specifier_return_value_t3(void)
{
	int			ret;
	char		*format;

	format = "%i%d%i%d%i%d%i";
	ret = PRINTF(format, -42, -2147483648, -10, 0, 10, 42, 2147483647);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
			;
	return (1);
}

int	test_format_str_with_decimanl_specifier_return_value_t4(void)
{
	int			ret;
	char		*format;

	format = "\r%d\xa%i\xb%d\t%i\n%d\x7f%i.%d?%i";
	ret = PRINTF(format, -2147483648, -500, -10, 0, 10, 42, 2147483647,
			2147483647l + 1);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_format_str_with_decimanl_specifier_return_value_t0();
	test_format_str_with_decimanl_specifier_return_value_t1();
	test_format_str_with_decimanl_specifier_return_value_t2();
	test_format_str_with_decimanl_specifier_return_value_t3();
	test_format_str_with_decimanl_specifier_return_value_t4();
	return (0);
}
