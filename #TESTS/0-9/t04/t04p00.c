/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t04p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/03 18:11:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#ifndef DEBUG
# define DEBUG 0
#endif

int	test_format_str_with_str_specifier_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%s";
	ret[0] = printf(format, "");
	ret[1] = ft_printf(format, "");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_str_specifier_return_value_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%s";
	ret[0] = printf(format, NULL);
	ret[1] = ft_printf(format, NULL);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_str_specifier_return_value_t2(void)
{
	int			ret[2];
	char		*format;

	format = "%s";
	ret[0] = printf(format, "0123456789");
	ret[1] = ft_printf(format, "0123456789");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_str_specifier_return_value_t3(void)
{
	int			ret[2];
	char		*format;

	format = "%s%s%s%s";
	ret[0] = printf(format, "c", NULL, "\001\x80 \x7f franchement", "   \n");
	ret[1] = ft_printf(format, "c", NULL, "\001\x80 \x7f franchement", "   \n");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_str_specifier_return_value_t4(void)
{
	int			ret[2];
	char		*format;

	format = "oh%soooooouh%scomme%sc'est   %sbizarre%s!";
	ret[0] = printf(format, "c", NULL,
		"\001\x80\x7f franchement", "   \n", "");
	ret[1] = ft_printf(format, "c", NULL,
		"\001\x80\x7f franchement", "   \n", "");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	if (test_format_str_with_str_specifier_return_value_t0()
		&& test_format_str_with_str_specifier_return_value_t1()
		&& test_format_str_with_str_specifier_return_value_t2()
		&& test_format_str_with_str_specifier_return_value_t3()
		&& test_format_str_with_str_specifier_return_value_t4())
		return (0);
	return (1);
}
