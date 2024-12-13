/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t11p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/13 13:52:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t11.h"

int	test_format_str_with_every_specifier_return_value_t0(void)
{
	int			ret;
	char		*format;

	format = "wow!!\rAfter\xathis,\tonly\x7fspecifiers:" 
		"%%%p%%??????%c%s%s%d%i%u{]|+-#######%x%X,wow\n";
	ret = PRINTF(format,
		(void *)0x2A, 0, "miam", "", 2147483648, -10, 0xFFFFFFFF,
		0, 0xFFFFFFFF);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_format_str_with_every_specifier_return_value_t0();
	return (0);
}
