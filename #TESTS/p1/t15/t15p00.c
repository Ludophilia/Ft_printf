/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t15p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 18:48:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t15.h"

int	test_di_bonus_flags_return_values_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%0d %1i %4d%-4d %11i %-15d%-20i\n";
	ret[0] = printf(format, -1, -10, -42, -42, 2147483647, 2147483647,
		-2147483648);
	ret[1] = ft_printf(format, -1, -10, -42, -42, 2147483647, 2147483647,
		-2147483648);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

// a precision of zero means that nothing is displayed
int	test_di_bonus_flags_return_values_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%.i\n";//%.0d%.1i %.3d%.9i%.17d %.20i\n";
	ret[0] = printf(format, 0);//, 0 -10, -42, -42, 42, 0);
	ret[1] = ft_printf(format, 0);//, 0 -10, -42, -42, 42, 0);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

// int	test_di_bonus_flags_return_values_t1(void)
// {
// 	int			ret[2];
// 	char		*format;

// 	format = "%.i%.0d%.1i %.3d%.9i%.17d %.20i\n";
// 	ret[0] = printf(format, 0, 0 -10, -42, -42, 42, 0);
// 	ret[1] = ft_printf(format, 0, 0 -10, -42, -42, 42, 0);
// 	if (DEBUG
// 		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
// 		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
// 		;
// 	assert(ret[0] == ret[1]);
// 	return (1);
// }

// Last one is the ultimate a mix

int	main(void)
{
	test_di_bonus_flags_return_values_t0();
	test_di_bonus_flags_return_values_t1();
	return (0);
}
