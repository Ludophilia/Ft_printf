/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:43:04 by jgermany          #+#    #+#             */
/*   Updated: 2023/02/15 22:20:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	just_format(int do_it)
{
	if (!do_it)
		return ;
	printf("Sh***ku I love you! *** motherfuckers!!\n");
}

void	character_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("%c\n", 0x41);
	// printf("%c\n", "a"); // warning: format specifies type 'int' but the argument has type 'char *' [-Wformat]
}

void	string_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("je souis '%s'\n", "travail");
	printf("je souis '%s'\n", "");

}

void	integer_specifier1(int do_it)
{
	if (!do_it)
		return ;
	printf("%i,%d\n", -42, -42);
	printf("% i,% d\n", -42, -42);
	printf("%+i,%+d\n\n", -42, -42);
	printf("%i,%d\n", 42, 42);
	printf("% i,% d\n", 42, 42);
	printf("%+i,%+d\n\n", 42, 42);
	printf("%i,%d\n", 0x2a, 0x2A);
	printf("% i,% d\n", -052, -052);
	// printf("% d\n", "");
	// printf("%i, %d\n", 42.7, 42.7); //  warning: format specifies type 'int' but the argument has type 'double' [-Wformat]
}

void	integer_specifier2(int do_it)
{
	int a, b, c;

	if (!do_it)
		return ;
	printf("Enter Decimal please\n");
	scanf("%d", &a);
	printf("Enter Octal please\n");
	scanf("%d", &b);
	printf("Enter Hex please\n");
	scanf("%d", &c);
	printf("a = %i, b = %i, c = %i\n", a, b, c);
}

void	unsigned_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("%u,%d\n", -22, -22);
	printf("%u,%d\n", 22, 22);
	printf("%u,%d\n", -7, -7);
	printf("%u,%d\n", 7, 7);
}

void	pointer_specifier(int do_it)
{
	int	*mf;

	if (!do_it)
		return ;
	mf = malloc(1 * sizeof(int));
	printf("%p\n", mf);
	free(mf);
}

void	hexadecimal_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("%x, %X\n", -0xab2F, -0xab2F);
	printf("%x, %X\n", 0xab2F, 0xab2F);
	printf("%#x, %#X\n", -0xab2F, -0xab2F);
	printf("%#x, %#X\n", 0xab2F, 0xab2F);
}

void	just_pourcent(int do_it)
{
	if (!do_it)
		return ;
	printf("42%%\n");
}

int	main(void)
{
	just_format(0);
	character_specifier(0);
	string_specifier(0);
	integer_specifier1(1);
	integer_specifier2(0);
	unsigned_specifier(0);
	pointer_specifier(0);
	hexadecimal_specifier(0);
	just_pourcent(0);
	return (0);
}