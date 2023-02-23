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
		"\tB16I standard %c specifier:\n\t\x20", 0x41); // -> (0x41)16 is (65)10
	printf("%s'%c'\n", 
		"\tB10I standard %c specifier:\n\t\x20", 65);
	printf("%s'%c'\n", 
		"\t-B10I standard %c specifier:\n\t\x20", -175); // -> -175 is 81 after 
		// unsigned char conversion
	printf("%s'%c'\n", 
		"\t-B8I standard %c specifier:\n\t\x20", -0276); // -> (-0276)8 is (66)10 after
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
		"\t-B10FL Wrong type:\n\t\x20", 3.14); // Produces a warning that blocks
		// execution with -Werror : format specifies type 'int' but the argument
		// has type 'double'. Undefined behavior?
	printf("%s'%c'\n",
		"\tSTR Wrong type:\n\t\x20", "a"); // warning: format specifies type 
		// 'int' but the argument has type 'char *'. // Undefined behavior?
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
		"\tSTR(8) standard %s specifier:\n\t\x20", "je souis\x20", "travail");
	printf("%s'%s'%s''\n",
		"\tSTR(0) standard %s specifier:\n\t\x20", "je souis\x20", "");
	printf("											"
		   "										  \n");
	printf("%s'%s'%.2s''\n",
		"\tSTR(9), Precision(2):\n\t\x20", "je souis\x20", "yesouite");
		// Write 'ye', but why precision and not min length width ? Precision
		// affects the str length. Min length width affects how many characters
		// are rendered AT MINIMUM.
	printf("											"
		   "											\n");
	printf("%s'%s'%1s''\n",
		"\tSTR(9) Min Field Length(1):\n\t\x20", "je souis\x20",
		"fresh af");
	printf("%s'%s'%20s''\n",
		"\tSTR(9) Min Field Length(20):\n\t\x20", "je souis\x20",
		"fresh af"); // 9/20 spots occuped, str is right justified.
	printf("											"
		   "										  	\n");
	printf("%s'%s'%-s''\n",
		"\tSTR(9) Left justified:\n\t\x20", "je souis\x20", "fresh af");
		// Does nothing
	printf("%s'%s'%-20s''\n",
		"\tSTR(9) Left justified + Min Field Length(20):\n\t\x20", 
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
		"\tB10I Wrong type:\n\t\x20", "je souis\x20", 42); // warning: format 
		// specifies type 'char *' but the argument has type 'int'. And it
		// segfaults...
	printf("%s'%s'%s''\n",
		"\t-B10FL Wrong type:\n\t\x20", "je souis\x20", -3.14); // warning:  
		// format specifies type 'char *' but the argument has type 'int'. And 
		// it segfaults...
	printf("%s'%s'%s''\n",
		"\tCR Wrong type:\n\t\x20", "je souis\x20", 'C'); // warning: format 
		// specifies type 'char *' but the argument has type 'int'. And it
		// segfaults...	
	printf("											"
		   "										 	\n");
}
*/

void	integer_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Integer specifiers and flags:\n");
	printf("%s'%i,%d'\n",
		"\t-B10I, standard %i,%d specifier:\n\t\x20", -42, -42);
	printf("%s'%i,%d'\n",
		"\t+B10I, standard %i,%d specifier:\n\t\x20", 42, 42);
	printf("%s'%i,%d'\n", 
		"\t+B16I, standard %i,%d specifier:\n\t\x20", 0x2a, 0x2A);
	printf("											"
		   "										 	\n");
	printf("%s'% i,% d'\n",
		"\t-B10I, Space +:\n\t\x20", -42, -42);
	printf("%s'% i,% d'\n",
		"\t-B8I, Space +:\n\t\x20", -052, -052);
	printf("%s'% i,% d'\n",
		"\t+B10I, Space +:\n\t\x20", 42, 42);
	printf("											"
		   "										 	\n");
	printf("%s'%+i,%+d'\n",
		"\t-B10I, +/- Sign:\n\t\x20", -42, -42);
	printf("%s'%+i,%+d'\n",
		"\t+B10I, +/- Sign:\n\t\x20", 42, 42);
	printf("											"
		   "										 	\n");
	printf("%s'%-i,%-d'\n",
		"\t-B10I, Left justified:\n\t\x20", -42, -42); // Useless
	printf("%s'%-i,%-d'\n",
		"\t+B10I, Left justified:\n\t\x20", 42, 42); // Useless
	printf("											"
		   "										 	\n");
	printf("%s'%1i,%1d'\n",
		"\t-B10I, Min Field Length(1):\n\t\x20", -42, -42);
	printf("%s'%4i,%4d'\n",
		"\t-B10I, Min Field Length(4): \n\t\x20", -42, -42);
	printf("%s'%10i,%10d'\n",
		"\t+B10I, Min Field Length(10):\n\t\x20", 42, 42);
	printf("											"
		   "										 	\n");
	printf("%s'%-1i,%-1d'\n",
		"\t-B10I, Min Field Length(1) + Left justified:\n\t\x20",
		-42, -42);
	printf("%s'%-4i,%-4d'\n",
		"\t-B10I, Min Field Length(4) + Left justified: \n\t\x20",
		-42, -42);
	printf("%s'%-10i,%-10d'\n",
		"\t+B10I, Min Field Length(5) + Left justified:\n\t\x20",
		42, 42);
	printf("											"
		   "										 	\n");	
	printf("%s'%0i,%0d'\n",
		"\t-B10I, Zero padding:\n\t\x20", -42, -42);
	printf("%s'%01i,%01d'\n",
		"\t-B10I, Zero padding + Min Field Length(1)\n\t\x20",
		-42, -42);
	printf("%s'%04i,%04d'\n",
		"\t-B10I, Zero padding + Min Field Length(4)\n\t\x20",
		-42, -42);
	printf("%s'%010i,%010d'\n",
		"\t+B10I, Zero padding + Min Field Length(10):\n\t\x20",
		42, 42);
	printf("											"
		   "										 	\n");
	printf("%s'%.i,%.d'\n",
		"\t-B10I, Precision(0):\n\t\x20", -42, -42); 
		// Set 0 as the minimum nb digit to appear. Does nothing, here.
	printf("%s'%.1i,%.1d'\n",
		"\t-B10I, Precision(1):\n\t\x20", -42, -42); 
		// Set 1 as the minimum nb digit to appear. Does nothing, here.
	printf("%s'%.10i,%.10d'\n",
		"\t-B10I, Precision(10):\n\t\x20", -42, -42);
		// Set 10 as the minimum nb digit to appear. // Adds 8 zeros before 42.
	printf("											"
		   "										 	\n");
}

/*
void	integer_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Integer specifiers err:\n");
	printf("%s'%i, %d'\n", 
		"\tB10 FL, Wrong type:\n\t\x20", 42.7, 42.7); //  warning: format
	// specifies type 'int' but the argument has type 'double' [-Wformat]
	printf("%s'%i, %d'\n", 
		"\tSTR(0), Wrong type:\n\t\x20", "", ""); //  warning: format
	// specifies type 'int' but the argument has type 'char *' [-Wformat]
	printf("											   "
	   	   "										 	\n");
	printf("%s'%-01i,%01d'\n",
		"\t-B10I, Zero padding + Left Justified + Min Field Length(1)\n\t\x20",
		-42, -42); // warning: flag '0' is ignored when flag '-' is present 
		// [-Wformat]
	printf("%s'%-04i,%04d'\n",
		"\t-B10I, Zero padding + Left Justified + Min Field Length(4)\n\t\x20",
		-42, -42); // warning: flag '0' is ignored when flag '-' is present 
		// [-Wformat]
	printf("%s'%-010i,%-010d'\n",
		"\t+B10I, Zero padding + Left Justified + Min Field Length(10):\n\t\x20",
		42, 42); // warning: flag '0' is ignored when flag '-' is present
		// [-Wformat]
	printf("											"
		   "										 	\n");
}
*/

void	unsigned_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Unsigned Integer specifiers and flags:\n");
	printf("%s'%u,%d'\n",
		"\t-B10I, standard %u specifier:\n\t\x20", -22, -22);
	printf("%s'%u,%d'\n",
		"\t+B10I, standard %u specifier:\n\t\x20", 22, 22);
	printf("%s'%u,%d'\n",
		"\t+B16UI, standard %u specifier:\n\t\x20", 0xFFFFFFFF, 0xFFFFFFFF);
	printf("%s'%u,%d'\n",
		"\t+B8UI, standard %u specifier:\n\t\x20", 037777777013, 037777777013);
	printf("											"
		   "										 	\n");
	printf("%s'%2u,%2d'\n",
		"\t+B10UI, Min Field Length(2):\n\t\x20", 2294966795U, 2294966795U);
	printf("%s'%12u,%12d'\n",
		"\t+B16UI, Min Field Length(12):\n\t\x20", 0xFFFFFFFF, 0xFFFFFFFF);
	printf("%s'%20u,%20d'\n",
		"\t+B8UI, Min Field Length(20):\n\t\x20", 037772154013, 037777777013);
	printf("											"
		   "										 	\n");
	printf("%s'%-u,%-d'\n",
		"\t+B10I, Left justified:\n\t\x20", 22, 22);
	printf("%s'%-2u,%-2d'\n",
		"\t+B10UI, Left justified + Min Field Length(13):\n\t\x20",
		2294966795U, 2294966795U);
	printf("%s'%-13u,%-13d'\n",
		"\t+B10UI, Left justified + Min Field Length(13):\n\t\x20",
		2294966795U, 2294966795U);
	printf("%s'%-19u,%-19d'\n",
		"\t+B16UI, Left justified + Min Field Length(19):\n\t\x20", 
		0xFFFFFFFF, 0xFFFFFFFF);
	printf("											"
		   "										 	\n");
	printf("%s'%.2u,%.2d'\n",
		"\t+B10UI, Precision(2):\n\t\x20", 2294966795U, 2294966795U);
	printf("%s'%.12u,%.12d'\n",
		"\t+B16UI, Precision(12):\n\t\x20", 0xFFFFFFFF, 0xFFFFFFFF);
	printf("%s'%.20u,%.20d'\n",
		"\t+B8UI, Precision(20):\n\t\x20", 037772154013, 037777777013);
	printf("											"
		   "										 	\n");
	printf("%s'%25.20u,%25.20d'\n",
		"\t+B10UI, Min Field Length(25) + Precision(20):\n\t\x20", 
		2294966795U, 2294966795U);
	printf("											"
		   "										 	\n");
	printf("%s'%0u,%0d'\n",
		"\t+B10UI, Zero padding:\n\t\x20", 
		2294966795U, 2294966795U);
	printf("%s'%010u,%010d'\n",
		"\t+B10UI, Zero padding + Min Field Length(10):\n\t\x20", 
		2294966795U, 2294966795U);
	printf("%s'%015u,%015d'\n",
		"\t+B10UI, Zero padding + Min Field Length(15):\n\t\x20", 
		2294966795U, 2294966795U);
	printf("%s'%025u,%025d'\n",
		"\t+B10UI, Zero padding + Min Field Length(25):\n\t\x20", 
		2294966795U, 2294966795U);
	printf("											"
		   "										 	\n");
}

/*
void	unsigned_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Unsigned Integer errors:\n");
	printf("%s'%u,%d'\n",
		"\t+STR(13), Wrong type:\n\t\x20", "037777777013", "037777777013");
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'char *'
	printf("%s'%u,%d'\n",
		"\t+FL, Wrong type:\n\t\x20", 69.69, 69.69);
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'double'
	printf("%s'%u,%d'\n",
		"\t+I*, Wrong type:\n\t\x20", (int[3]){1, 2, 3}, (int[3]){1, 2, 3});
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'int *'
	printf("											"
		   "										 	\n");
	printf("%s'% u,% d'\n",
		"\t-B10I, Broken Space +:\n\t\x20", -42, -42); 
	printf("%s'% u,% d'\n",
		"\tB8I, Broken Space +:\n\t\x20", 052, 052); // Does nothing
		/  warning: flag ' ' results in undefined behavior with 'u' conversion 
		// specifier [-Wformat]
	printf("%s'% u,% d'\n",
		"\t+B16UI, Broken Space +:\n\t\x20", 0xFFFFFFFF, 0xFFFFFFFF); // Does nothing
		//  warning: flag ' ' results in undefined behavior with 'u' conversion 
		// specifier [-Wformat]
	printf("											"
		   "										 	\n");
	printf("%s'%+u,%+d'\n",
		"\t+B10UI, +/- Sign:\n\t\x20", 2294966795U, 2294966795U); // does nothing
		// warning: flag '+' results in undefined behavior with 'u' 
		// conversion specifier [-Wformat]
	printf("%s'%+u,%+d'\n",
		"\t+B16UI, +/- Sign:\n\t\x20", 0xFFFFFFFF, 0xFFFFFFFF); // does nothing
		// warning: flag '+' results in undefined behavior with 'u' 
		// conversion specifier [-Wformat]
	printf("%s'%+u,%+d'\n",
		"\t+B8UI, +/- Sign:\n\t\x20", 037772154013, 037777777013); // does nothing
		// warning: flag '+' results in undefined behavior with 'u' 
		// conversion specifier [-Wformat]
	printf("											"
		   "										 	\n");
	printf("%s'%025.20u,%025.20d'\n",
		"\t+B10UI, Zero padding + Min Field Length(25) + Precision(20):\n\t\x20", 
		2294966795U, 2294966795U); // Zero padding is ignored when precision
	printf("											"
		   "										 	\n");
}
*/

void	pointer_specifier(int do_it)
{
	void	*p0;
	int		*p1;
	char	*p2;

	if (!do_it)
		return ;
	printf("Pointers specifier and flags:\n");
	printf("%s'%p'\n",
		"\tvoid* PTR, standard %p specifier:\n\t\x20", p0);
	printf("%s'%p'\n",
		"\tint* PTR, standard %p specifier:\n\t\x20", p1);
	printf("%s'%p'\n",
		"\tchar* PTR, standard %p specifier:\n\t\x20", p2);
	printf("%s'%p'\n",
		"\tvoid* from B16ULI, standard %p specifier:\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
	printf("%s'%p'\n",
		"\tvoid* from B8I, standard %p specifier:\n\t\x20",
		(void *)010);
	printf("%s'%p'\n",
		"\tvoid* from B10I, standard %p specifier:\n\t\x20",
		(void *)4242);
	printf("%s'%p'\n",
		"\tvoid* from B16I, standard %p specifier:\n\t\x20",
		(void *)0xFFFF);
	printf("												"
		   "										 		\n");
	printf("%s'%1p'\n",
		"\tvoid* from B16ULI, Min Field Length(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
	printf("%s'%7p'\n",
		"\tvoid* from B16ULI, Min Field Length(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
	printf("%s'%15p'\n",
		"\tvoid* from B16ULI, Min Field Length(15):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
	printf("												"
		   "										 		\n");
	printf("%s'%-1p'\n",
		"\tvoid* from B16ULI, Left Aligned + Min Field Length(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
	printf("%s'%-7p'\n",
		"\tvoid* from B16ULI, Left Aligned + Min Field Length(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
	printf("%s'%-15p'\n",
		"\tvoid* from B16ULI, Left Aligned + Min Field Length(15):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
	printf("												"
		   "										 		\n");
}

/*
void	pointer_specifier_err(int do_it)
{
	void	*p0;
	int		*p1;
	char	*p2;

	if (!do_it)
		return ;
	printf("Pointers specifier errs:\n");
	printf("%s'%p'\n",
		"\tB10I, wrong type, standard %p specifier:\n\t\x20",
		256); // still displays the value correct in hex
		//  warning: format specifies type 'void *' but the argument 
		// has type 'int'
	printf("%s'%p'\n",
		"\tB16I, wrong type, standard %p specifier:\n\t\x20",
		0xEFF); // still displays the value correct in hex
		//  warning: format specifies type 'void *' but the argument
		// has type 'int'
	void	*p;
	printf("%s'%p'\n",
		"\tPTRUL, wrong type, standard %p specifier:\n\t\x20", (uintptr_t)p); 
		// The value returned matches the hexadecimal one printed by %p.
		// warning: format specifies type 'void *' but the argument has type
		// 'uintptr_t' (aka 'unsigned long')
	printf("%s'%p'\n",
		"\tB16ULI, wrong type, standard %p specifier:\n\t\x20",
		((uintptr_t){ 0x1000UL })); // The value 
		// returned matches the hexadecimal one printed by %p.
		// warning: format specifies type 'void *' but the argument has type
		// 'uintptr_t' (aka 'unsigned long')
	printf("												"
		   "										 		\n");
	printf("%s'%0p'\n",
		"\tvoid* PTR, zero filled:\n\t\x20", p0); // 
		// displays the right value but raises a warning 
		// flag '0' results in undefined behavior with 'p' conversion specifier
	printf("%s'%01p'\n",
		"\tvoid* from B16ULI, Zero filled + Min Field Length(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// does nothing but raises a warning 
		// flag '0' results in undefined behavior with 'p' conversion specifier
	printf("%s'%07p'\n",
		"\tvoid* from B16ULI, Zero filled + Min Field Length(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// 0x at the left, then 1 zero, then 1000.
		// flag '0' results in undefined behavior with 'p' conversion specifier
	printf("%s'%015p'\n",
		"\tvoid* from B16ULI, Zero filled + Min Field Length(15):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// 0x at the left, then 9 zeros, then 1000.
		// flag '0' results in undefined behavior with 'p' conversion specifier	
	printf("												"
		   "										 		\n");
	printf("%s'%.1p'\n",
		"\tvoid* from B16ULI, Precision(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// 1 number minimum
		// precision used with 'p' conversion specifier, resulting in undefined 
		// behavior
	printf("%s'%.7p'\n",
		"\tvoid* from B16ULI, Precision(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// 1000 is 4 numbers so it will zero filled with 3 zeros. 
		// 0x prefix is still at the extreme left and not being taken account.
		// precision used with 'p' conversion specifier, resulting in undefined
		// behavior 
	printf("%s'%.15p'\n",
		"\tvoid* from B16ULI, Precision(15):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// 1000 is 4 numbers so it will zero filled with 11 zeros
		// 0x prefix is still at the extreme left and not being taken account.
		// precision used with 'p' conversion specifier, resulting in undefined 
		// behavior 
	printf("												"
		   "										 		\n");
	printf("%s'% p'\n",
		"\tchar* PTR, Space for + prefix:\n\t\x20", p2); 
		// does nothing
		// displays the right value but raises a warning 
		// flag ' ' results in undefined behavior with 'p' conversion specifier
	printf("												"
		   "										 		\n");
	printf("%s'%#p'\n",
		"\tchar* PTR, 0x prefix:\n\t\x20", p2); // 
		// does nothing, no additionnal 0x 
		// displays the right value but raises a warning 
		// flag '#' results in undefined behavior with 'p' conversion specifier
	printf("												"
		   "										 		\n");
	printf("%s'%+p'\n",
		"\tvoid* PTR, +/- prefix:\n\t\x20", p0); // 
		// does nothing
		// displays the right value but raises a warning 
		// flag '+' results in undefined behavior with 'p' conversion specifier
	printf("												"
		   "										 		\n");
}
*/

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

void	hexadecimal_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	// HELLO_HELLO_HELLO
}

void	just_pourcent(int do_it)
{
	if (!do_it)
		return ;
	printf("%s'42%%'\n",
		"\tJust pourcent:\n\t\x20");
}

//  NOT TREATED
	// flags: ' ' '#' '+' '0' '-'
	// options: min length,

//  TREATED
	// flags:  
	// options:  precision

int	main(void)
{
	// integer_specifier2(1);
	// format_string(1);
	// // format_string_err(1);
	// character_specifier(1);
	// // character_specifier_err(1);
	// string_specifier(1);
	// // string_specifier_err(1);
	// integer_specifier(1);
	// // integer_specifier_err(1);
	// unsigned_specifier(1);
	// unsigned_specifier_err(1);
	// pointer_specifier(1);
	// pointer_specifier_err(1);
	hexadecimal_specifier(1);
	// hexadecimal_specifier_err(1);
	// just_pourcent(1);
	return (0);
}