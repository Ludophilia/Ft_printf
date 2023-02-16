/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:43:04 by jgermany          #+#    #+#             */
/*   Updated: 2023/02/16 23:29:18 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	just_format(int do_it)
{
	if (!do_it)
		return ;
	printf("No specifiers and flags:\n");
	printf("\t'Sh***ku I love you! *** motherfuckers!!'\n");
	printf("						\n");
}

void	character_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Character specifiers and flags:\n");
	printf("\tB16 Normal:\n\t\x20'%c'\n", 0x41);
	// printf("\tString Normal:\n\t\x20'%c'\n", "a"); /* warning: format 
		// specifies type 'int' but the argument has type 'char *' [-Wformat]
	printf("\tB16 Left justified:\n\t\x20'%-c'\n", 0x41);
	// printf("\tB16 Zero Padding(4):\n\t\x20'%04c'\n", 0x41); // Undefined
		// behavior
	printf("						\n");
}

void	string_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("String specifier and flags:\n");
	printf("\tString Normal:\n\t\x20je souis '%s'\n", "travail");
	printf("\tEmpty String Normal:\n\t\x20je souis '%s'\n", "");
	printf("\tString Left justified:\n\t\x20je souis '%-s'\n", "fresh af"); 
	// useless, no space
	printf("					\n");
}

void	integer_specifier1(int do_it)
{
	if (!do_it)
		return ;
	printf("Integer specifiers and flags:\n");
	printf("\t-B10, Normal:\n\t\x20'%i,%d'\n", -42, -42);
	printf("\t-B10, Left justified:\n\t\x20'%-i,%-d'\n", -42, -42);
	printf("\t-B10, Space with a pos number:\n\t\x20'% i,% d'\n", -42, -42);
	printf("\t-B10, Zero padding(5):\n\t\x20'%05i,%05d'\n", -42, -42);
	printf("\t-B10, +/- Sign:\n\t\x20'%+i,%+d'\n", -42, -42);
	printf("				\n"); // Synthesis, where?
	printf("\t+B10, Normal:\n\t\x20'%i,%d'\n", 42, 42);
	printf("\t+B10, Left justified:\n\t\x20'%-i,%-d'\n", 42, 42);
	printf("\t+B10, Space with a pos number:\n\t\x20'% i,% d'\n", 42, 42);
	printf("\t+B10, +/- Sign:\n\t\x20'%+i,%+d'\n", 42, 42);
	printf("\t+B10, Zero padding(5):\n\t\x20'%05i,%05d'\n", 42, 42);
	printf("				\n");
	printf("\tB16, Normal:\n\t\x20'%i,%d'\n", 0x2a, 0x2A);
	printf("\t-B8, Space with a pos number:\n\t\x20'% i,% d'\n", -052, -052);
	printf("				\n");
	// printf("% d\n", "");
	// printf("%i, %d\n", 42.7, 42.7); //  warning: format specifies type 'int'
	// but the argument has type 'double' [-Wformat]
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
	printf("%-u,%-d\n", -22, -22); // Left just, useless, no space
	printf("%u,%d\n", 22, 22);
	printf("%-u,%-d\n", 22, 22); // Left just, useless, no space
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
	printf("%x,%X\n", -0xab2F, -0xab2F);
	printf("%x,%X\n\n", 0xab2F, 0xab2F);
	printf("%-x,%-X\n", -0xab2F, -0xab2F); // Left just, useless, no space
	printf("%-x,%-X\n\n", 0xab2F, 0xab2F);
	printf("%#x,%#X\n", -0xab2F, -0xab2F); // Special Conv, add 0x
	printf("%#x,%#X\n\n", 0xab2F, 0xab2F); 
}

void	just_pourcent(int do_it)
{
	if (!do_it)
		return ;
	printf("42%%\n");
}

int	main(void)
{
	just_format(1);
	character_specifier(1);
	string_specifier(1);
	integer_specifier1(1);
	integer_specifier2(0);
	unsigned_specifier(0);
	pointer_specifier(0);
	hexadecimal_specifier(0);
	just_pourcent(0);
	return (0);
}