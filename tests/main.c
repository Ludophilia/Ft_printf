/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:58:49 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/06 22:11:06 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	ft_printf("Ça marche frère.\n");
	ft_printf("Ça marche %d fois frère.\n", 0b101010);
	ft_printf("Ça marche toujours %i fois frère.\n", 0b101010);
	ft_printf("Ça marche %d et %i fois frère.\n", (0x2A | 0b1), 44);
	ft_printf("Ça marche %d et %i et %i fois frère.\n",
		-(0x2A | 0b1), -44, -0x2D);
	ft_printf("									"
			"									\n");
	ft_printf("%i as a char is '%c'\n", 0x2A, 42);
	ft_printf("									"
			"									\n");
	ft_printf("%u is UINT_MAX, basically\n", 4294967295U);
}

// Now we have to compile this main.
	// * ft_printf have to be compiled first as libftprintf.a and used as a lib
	// with this main
	// * libftprintf.a have to be compiled with libft.a
	// * libft.a have to be compiled from its sources. 
	// ...
