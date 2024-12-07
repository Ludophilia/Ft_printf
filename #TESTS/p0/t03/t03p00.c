/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t03p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/06 15:40:07 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t03.h"

int	test_format_str_with_c_specifier_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%c";
	ret[0] = ft_printf(format, 'c');
	ret[1] = printf(format, 'c');
	if (DEBUG
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_c_specifier_return_value_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%c%c%c%c";
	ret[0] = printf(format, 'c', 0, '\001', '\x80');
	ret[1] = ft_printf(format, 'c', 0, '\001', '\x80');
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_c_specifier_return_value_t2(void)
{
	int			ret[2];
	char		*format;

	format = "oh%cque%cse%cpasse%ct-il?";
	ret[0] = printf(format, 'c', 0, '\001', '\x80');
	ret[1] = ft_printf(format, 'c', 0, '\001', '\x80');
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	if (test_format_str_with_c_specifier_return_value_t0()
		&& test_format_str_with_c_specifier_return_value_t1()
		&& test_format_str_with_c_specifier_return_value_t2())
		return (0);
	return (1);
}
