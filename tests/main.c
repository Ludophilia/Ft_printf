/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:58:49 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 20:37:57 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "main.h"

void	decimal_specifier(unsigned char do_it)
{
	int	ft_proc, proc;

	if (!do_it)
		return ;
	ft_proc = ft_printf("123");
	proc = printf("123");
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_proc = ft_printf("123\n");
	proc = printf("123\n");
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_proc = ft_printf("%i\n", 123);
	proc = printf("%i\n", 123);
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_proc = ft_printf("%i123\n", 0);
	proc = printf("%i123\n", 0);
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_proc = ft_printf("%2i123\n", 0);
	proc = printf("%2i123\n", 0);
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_printf("Ça marche %d fois frère.\n", 0b101010);
	ft_printf("Ça marche toujours %i fois frère.\n", 0b101010);
	ft_printf("Ça marche %d et %i fois frère.\n", (0x2A | 0b1), 44);
	ft_proc = ft_printf("%d%i%i\n", -(0x2A | 0b1), -44, -0x2D);
	proc = printf("%d%i%i\n", -(0x2A | 0b1), -44, -0x2D);
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	printf("										"
		"										\n");
}

void	character_specifier(unsigned char do_it)
{
	int	ft_proc, proc;

	if (!do_it)
		return ;
	ft_proc = ft_printf("%i as a char is '%c'\n", 0x2A, 42);
	proc = ft_printf("%i as a char is '%c'\n", 0x2A, 42);
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_printf("										"
		"										\n");
}

void	unsigned_specifier(unsigned char do_it)
{
	int	ft_proc, proc;

	if (!do_it)
		return ;
	ft_proc = ft_printf("%u is UINT_MIN and %u is UINT_MAX, basically\n",
		0U, 4294967295U);
	proc = printf("%u is UINT_MIN and %u is UINT_MAX, basically\n",
		0U, 4294967295U);;
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_printf("-10 is %u as an unsigned int, -42 is %u, -1 is %u\n",
		-10, -42, -1);
	ft_printf("									"
			"									\n");
}

void	string_specifier(unsigned char do_it)
{
	int	ft_proc, proc;

	if (!do_it)
		return ;
	ft_printf("je suis '%s'\n", "travail");
	ft_proc = ft_printf("je ne suis que %s, je n'ai pas de %s.\n", 
		"travail", "vie");
	proc = printf("je ne suis que %s, je n'ai pas de %s.\n", 
		"travail", "vie");
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);	
	ft_printf("										"
			"									\n");
}

void	hexa_specifier(unsigned char do_it)
{
	int	ft_proc, proc;

	if (!do_it)
		return ;
	ft_proc = ft_printf("42 is %x in hex and %X in HEX\n", 42, 42);
	proc = printf("42 is %x in hex and %X in HEX\n", 42, 42);
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);	
	ft_printf("Int bounds: min as unsigned = %x, max = %X\n", 
		-0x7FFFFFFF, 0x80000000);
	ft_printf("										"
			"										\n");
}

void	pointer_specifier(unsigned char do_it)
{
	int	ft_proc, proc;
	int	*pi, *pj;

	if (!do_it)
		return ;
	pi = (int *)(uintptr_t)0x7FFFFFFF;
	pj = 0;
	ft_proc = ft_printf("pi = %p, pj = %p\n", pi, pj);
	proc = printf("pi = %p, pj = %p\n", pi, pj);
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc); // FALSE. pj is (nil) on linux
	ft_printf("									"
			"									\n");
}

void	pourcent_specifier(unsigned char do_it)
{
	int	ft_proc, proc;

	if (!do_it)
		return ;
	// printf("%Double pourcent: '%%', Triple pourcent: '%%%'\n");
	// error: more '%' conversions than data arguments (%D is interpreted as arg)
	// printf("Double pourcent: '%%', Triple pourcent: '%%%'\n");
	// error: invalid conversion specifier '\x0a' (%') (a % will open a % conversion request)
	// printf("Double pourcent: '%%', Triple pourcent: '%%%");
	// // error: incomplete format specifier. Better abandon that Triple pourcent.
	ft_proc = ft_printf("Double pourcent: '%%', quadruple pourcent: '%%%%'\n");
	proc = printf("Double pourcent: '%%', quadruple pourcent: '%%%%'\n");
	printf("\tft_proc = %i, proc = %i\n", ft_proc, proc);
	ft_printf("10 pourcent signs in the row: '%%%%%%%%%%'\n");
	ft_printf("									"
			"									\n");
}

int	main(void)
{
	decimal_specifier(0b00000001);
	character_specifier(0b00000001);
	unsigned_specifier(0b00000001);
	string_specifier(0b00000001);
	hexa_specifier(0b00000001);
	pointer_specifier(0b00000001);
	pourcent_specifier(0b00000001);
}