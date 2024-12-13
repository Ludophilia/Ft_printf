/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t13p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/13 16:41:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t13.h"

int	test_output_format_str_with_c_specifier_bonus_flags_t0(void)
{
	int			ret;
	char		*format;

	format = "%c%0c%15c%-15c%------2c\n";
	ret = PRINTF(format, 'z', 'x', 'a', 'm', 'l');
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_output_format_str_with_c_specifier_bonus_flags_t0();
	return (0);
}
