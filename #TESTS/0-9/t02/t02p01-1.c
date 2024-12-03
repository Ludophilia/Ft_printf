/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t02p01-1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/03 14:33:41 by jegerman         ###   ########.fr       */
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

	ret = ft_printf(format);
	if (DEBUG
			&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}
