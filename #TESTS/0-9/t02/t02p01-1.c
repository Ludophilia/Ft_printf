/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t02p01-1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/29 17:18:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>

#ifndef DEBUG
# define DEBUG 0
#endif

int	test_format_str_without_spec_output_comparison(const char *format)
{
	int	ret[2];

	ret[0] = printf(format);
	if (DEBUG
			&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[1]))
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
