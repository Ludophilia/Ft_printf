/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t02p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/06 16:43:01 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t02.h"

int	test_format_str_without_spec_output_comparison(const char *format)
{
	int	ret;

	ret = PRINTF(format);
	if (DEBUG
		&& dprintf(2, PRINTF_STR"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	if (test_format_str_without_spec_output_comparison("0")
		&& test_format_str_without_spec_output_comparison("0123456789")
		&& test_format_str_without_spec_output_comparison(
			"012345678901234567890123456789012345678901"))
		return (0);
	return (1);
}
