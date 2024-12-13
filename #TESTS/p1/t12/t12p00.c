/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t12p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/13 15:41:15 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t12.h"

int	test_format_str_with_c_specifier_bonus_flags_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%c%0c%15c%-15c%------2c\n";
	ret[0] = printf(format, 'z', 'x', 'a', 'm', 'l');
	ret[1] = ft_printf(format, 'z', 'x', 'a', 'm', 'l');
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_format_str_with_c_specifier_bonus_flags_return_value_t0();
	return (0);
}
