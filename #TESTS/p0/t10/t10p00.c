/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t10p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/07 17:11:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t10.h"

int	test_format_str_with_percent_specifier_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%%";
	ret[0] = printf(format);
	ret[1] = ft_printf(format);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_percent_specifier_return_value_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%%%%%%%%%%%%";
	ret[0] = printf(format);
	ret[1] = ft_printf(format);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_percent_specifier_return_value_t2(void)
{
	int			ret[2];
	char		*format;

	format = "\r%%\xa%%\xb%%\t%%\n%%\x7f%%.%%?%%";
	ret[0] = printf(format);
	ret[1] = ft_printf(format);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_format_str_with_percent_specifier_return_value_t0();
	test_format_str_with_percent_specifier_return_value_t1();
	test_format_str_with_percent_specifier_return_value_t2();
	return (0);
}
