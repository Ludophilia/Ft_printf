/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t14p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 17:42:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t14.h"

int	test_p_bonus_flags_output_comparison_t0(void)
{
	int			ret;
	char		*format;

	format = "%0p %1p %3p %11p %-15p\n";
	ret = PRINTF(format, NULL, NULL, NULL, NULL, NULL);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_p_bonus_flags_output_comparison_t1(void)
{
	int			ret;
	char		*format;

	format = "%0p %4p %9p %-12p\n";
	ret = PRINTF(format, (void *)0x12345, (void *)0x12345,
			(void *)0x12345, (void *)0x12345);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_p_bonus_flags_output_comparison_t0();
	test_p_bonus_flags_output_comparison_t1();
	return (0);
}
