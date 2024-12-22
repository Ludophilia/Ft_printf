/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t13p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/22 16:21:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t13.h"

int	test_s_bonus_flags_output_comparison_t0(void)
{
	int			ret;
	char		*format;

	format = "%0s %1s %10s %-10s\n";
	ret = PRINTF(format, "12345", "12345", "12345", "12345");
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_s_bonus_flags_output_comparison_t1(void)
{
	int			ret;
	char		*format;

	format = "%.5s%.6s\n";
	ret = PRINTF(format, NULL, NULL);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_s_bonus_flags_output_comparison_t2(void)
{
	int			ret;
	char		*format;

	format = "%.0s%.s%.s %.1s%.2s %.5s %.6s %.10s%.25s\n";
	ret = PRINTF(
			format, NULL, "12", "", "12345", "12345", NULL, NULL, "12345", "");
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_s_bonus_flags_output_comparison_t3(void)
{
	int			ret;
	char		*format;

	format = "%14.0s%-6.s %-17.1s%7.2s%9.5s%-8.6s%1.10s           \n";
	ret = PRINTF(
			format, NULL, "12" "12345", "12345", NULL, NULL, "12345");
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_s_bonus_flags_output_comparison_t0();
	test_s_bonus_flags_output_comparison_t1();
	test_s_bonus_flags_output_comparison_t2();
	test_s_bonus_flags_output_comparison_t3();
	return (0);
}
