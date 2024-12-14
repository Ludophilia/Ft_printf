/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t13p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/14 15:10:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t13.h"

int	test_format_str_with_str_specifier_bonus_flags_p0_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%0s %1s %10s %-10s\n";
	ret[0] = printf(format, "12345", "12345", "12345", "12345");
	ret[1] = ft_printf(format, "12345", "12345", "12345", "12345");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_str_specifier_bonus_flags_p1_return_value_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%.0s%.s %.1s%.2s %.5s %.6s %.10s\n";
	ret[0] = printf(
			format, NULL, "12" "12345", "12345", NULL, NULL, "12345");
	ret[1] = ft_printf(
			format, NULL, "12" "12345", "12345", NULL, NULL, "12345");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_str_specifier_bonus_flags_p01_return_value_t2(void)
{
	int			ret[2];
	char		*format;

	format = "%14.0s%-6.s %-17.1s%7.2s%9.5s%-8.6s%1.10s           \n";
	ret[0] = printf(
			format, NULL, "12" "12345", "12345", NULL, NULL, "12345");
	ret[1] = ft_printf(
			format, NULL, "12" "12345", "12345", NULL, NULL, "12345");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_format_str_with_str_specifier_bonus_flags_p0_return_value_t0();
	test_format_str_with_str_specifier_bonus_flags_p1_return_value_t1();
	test_format_str_with_str_specifier_bonus_flags_p01_return_value_t2();
	return (0);
}
