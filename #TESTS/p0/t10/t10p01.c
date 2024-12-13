/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t10p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/13 13:52:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t10.h"

int	test_format_str_with_percent_specifier_return_value_t0(void)
{
	int			ret;
	char		*format;

	format = "%%";
	ret = PRINTF(format);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_percent_specifier_return_value_t1(void)
{
	int			ret;
	char		*format;

	format = "%%%%%%%%%%%%";
	ret = PRINTF(format);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_percent_specifier_return_value_t2(void)
{
	int			ret;
	char		*format;

	format = "\r%%\xa%%\xb%%\t%%\n%%\x7f%%.%%?%%";
	ret = PRINTF(format);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_format_str_with_percent_specifier_return_value_t0();
	test_format_str_with_percent_specifier_return_value_t1();
	test_format_str_with_percent_specifier_return_value_t2();
	return (0);
}
