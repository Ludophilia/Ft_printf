/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t02p01-main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:31:19 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/03 14:40:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	test_format_str_without_spec_output_comparison(const char *);

	if (test_format_str_without_spec_output_comparison("0")
		&& test_format_str_without_spec_output_comparison("0123456789")
		&& test_format_str_without_spec_output_comparison(
			"012345678901234567890123456789012345678901"))
		return (0);
	return (1);
}
