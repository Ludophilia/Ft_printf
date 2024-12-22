/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t18p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/22 16:20:59 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t18.h"

int	test_pourcent_bonus_flags_output_comparison_t0(void)
{
	int			ret;
	char		*format;

	format = "%100%%-42%%99%%-41%%88%%-40%%98%%-39%%97%%-21%\n";
	ret = PRINTF(format);
	if (DEBUG
		&& dprintf(2, DBG_PRINTF"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	test_pourcent_bonus_flags_output_comparison_t0();
	return (0);
}
