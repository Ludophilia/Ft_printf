/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:43:04 by jgermany          #+#    #+#             */
/*   Updated: 2023/02/19 19:28:32 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	integer_specifier2(int do_it)
{
	int a, b, c, d, e, f;

	if (!do_it)
		return ;
	printf("Integer specifiers and flags with scanf:\n");
	printf("\tNormal %%d, Enter Decimal please\n");
	scanf("\n\t\x20%d", &a);
	printf("\tNormal %%d, Enter Octal please\n");
	scanf("\n\t\x20%d", &b);
	printf("\tNormal %%d, Enter Hex please\n");
	scanf("\n\t\x20%d", &c);
	printf("											"
		   "										  \n");
	printf("\tNormal %%i, Enter Decimal please\n");
	scanf("\n\t\x20%i", &d);
	printf("\tNormal %%i, Enter Octal please\n");
	scanf("\n\t\x20%i", &e);
	printf("\tNormal %%i, Enter Hex please\n");
	scanf("\n\t\x20%i", &f);
	printf("											"
		   "										  \n");
	printf("\tdecimal a = %d, octal b = %d, hex c = %d\n", a, b, c);
	printf("\tdecimal d = %i, octal e = %i, hex f = %i\n", d, e, f);
	printf("											"
		   "										  \n");
}
*/

void	format_string(int do_it)
{
	if (!do_it)
		return ;
	printf("No specifiers and flags:\n");
	printf("\t'Sh***ku I love you! *** motherfuckers!!'\n");
	printf("											"
		   "										  \n");
}

/*
void	format_string_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Not enough specifications or args:\n");
	printf("\t'English ***, do you speak it?'\n", 42); // -> warning, data arg 
		// not used by format string
	printf("											"
		   "										  \n");
}
*/

void	character_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Character specifiers and flags:\n");
	printf("%s'%c'\n", 
		"\tB16I Normal:\n\t\x20", 0x41); // -> (0x41)16 is (65)10
	printf("%s'%c'\n", 
		"\tB10I Normal:\n\t\x20", 65);
	printf("%s'%c'\n", 
		"\t-B10I Normal:\n\t\x20", -175); // -> -175 is 81 after 
		// unsigned char conversion
	printf("%s'%c'\n", 
		"\t-B8I Normal:\n\t\x20", -0276); // -> (-0276)8 is (66)10 after
		// unsigned char conversion
	printf("											"
		   "										  \n");
	printf("%s'%-c'\n",
		"\tB16I Left justified:\n\t\x20", 0x41);
	printf("											"
		   "										  \n");
}

/*
void	character_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Character specifiers errors:\n");
	printf("%s'%c'\n", 
		"\tSpecifier-argument Mismatch:\n\t\x20"); // -> replaced by nothing
	printf("											"
		   "										  \n");
	printf("%s'%c'\n", 
		"\t-B10FL Normal:\n\t\x20", 3.14); // Produces a warning that blocks
		// execution with -Werror : format specifies type 'int' but the argument
		// has type 'double'. Undefined behavior?
	printf("%s'%c'\n",
		"\tSTR Normal:\n\t\x20", "a"); // warning: format specifies type 'int'
		// but the argument has type 'char *'. // Undefined behavior?
	printf("											"
		   "										  \n");
	printf("%s'%04c'\n",
		"\tB16I Zero Padding + Len(4):\n\t\x20", 0x41); // flag 0 is undefinded 
		// behavior with c conversion specifier.
	printf("											"
		   "										  \n");
}
*/

void	string_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("String specifier and flags:\n");
	printf("%s'%s'%s''\n",
		"\tSTR(8) Normal:\n\t\x20", "je souis\x20", "travail");
	printf("%s'%s'%s''\n",
		"\tSTR(0) Normal:\n\t\x20", "je souis\x20", "");
	printf("											"
		   "										  \n");
	printf("%s'%s'%.2s''\n",
		"\tSTR(9), Precision(2):\n\t\x20", "je souis\x20", "yesouite");
		// Write 'ye', but why precision and not min length width ? Precision
		// affects the str length. Min length width affects how many characters
		// are rendered AT MINIMUM.
	printf("											"
		   "										  \n");
	printf("%s'%s'%1s''\n",
		"\tSTR(9) with 1 of min field width:\n\t\x20", "je souis\x20",
		"fresh af");
	printf("%s'%s'%20s''\n",
		"\tSTR(9) with 20 of min field width:\n\t\x20", "je souis\x20",
		"fresh af"); // 9/20 spots occuped, str is right justified.
	printf("											"
		   "										  	\n");
	printf("%s'%s'%-s''\n",
		"\tSTR(9) Left justified:\n\t\x20", "je souis\x20", "fresh af");
		// Does nothing
	printf("%s'%s'%-20s''\n",
		"\tSTR(9) with 20 of min field width, left justified:\n\t\x20", 
		"je souis\x20", "fresh af");
		// 9/20 spots occuped, str is left justified.
	printf("											"
		   "										  	\n");
}

/*
void	string_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("String specifier errors:\n");
	printf("%s'%s'\n", 
		"\tSpecifier-argument Mismatch:\n\t\x20"); // warning: more '%' 
		// conversions than data arguments. Segfault? (Null)? Undefined 
		// behavior ?
	printf("											"
		   "										 	\n");
	printf("%s'%s'\n",
		"\tMisplaced format specifiers:\n\t\x20", "%s %s %u %p"); // prints 
		// "%s %s %u %p".
	printf("											"
		   "										 	\n");
	printf("%s'%s'%020s''\n",
		"\tSTR(9) zero filled with 20 of min field width:\n\t\x20", 
		"je souis\x20", "fresh af"); // 9/20 spots occuped, str is right 
		// justified with 000000 on the left. Undefined behavior.
	printf("											"
		   "										 	\n");
	printf("%s'%s'%s''\n",
		"\tB10I Normal:\n\t\x20", "je souis\x20", 42); // warning: format 
		// specifies type 'char *' but the argument has type 'int'. And it's
		// segfaults...
	printf("%s'%s'%s''\n",
		"\t-B10FL Normal:\n\t\x20", "je souis\x20", -3.14); // warning: format 
		// specifies type 'char *' but the argument has type 'int'. And it's
		// segfaults...
	printf("%s'%s'%s''\n",
		"\tCR Normal:\n\t\x20", "je souis\x20", 'C'); // warning: format 
		// specifies type 'char *' but the argument has type 'int'. And it's
		// segfaults...	
	printf("											"
		   "										 	\n");
}
*/

void	integer_specifier1(int do_it)
{
	if (!do_it)
		return ;
	printf("Integer specifiers and flags:\n");
	printf("%s'%i,%d'\n",
		"\t-B10, Normal:\n\t\x20", -42, -42);
	printf("%s'%i,%d'\n",
		"\t+B10, Normal:\n\t\x20", 42, 42);
	printf("%s'%i,%d'\n", 
		"\t+B16, Normal:\n\t\x20", 0x2a, 0x2A);
	// printf("%s'%i, %d'\n", 
		// "\tB10 Float, Normal:\n\t\x20", 42.7, 42.7); //  warning: format
	// specifies type 'int' but the argument has type 'double' [-Wformat]
	printf("					\n");
	printf("%s'%-i,%-d'\n",
		"\t-B10, Left justified:\n\t\x20", -42, -42);
	printf("%s'%-i,%-d'\n",
		"\t+B10, Left justified:\n\t\x20", 42, 42);
	printf("					\n");
	printf("%s'% i,% d'\n",
		"\t-B10, Space with a pos number:\n\t\x20", -42, -42);
	printf("%s'% i,% d'\n",
		"\t-B8, Space with a pos number:\n\t\x20", -052, -052);
	printf("%s'% i,% d'\n",
		"\t+B10, Space with a pos number:\n\t\x20", 42, 42);
	// printf("\tString, Space with a pos number:\n\t\x20'% d'\n", "");
	printf("					\n");
	printf("%s'%+i,%+d'\n",
		"\t-B10, +/- Sign:\n\t\x20", -42, -42);
	printf("%s'%+i,%+d'\n",
		"\t+B10, +/- Sign:\n\t\x20", 42, 42);
	printf("					\n");
	printf("%s'%0i,%0d'\n",
		"\t-B10, Zero padding(0):\n\t\x20", -42, -42);
	printf("%s'%01i,%01d'\n",
		"\t-B10, Zero padding(1):\n\t\x20", -42, -42);
	printf("%s'%04i,%04d'\n",
		"\t-B10, Zero padding(4):\n\t\x20", -42, -42);
	printf("%s'%05i,%05d'\n",
		"\t+B10, Zero padding(5):\n\t\x20", 42, 42);
	// printf("%s'%05-i,%05-d'\n",
	// 	"\t-B10, Zero padding(5), Left justified:\n\t\x20", -42, -42); 
	// 	// 0 is ignored when - is present.
	printf("%s'%-05i,%-05d'\n",
		"\t+B10, Zero padding(5), Left justified:\n\t\x20", 42, 42); 
		// 0 is ignored when - is present.
	printf("					\n");
}

void	unsigned_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Unsigned Integer specifiers and flags:\n");
	printf("%s'%u,%d'\n",
		"\t-B10, Normal:\n\t\x20", -22, -22);
	printf("%s'%u,%d'\n",
		"\t+B10, Normal:\n\t\x20", 22, 22);
	printf("					\n");
	printf("%s'%-u,%-d'\n",
		"\t-B10, Left justified:\n\t\x20", -22, -22);
	printf("%s'%-u,%-d'\n",
		"\t+B10, Left justified:\n\t\x20", 22, 22);
	printf("					\n");
}

void	pointer_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Pointers specifier and flags:\n");
	int	*mf = malloc(1 * sizeof(int));
	printf("%s'%p'\n", 
		"\tPointer, Normal:\n\t\x20", mf);
	free(mf);
	printf("					\n");
}

void	hexadecimal_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Hexadecimal specifier and flags:\n");
	printf("%s'%x,%X'\n", 
		"\t-B16, Normal:\n\t\x20", -0xab2F, -0xab2F);
	printf("%s'%x,%X'\n", 
		"\t+B16, Normal:\n\t\x20", 0xab2F, 0xab2F);
	printf("					\n");
	printf("%s'%-x,%-X'\n",
		"\t-B16, Left justified:\n\t\x20", -0xab2F, -0xab2F);
	printf("%s'%-x,%-X'\n",
		"\t+B16, Left justified:\n\t\x20", 0xab2F, 0xab2F);
	printf("					\n");
	printf("%s'%#x,%#X'\n",
		"\t-B16, Alt form:\n\t\x20", -0xab2F, -0xab2F);
	printf("%s'%#x,%#X'\n",
		"\t-B16, Alt form:\n\t\x20", 0xab2F, 0xab2F);
	printf("					\n");
}

void	just_pourcent(int do_it)
{
	if (!do_it)
		return ;
	printf("%s'42%%'\n",
		"\tJust pourcent:\n\t\x20");
}

int	main(void)
{
	// integer_specifier2(1);

	format_string(1);
	// format_string_err(1);
	character_specifier(1);
	// character_specifier_err(1);
	string_specifier(1);
	// string_specifier_err(1);
	// integer_specifier1(1);
	// unsigned_specifier(1);
	// pointer_specifier(1);
	// hexadecimal_specifier(1);
	// just_pourcent(1);
	return (0);
}