/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t19p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/22 16:23:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t19.h"

int	test_mix_bonus_flags_output_comparison_t0(void)
{
	int			ret[2];
	char		*format;

	format = "wow!!\rAfter\xathis,\tonly\x7fspecifiers:" 
		"%%->%42p%-21p(%%??????%-33c%17c||%-15.5s%15.s;"
		"%10.19d%-10.19i,,%010i% 10d%- 10d;'\"%0+10d%0-+10i{}"
		"%20.25u%020u%-20.25u{]|+-#######"
		"%10.10x%10.10X,%-10.10x%-10.10X,"
		"%-0#10x%-0#10X"
		"wow, such insane\n";
	ret[0] = printf(format,
		(void *)0x2A, (void *)0xA2,
		0, 'x',
		"miam", NULL,
		2147483648, -10, 3, 3, 3, 3, 3,
		0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
		0x1234, 0x1234, 0x1234, 0x1234,
		0x1234, 0x1234);
	ret[1] = ft_printf(format,
		(void *)0x2A, (void *)0xA2,
		0, 'x',
		"miam", NULL,
		2147483648, -10, 3, 3, 3, 3, 3,
		0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
		0x1234, 0x1234, 0x1234, 0x1234,
		0x1234, 0x1234);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_mix_bonus_flags_output_comparison_t0();
	return (0);
}
