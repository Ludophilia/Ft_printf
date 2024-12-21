/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t03p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/21 14:55:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t03.h"

int	test_format_str_with_c_specifier_return_value_t0(void)
{
	int			ret;
	char		*format;

	format = "%c\n";
	ret = PRINTF(format, 'c');
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_c_specifier_return_value_t1(void)
{
	int			ret;
	char		*format;

	format = "%c%c%c%c\n";
	ret = PRINTF(format, 'c', 0, '\001', '\x80');
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_c_specifier_return_value_t2(void)
{
	int			ret;
	char		*format;

	format = "oh%cque%cse%cpasse%ct-il?\n";
	ret = PRINTF(format, 'c', 0, '\001', '\x80');
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_format_str_with_c_specifier_return_value_t0();
	test_format_str_with_c_specifier_return_value_t1();
	test_format_str_with_c_specifier_return_value_t2();
	return (0);
}
