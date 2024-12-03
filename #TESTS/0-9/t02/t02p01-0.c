/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t02p01-0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/03 14:37:35 by jegerman         ###   ########.fr       */
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
	int	ret;

	ret = printf(format);
	if (DEBUG
			&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}
