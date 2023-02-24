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

void	format_string(int do_it)
{
	if (!do_it)
		return ;
	printf("Just format string, no specifiers and flags:\n");
	printf("\t'Sh***ku I love you! *** motherfuckers!!'\n");
	printf("											"
		   "											\n");
}

/*
void	format_string_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Just format string, errors:\n");
	printf("\tUnused specifications:\n");
	printf("\t\x20'English ***, do you speak it?'\n", 
		42); // -> warning, data arg not used by format string
	printf("											"
		   "											\n");
}
*/

void	character_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Character specifiers and flags:\n");
	printf("%s'%c'\n", 
		"\tCR standard %c specifier:\n\t\x20", 'Q');
	printf("%s'%c'\n", 
		"\tCR16 standard %c specifier:\n\t\x20", '\x41'); // (0x41)16 is (65)10
	printf("%s'%c'\n",
		"\tCR8 standard %c specifier:\n\t\x20", '\104');
	printf("%s'%c'\n", 
		"\tB16I standard %c specifier:\n\t\x20", 0x41); // (0x41)16 is (65)10
	printf("%s'%c'\n", 
		"\tB10I standard %c specifier:\n\t\x20", 65); // XXX
	printf("%s'%c'\n", 
		"\t-B10I standard %c specifier:\n\t\x20", -175); // -175 is 81 after 
		// unsigned char conversion
	printf("%s'%c'\n", 
		"\t-B8I standard %c specifier:\n\t\x20", -0276); // (-0276)8 is 
		// (66)10 after unsigned char conversion
	printf("											"
		   "											\n");
	printf("%s'%1c'\n", 
		"\tCR, Min Len Field (1):\n\t\x20", 'Q');
	printf("%s'%5c'\n", 
		"\tCR, Min Len Field (5):\n\t\x20", 'Q');
	printf("%s'%10c'\n", 
		"\tCR, Min Len Field (10):\n\t\x20", 'Q');
	printf("											"
		   "											\n");
	printf("%s'%-c'\n",
		"\tCR, Left justified:\n\t\x20", 'Q');
	printf("%s'%-1c'\n",
		"\tCR, Left justified + Min Len Field (1):\n\t\x20", 'Q');
	printf("%s'%-5c'\n",
		"\tCR, Left justified + Min Len Field (5):\n\t\x20", 'Q');
	printf("%s'%-10c'\n",
		"\tCR, Left justified + Min Len Field (10):\n\t\x20", 'Q');
	printf("											"
		   "										 	\n");
}

/*
void	character_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Character specifiers errors:\n");
	printf("%s'%c'\n", 
		"\tNO ARGUMENT, standard %c specifier:\n\t\x20"); 
		// prints nothing
		// raises a warning: more '%' conversions than data arguments
	printf("%s'%c'\n", 
		"\t-B10F, Wrong type, standard %c specifier:\n\t\x20", 3.14F); 
		// prints nothing
		// Produces a warning that blocks execution with -Werror : format 
		// specifies type 'int' but the argument has type 'double'.
	printf("%s'%c'\n",
		"\tSTR, Wrong type, standard %c specifier:\n\t\x20", "a");
		// prints nothing
		// warning: format specifies type 'int' but the argument has type 
		// 'char *'.
	printf("%s'%c'\n",
		"\tvoid* B16I, Wrong type, standard %c specifier:\n\t\x20", 
		(void *)0x1010); 
		// prints nothing
		// warning: format specifies type  'int' but the argument has type 
		// 'void *'. 
	printf("													"
		   "										  			\n");
	printf("%s'% c'\n", 
		"\tCR, Space for +:\n\t\x20", 'Q');
		// No space printed. 'Q' is printed but a warning is raised.
		// warning: flag ' ' results in undefined behavior with 'c' conversion
		// specifier 
	printf("%s'%+c'\n", 
		"\tCR, +/- sign:\n\t\x20", 'Q');
		// No + or - printed. 'Q' is printed and a warning is raised.
		// warning: flag '+' results in undefined behavior with 'c' conversion
		// specifier
	printf("											"
		   "										  \n");
	printf("%s'%#c'\n", 
		"\tCR, 0x prefix:\n\t\x20", 'Q');
		// No 0x printed. 'Q' is printed but a warning is raised.
		// warning: flag '#' results in undefined behavior with 'c' conversion
		// specifier
	printf("											"
		   "										  \n");
	printf("%s'%.1c'\n", 
		"\tCR, Precision (1):\n\t\x20", 'Q'); 
		// Does nothing. No zero or anything else added, just 'Q'
		// warning: precision used with 'c' conversion specifier, 
		// resulting in undefined behavior
	printf("%s'%.5c'\n", 
		"\tCR, Precision (5):\n\t\x20", 'Q');
		// Does nothing. No zero or anything else added, just 'Q'
		// warning: precision used with 'c' conversion specifier, 
		// resulting in undefined behavior
	printf("%s'%.10c'\n", 
		"\tCR, Precision (10):\n\t\x20", 'Q');
		// Does nothing. No zero or anything else added, just 'Q'
		// warning: precision used with 'c' conversion specifier, 
		// resulting in undefined behavior
	printf("											"
		   "											\n");
	printf("%s'%0c'\n",
		"\tCR, Zero Padding:\n\t\x20", 'Q');
		// warning: flag '0' results in undefined behavior with 'c' 
		// conversion specifier
	printf("%s'%01c'\n",
		"\tCR, Zero Padding + Min Len Field (1):\n\t\x20", 'Q');
		// warning: flag '0' results in undefined behavior with 'c' 
		// conversion specifier
	printf("%s'%05c'\n",
		"\tCR, Zero Padding + Min Len Field (5):\n\t\x20", 'Q');
		// Prints '0000Q', so it works but...
		// warning: flag '0' results in undefined behavior with 'c' 
		// conversion specifier
	printf("%s'%010c'\n",
		"\tCR, Zero Padding + Min Len Field (10):\n\t\x20", 'Q');
		// Prints '000000000Q', so it works but...
		// warning: flag '0' results in undefined behavior with 'c' 
		// conversion specifier
	printf("											"
		   "										  \n");
	printf("%s'%-0c'\n",
		"\tCR, Zero Padding + Left justified:\n\t\x20", 'Q');
		// Prints 'Q'
		// warning: flag '0' is ignored when flag '-' is present
		// warning: flag '0' results in undefined behavior with 'c'
		// conversion specifier
	printf("%s'%0-1c'\n",
		"\tCR, Zero Padding + Left justified + Min Len Field (1):\n\t\x20",
		'Q');
		// Prints 'Q'	
		// warning: flag '0' is ignored when flag '-' is present
		// warning: flag '0' results in undefined behavior with 'c'
		// conversion specifier
	printf("%s'%-05c'\n",
		"\tCR, Zero Padding + Left justified + Min Len Field (5):\n\t\x20",
		'Q');
		// Prints 'Q    '
		// warning: flag '0' is ignored when flag '-' is present
		// warning: flag '0' results in undefined behavior with 'c'
		// conversion specifier
	printf("%s'%0-10c'\n",
		"\tCR, Zero Padding + Left justified + Min Len Field (10):\n\t\x20",
		'Q');
		// Prints 'Q         '
		// warning: flag '0' is ignored when flag '-' is present
		// warning: flag '0' results in undefined behavior with 'c'
		// conversion specifier
	printf("											"
		   "											\n");
}
*/

void	string_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("String specifier and flags:\n");
	printf("%s'%s'%s''\n",
		"\tCR[0], standard %s specifier:\n\t\x20",
		"je souis\x20", "");
	printf("%s'%s'%s''\n",
		"\tCR[8], standard %s specifier:\n\t\x20",
		"je souis\x20", "travail");
	printf("%s'%s'\n",
		"\tCR[8], standard %s specifier, misplaced format specifiers:\n\t\x20", 
		"%s %s %u %p"); 
		// prints "%s %s %u %p". Format speciers have no effect here.
	printf("												"
		   "												\n");
	printf("%s'%s'%1s''\n",
		"\tCR[9] Min Field Length(1):\n\t\x20", 
		"je souis\x20", "fresh af");
	printf("%s'%s'%10s''\n",
		"\tCR[9] Min Field Length(10):\n\t\x20", 
		"je souis\x20", "fresh af");
	printf("%s'%s'%16s''\n",
		"\tCR[9] Min Field Length(16):\n\t\x20", 
		"je souis\x20", "fresh af");
	printf("											"
		   "										  	\n");
	printf("%s'%s'%-s''\n",
		"\tCR[9] Left Justified:\n\t\x20", 
		"je souis\x20", "fresh af");
	printf("%s'%s'%-1s''\n",
		"\tCR[9] Left Justified + Min Field Length(1):\n\t\x20", 
		"je souis\x20", "fresh af");
	printf("%s'%s'%-10s''\n",
		"\tCR[9] Left Justified + Min Field Length(10):\n\t\x20", 
		"je souis\x20", "fresh af");
	printf("%s'%s'%-16s''\n",
		"\tCR[9] Left Justified + Min Field Length(16):\n\t\x20", 
		"je souis\x20", "fresh af");
	printf("											"
		   "										  	\n");
	printf("%s'%s'%.2s''\n",
		"\tCR[9], Precision(2):\n\t\x20", 
		"je souis\x20", "yesouite");
		// 'je souis 'ye''
		// Strange...
	printf("%s'%s'%.4s''\n",
		"\tCR[9], Precision(4):\n\t\x20", 
		"je souis\x20", "yesouite");
		// 'je souis 'yeso''
		// Strange...
	printf("%s'%s'%.6s''\n",	
		"\tCR[9], Precision(6):\n\t\x20", 
		"je souis\x20", "yesouite");
		// 'je souis 'yesoui''
		// Strange...
	printf("%s'%s'%.10s''\n",
		"\tCR[9], Precision(10):\n\t\x20", 
		"je souis\x20", "yesouite");
		// 'je souis 'yesouite'' and nothing else, no extra characters
		// Strange...
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
		"\tNO ARGUMENT, standard %s specifier:\n\t\x20");
		// Prints (Null) raises a warning:
		// warning: more '%' conversions than data arguments
	printf("											"
		   "										  \n");
	printf("%s'%s'%s''\n",
		"\tB10I, Wrong type, standard %s specifier :\n\t\x20", 
		"je souis\x20", 42); 
		// Segmentation fault.
		// warning: format specifies type 'char *' but the argument has type 
		// 'int'.
	printf("%s'%s'%s''\n",
		"\t-B10FL, Wrong type, standard %s specifier:\n\t\x20", 
		"je souis\x20", -3.14F);  
		// Segmentation fault.
		// warning: format specifies type 'char *' but the argument has type 
		// 'float'.
	printf("%s'%s'%s''\n",
		"\tCR, Wrong type, standard %s specifier:\n\t\x20",
		"je souis\x20", 'C'); 
		// Segmentation fault.
		// warning: format specifies type 'char *' but the argument has type 
		// 'int'.
	printf("%s'%s'%s''\n",
		"\t(int *)B16U, Wrong type, standard %s specifier:\n\t\x20",
		"je souis\x20", (int *)0x1111U); 
		// Segmentation fault.
		// warning: format specifies type 'char *' but the argument has type 
		// 'int *'.
	printf("											"
		   "											\n");
	printf("%s'%s'% s''\n",
		"\tCR[8], Space for +:\n\t\x20",
		"je souis\x20", "+travail+");
		// Prints '+travail+', a warning is raised. No + sign is replaced by 
		// space, a str is not positive anyway...
		// warning: flag ' ' results in undefined behavior with 's' conversion 
		// specifier
	printf("%s'%s'%+s''\n",
		"\tCR[8], +/- sign:\n\t\x20",
		"je souis\x20", "travail");
		// Prints 'travail', a warning is raised. No + sign is added...
		// warning: flag '+' results in undefined behavior with 's' conversion 
		// specifier
	printf("%s'%s'%#s''\n",
		"\tCR[8], 0x prefix:\n\t\x20",
		"je souis\x20", "travail");
		// Prints 'travail', a warning is raised. No prefix added...
		// warning: flag '#' results in undefined behavior with 's' conversion 
		// specifier
	printf("												"
		   "												\n");
	printf("%s'%s'%0s''\n",
		"\tCR[9] Zero Filled:\n\t\x20", 
		"je souis\x20", "fresh af");
		// No need for zero filling, raises a warning
		// flag '0' results in undefined behavior with 's' conversion specifier
	printf("%s'%s'%01s''\n",
		"\tCR[9] Zero Filled + Min Field Length(1):\n\t\x20", 
		"je souis\x20", "fresh af");
		// No need for zero filling, raises a warning
		// flag '0' results in undefined behavior with 's' conversion specifier
	printf("%s'%s'%010s''\n",
		"\tCR[9] Zero Filled + Min Field Length(10):\n\t\x20", 
		"je souis\x20", "fresh af");
		// Prints 'je souis '00fresh af'', raises a warning
		// flag '0' results in undefined behavior with 's' conversion specifier 
	printf("%s'%s'%016s''\n",
		"\tCR[9] Zero Filled + Min Field Length(16):\n\t\x20", 
		"je souis\x20", "fresh af");
		// Prints '00000000fresh af'', raises a warning
		// flag '0' results in undefined behavior with 's' conversion specifier
	printf("											"
		   "										  	\n");
	printf("%s'%s'%-016s''\n",
		"\tCR[9] Left justified + Zero Filled + Min Field Length(16):\n\t\x20", 
		"je souis\x20", "fresh af");
		// Prints 'je souis 'fresh af        '', raises two warnings
		// flag '0' is ignored when flag '-' is present
		// flag '0' results in undefined behavior with 's' conversion specifier
	printf("											"
		   "											\n");
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
	printf("%s'%i,%d'\n", 
		"\t+B8U, standard %i,%d specifier:\n\t\x20", 052U, 052U);	
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

/**/
void	integer_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Integer specifiers err:\n");
	printf("%s'%i, %d'\n", 
		"\tB10F, Wrong type, standard %i,%d specifier:\n\t\x20", 
		42.7F, 42.7F);
		// Prints '0, -97124212'. Raises a warning.
		// warning: format specifies type 'int' but the argument has type 
		// 'float'
	printf("%s'%i, %d'\n", 
		"\tCR[0], Wrong type, standard %i,%d specifier:\n\t\x20",
		"", "");
		// Prints '83745994, 83745994'. Raises a warning.
		// warning: format specifies type 'int' but the argument has 
		// type 'char *'
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
/**/

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
		"\t+B16UI, Broken Space +:\n\t\x20", 0xFFFFFFFF, 0xFFFFFFFF); // Does 
		// nothing warning: flag ' ' results in undefined behavior with 'u' 
		// conversion specifier [-Wformat]
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
		"\t-B8I, %x standard specifier:\n\t\x20", -052, -052);
		// Number is converted to unsigned int via signed 2 complements then
		// converted to hex
	printf("%s'%x,%X'\n", 
		"\t+B16I, %x standard specifier:\n\t\x20", 0xab2F, 0xab2F);
	printf("%s'%x,%X'\n", 
		"\t+B10U, %x standard specifier:\n\t\x20", 42U, 42U);
	printf("												"
		   "										 		\n");
	printf("%s'%#x,%#X'\n",
		"\tB16I, 0x prefix:\n\t\x20", 0xab2F, 0xab2F);
	printf("%s'%#x,%#X'\n", 
		"\t+B10U, 0x prefix:\n\t\x20", 42U, 42U);
	printf("												"
		   "										 		\n");
	printf("%s'%1x,%1X'\n", 
		"\t+B10U, Min Length(1):\n\t\x20", 42U, 42U);
	printf("%s'%4x,%4X'\n", 
		"\t+B10U, Min Length(4):\n\t\x20", 42U, 42U);
	printf("%s'%#1x,%#1X'\n",
		"\t+B10U, Min Length(4) + 0x prefix:\n\t\x20", 42U, 42U);
	printf("												"
		   "										 		\n");
	printf("%s'%-x,%-X'\n", 
		"\t+B10U, Left Justified:\n\t\x20", 42U, 42U);
	printf("%s'%-4x,%-4X'\n", 
		"\t+B10U, Left Justified + Min Length(4):\n\t\x20", 42U, 42U);
	printf("%s'%-10x,%-10X'\n",
		"\t+B10U, Left Justified + Min Length(10):\n\t\x20", 42U, 42U);
	printf("												"
		   "										 		\n");
	printf("%s'%#-4x,%#-4X'\n", 
		"\t+B10U, 0x Prefix + Left Justified + Min Length(4):\n\t\x20", 
		42U, 42U);
	printf("%s'%-#10x,%-#10X'\n", 
		"\t+B10U, 0x Prefix + Left Justified + Min Length(10):\n\t\x20", 
		42U, 42U);
	printf("												"
		   "										 		\n");
	printf("%s'%0x,%0X'\n", 
		"\t+B10U, Zero filled:\n\t\x20", 42U, 42U);
	printf("%s'%04x,%04X'\n", 
		"\t+B10U, Zero filled + Min Length(4):\n\t\x20", 42U, 42U);
	printf("%s'%010x,%010X'\n",
		"\t+B10U, Zero filled + Min Length(10):\n\t\x20", 42U, 42U);
	printf("%s'%#010x,%#010X'\n",
		"\t+B10U, 0x prefix + Zero filled + Min Length(10):\n\t\x20",
		42U, 42U);
	printf("												"
		   "										 		\n");
	printf("%s'%.1x,%.1X'\n", 
		"\t+B10U, Precision(1):\n\t\x20", 42U, 42U);
	printf("%s'%.4x,%.4X'\n", 
		"\t+B10U, Precision(4):\n\t\x20", 42U, 42U);
	printf("%s'%#.4x,%#.4X'\n", 
		"\t+B10U, 0x prefix + Precision(4):\n\t\x20", 42U, 42U);
	printf("												"
		   "										 		\n");
}

/*
void	hexadecimal_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Hexadecimal specifier errors:\n");
	printf("%s'%x,%X'\n", 
		"\t+B10UL, wrong type, %x standard specifier:\n\t\x20", 16UL, 16UL);
		// Conversion is done correctly but a warning is raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'unsigned long'
	printf("%s'%x,%X'\n", 
		"\tvoid* +B16I, wrong type, %x standard specifier:\n\t\x20",
		(void *)0xAAA, (void *)0xAAA);
		// Conversion is done correctly but a warning is raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'void *'
	printf("%s'%x,%X'\n",
		"\tint* +B16I, wrong type, %x standard specifier:\n\t\x20",
		(int *)0xAAA, (int *)0xAAA);
		// Conversion is done correctly but a warning is raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'int *'
	printf("%s'%x,%X'\n",
		"\tSTR(13), wrong type, %x standard specifier:\n\t\x20",
		"(int *)0xAAA", "(int *)0xAAA)");
		// A conversion is done but a warning is raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'char *'
	printf("												"
		   "										 		\n");
	printf("%s'% x,% X'\n", 
		"\t+B10U, Space for +:\n\t\x20", 42U, 42U);
		// No space is added, conversion is done but a warning is raised
		// warning: flag ' ' results in undefined behavior with 'x' conversion 
		// specifier
	printf("%s'%+x,%+X'\n", 
		"\t+B10U, +/- sign:\n\t\x20", 42U, 42U);
		// Not sign + is added, conversion is done but a warning is raised
		// warning: flag '+' results in undefined behavior with 'x' conversion 
		// specifier
	printf("												"
		   "										 		\n");
	printf("%s'%-010x,%-010X'\n",
		"\t+B10U, Left Justified + Zero filled + Min Length(10):\n\t\x20", 
		42U, 42U);
		// Zero filled is ignored when - is present. So this raises a warning.
	printf("												"
		   "										 		\n");
	printf("%s'%#010.3x,%#010.3X'\n",
		"\t+B10U, 0x prefix + Zero filled + Precision(3) + Min Length(10):\n\t\x20",
		42U, 42U); 
		// Precision and Zero filled clash but no flag is raised
	printf("												"
		   "										 		\n");
}
*/

void	just_pourcent(int do_it)
{
	if (!do_it)
		return ;
	printf("%s'42%%'\n",
		"\tJust pourcent:\n\t\x20");
}

// SPECIFIERS REVIEW
	// NOT TREATED: %i %d %p %u %x %% 
	// TREATED: %c, %s

// FLAGS REVIEW
	// NOT TREATED: ' ' '+' | '#' | '-' '0'
	// TREATED: 

// OPTIONS REVIEW
	// NOT TREATED: min length, precision
	// TREATED: 

int	main(void)
{
	// format_string(1);
	// character_specifier(1);
	// string_specifier(1);
	integer_specifier(1);
	// unsigned_specifier(1);
	// pointer_specifier(1);
	// hexadecimal_specifier(1);
	// just_pourcent(1);
	// ------------------------- //
	// format_string_err(1);
	// character_specifier_err(1);
	// string_specifier_err(0);
	// integer_specifier_err(1);
	// unsigned_specifier_err(1);
	// pointer_specifier_err(1);
	// hexadecimal_specifier_err(1);
}

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
