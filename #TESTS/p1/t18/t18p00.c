/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t18p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/22 14:52:56 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t18.h"

int	test_pourcent_bonus_flags_return_values_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%100%%-42%%99%%-41%%88%%-40%%98%%-39%%97%%-21%\n";
	ret[0] = printf(format);
	ret[1] = ft_printf(format);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_pourcent_bonus_flags_return_values_t0();
	return (0);
}
