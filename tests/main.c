/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:58:49 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/09 22:37:14 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	ft_printf("Ça marche,,, mon frère.\n");
	ft_printf("Ça marche %d fois frère.\n", 0b101010);
	ft_printf("Ça marche toujours %i fois frère.\n", 0b101010);
	ft_printf("Ça marche %d et %i fois frère.\n", (0x2A | 0b1), 44);
	ft_printf("Ça marche %d et %i et %i fois frère.\n",
		-(0x2A | 0b1), -44, -0x2D);
	ft_printf("										"
			"									\n");
	ft_printf("%i as a char is '%c'\n", 0x2A, 42);
	ft_printf("									"
			"									\n");
	ft_printf("%u is UINT_MIN and %u is UINT_MAX, basically\n",
		0U, 4294967295U);
	ft_printf("-10 is %u as an unsigned int, -42 is %u, -1 is %u\n",
		-10, -42, -1);
	ft_printf("									"
			"									\n");
	ft_printf("-10 is %u as an unsigned int, -42 is %u, -1 is %u\n",
		-10, -42, -1);
	ft_printf("									"
			"									\n");
	ft_printf("je suis '%s'\n", "travail");
	ft_printf("je ne suis que %s, je n'ai pas de %s.\n", 
		"travail", "vie");
	ft_printf("									"
			"									\n");
	ft_printf("42 is %x in hex and %X in HEX\n", 42, 42);
	ft_printf("Int bounds: min as unsigned = %x, max = %X\n", 
		-0x7FFFFFFF, 0x80000000);
	ft_printf("									"
			"									\n");
	int	*pi, pj;
	pi = (int *)(uintptr_t)0x7FFFFFFF;
	pj = 0;
	ft_printf("pi = %p, pj = %p\n", pi, pj);
	ft_printf("									"
			"									\n");
	// printf("%Double pourcent: '%%', Triple pourcent: '%%%'\n");
	// error: more '%' conversions than data arguments (%D is interpreted as arg)
	// printf("Double pourcent: '%%', Triple pourcent: '%%%'\n");
	// error: invalid conversion specifier '\x0a' (%') (a % will open a % conversion request)
	// printf("Double pourcent: '%%', Triple pourcent: '%%%");
	// // error: incomplete format specifier. Better abandon that Triple pourcent.
	ft_printf("Double pourcent: '%%', quadruple pourcent: '%%%%'\n");
	ft_printf("10 pourcent signs in the row: '%%%%%%%%%%'\n");
	ft_printf("									"
			"									\n");
}

// Now we have to compile this main.
	// * ft_printf have to be compiled first as libftprintf.a and used as a lib
	// with this main
	// * libftprintf.a have to be compiled with libft.a
	// * libft.a have to be compiled from its sources. 
	// ...
