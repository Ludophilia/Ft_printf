/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:14:43 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/05 17:17:38 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	int		counts[2];
	char	*str;

	str = "Hello\n";
	counts[0] = ft_printf(str);
	counts[1] = printf(str);
	ft_printf("counts[0] = %i\n", counts[0]);
	if (counts[0] != counts[1])
		return (1);
	str = "My name is %s\n";
	counts[0] = ft_printf(str, "Jotaro");
	counts[1] = printf(str, "Jotaro");
	ft_printf("counts[0] = %i\n", counts[0]);
	if (counts[0] != counts[1])
		return (1);
	str = "This ptr returns %p\n";
	counts[0] = ft_printf(str, 0);
	counts[1] = printf(str, 0);
	ft_printf("counts[0] = %i\n", counts[0]);
	if (counts[0] != counts[1])
		return (1);
	str = "42 formatted: '%-015i'\n";
	counts[0] = ft_printf(str, 42);
	counts[1] = printf(str, 42);
	ft_printf("counts[0] = %i\n", counts[0]);
	if (counts[0] != counts[1])
		return (1);
	str = "42 formatted: '%15i'\n";
	counts[0] = ft_printf(str, 42);
	counts[1] = printf(str, 42);
	ft_printf("counts[0] = %i\n", counts[0]);
	if (counts[0] != counts[1])
		return (1);
	str = "'%10.3s'\n";
	counts[0] = ft_printf(str, "banane");
	counts[1] = printf(str, "banane");
	ft_printf("counts[0] = %i\n", counts[0]);
	if (counts[0] != counts[1])
		return (1);
	return (0);
}
