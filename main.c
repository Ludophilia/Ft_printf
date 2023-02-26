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

// ############################################################################

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

// ############################################################################

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

// ############################################################################

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
		"\t-B10I, Space for +:\n\t\x20", -42, -42);
	printf("%s'% i,% d'\n",
		"\t+B10I, Space for +:\n\t\x20", 42, 42);
	printf("%s'%+i,%+d'\n",
		"\t-B10I, +/- Sign:\n\t\x20", -42, -42);
	printf("%s'%+i,%+d'\n",
		"\t+B10I, +/- Sign:\n\t\x20", 42, 42);
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
	printf("%s'%-i,%-d'\n",
		"\t-B10I, Left justified:\n\t\x20", -42, -42);
		// Nothing changes as the field is not large enough
	printf("%s'%-1i,%-1d'\n",
		"\t-B10I, Left justified + Min Field Length(1):\n\t\x20",
		-42, -42);
	printf("%s'%-4i,%-4d'\n",
		"\t-B10I, Left justified + Min Field Length(4): \n\t\x20",
		-42, -42);
	printf("%s'%-10i,%-10d'\n",
		"\t+B10I, Left justified + Min Field Length(10):\n\t\x20",
		42, 42);
	printf("											"
		   "										 	\n");	
	printf("%s'%0i,%0d'\n",
		"\t-B10I, Zero padding:\n\t\x20", -42, -42);
		// Nothing changes as the field is not large enough
	printf("%s'%01i,%01d'\n",
		"\t-B10I, Zero padding + Min Field Length(1)\n\t\x20",
		-42, -42);
	printf("%s'%04i,%04d'\n",
		"\tB10I, Zero padding + Min Field Length(4)\n\t\x20",
		42, 42);
	printf("%s'%010i,%010d'\n",
		"\tB10I, Zero padding + Min Field Length(10):\n\t\x20",
		-42, -42);
		// 7 Zeroes appear between the negative sign and the number.
		// The sign is taken into the calculation.
	printf("											"
		   "										 	\n");
	printf("%s'%.i,%.d'\n",
		"\t-B10I, Precision(0):\n\t\x20", -42, -42); 
		// Set 0 as the minimum nb of digits to appear.
	printf("%s'%.1i,%.1d'\n",
		"\t-B10I, Precision(1):\n\t\x20", -42, -42); 
		// Set 1 as the minimum nb of digits to appear.
	printf("%s'%.10i,%.10d'\n",
		"\t-B10I, Precision(10):\n\t\x20", -42, -42);
		// Set 10 as the minimum nb digit to appear. 
		// Adds 8 zeros before 42, the presence of a sign or not has no
		// influence, contrary to Zero Filled + Min Field Width (10).
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
	printf("%s'%#i,%#d'\n",
		"\t-B10I, 0x Prefix:\n\t\x20", -42, -42);
		// Prints '-42' and raises a warning.
		// warning: flag '#' results in undefined behavior with 'i' (and 'd')
		//conversion specifier
	printf("%s'%#i,%#d'\n",
		"\t+B10I, 0x Prefix:\n\t\x20", 42, 42);
		// Prints '-42' and raises a warning.
		// warning: flag '#' results in undefined behavior with 'i' (and 'd')
		// conversion specifier
	printf("												"
		   "										 		\n");
	printf("%s'%0-i,%0-d'\n",
		"\t-B10I, Zero padding + Left justified:\n\t\x20", -42, -42);
		// Same behavior as Left justified. A warning is raised.
		// warning: flag '0' is ignored when flag '-' is present
	printf("%s'%-01i,%-01d'\n",
		"\t-B10I, Zero padding + Left justified + Min Field Length(1):\n\t\x20",
		-42, -42);
		// Same behavior as Left justified. A warning is raised.
		// warning: flag '0' is ignored when flag '-' is present
	printf("%s'%0-4i,%0-4d'\n",
		"\t-B10I, Zero padding + Left justified + Min Field Length(4):\n\t\x20",
		-42, -42);
		// Same behavior as Left justified. A warning is raised.
		// warning: flag '0' is ignored when flag '-' is present
	printf("%s'%-010i,%-010d'\n",
		"\t+B10I, Zero padding + Left justified + Min Field Length(10):\n\t\x20",
		42, 42);
		// Same behavior as Left justified. A warning is raised.
		// warning: flag '0' is ignored when flag '-' is present
	printf("											"
		   "										 	\n");
}
*/

// ############################################################################

void	unsigned_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Unsigned Integer specifiers and flags:\n");
	printf("%s'%u,%d'\n",
		"\t-B10I, standard %u specifier:\n\t\x20",
		-22, -22);
	printf("%s'%u,%d'\n",
		"\t+B10I, standard %u specifier:\n\t\x20",
		22, 22);
	printf("%s'%u,%d'\n",
		"\t+B16U, standard %u specifier:\n\t\x20", 
		0xFFFFFFFFU, 0xFFFFFFFFU);
	printf("%s'%u,%d'\n",
		"\t+B8U, standard %u specifier:\n\t\x20",
		037777777013U, 037777777013U);
	printf("											"
		   "										 	\n");
	printf("%s'%2u,%2d'\n",
		"\t+B10U, Min Field Length(2):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%5u,%5d'\n",
		"\t+B10U, Min Field Length(5):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%10u,%10d'\n",
		"\t+B10U, Min Field Length(10):\n\t\x20", 
		2294U, 2294U);
	printf("											"
		   "										 	\n");
	printf("%s'%-u,%-d'\n",
		"\t+B10I, Left justified:\n\t\x20", 2294U, 2294U);
	printf("%s'%-2u,%-2d'\n",
		"\t+B10U, Left justified + Min Field Length(2):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%-5u,%-5d'\n",
		"\t+B10U, Left justified + Min Field Length(5):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%-10u,%-10d'\n",
		"\t+B10U, Left justified + Min Field Length(10):\n\t\x20", 
		2294U, 2294U);
	printf("											"
		   "										 	\n");
	printf("%s'%0u,%0d'\n",
		"\t+B10I, Zero padding:\n\t\x20", 2294U, 2294U);
	printf("%s'%02u,%02d'\n",
		"\t+B10U, Zero padding + Min Field Length(2):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%05u,%05d'\n",
		"\t+B10U, Zero padding + Min Field Length(5):\n\t\x20", 
		2294U, 2294U);
		// Adds 1 zero
	printf("%s'%010u,%-10d'\n",
		"\t+B10U, Zero padding + Min Field Length(10):\n\t\x20", 
		2294U, 2294U);
		// Adds 6 zeros
	printf("											"
		   "										 	\n");
	printf("%s'%.u,%.d'\n",
		"\t+B10I, Precision(0):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%.2u,%.2d'\n",
		"\t+B10U, Precision(2):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%.5u,%.5d'\n",
		"\t+B10U, Precision(5):\n\t\x20", 
		2294U, 2294U);
		// Adds 1 zero, same as Zero padding
	printf("%s'%.10u,%.10d'\n",
		"\t+B10U, Precision(10):\n\t\x20", 
		2294U, 2294U);
		// Adds 6 zeros, same as Zero padding
	printf("											"
		   "										 	\n");
	printf("%s'%10.5u,%10.5d'\n",
		"\t+B10U, Precision(5) + Min Field Width(10):\n\t\x20", 
		2294U, 2294U);
	printf("%s'%5.10u,%5.10d'\n",
		"\t+B10U, Precision(10) + Min Field Width(5):\n\t\x20", 
		2294U, 2294U);
	printf("											"
		   "										 	\n");
	printf("%s'%010.5u,%010.5d'\n",
		"\t+B10U, Zero Padding + Precision(5) + Min Field Width(10):\n\t\x20", 
		2294U, 2294U);
		// Prints '     02294,     02294'. No warning raised but
		// Zero padding is ignored when precision and numeric conversion.
}

/*
void	unsigned_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Unsigned Integer errors:\n");
	printf("%s'%u,%d'\n",
		"\tCR[13], wrong type, standard %u specifier:\n\t\x20", 
		"037777777013", "037777777013");
		// Prints '14239130,14239130' raises a warning.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'char *'
	printf("%s'%u,%d'\n",
		"\t+B10F, wrong type, standard %u specifier:\n\t\x20",
		69.69F, 69.69F);
		// Prints '0,1041301682' and raises a warning.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'float'
	printf("%s'%u,%d'\n",
		"\tI[3], Wrong type, standard %u specifier:\n\t\x20", 
		(int[3]){1, 2, 3}, (int[3]){1, 2, 3});
		// Prints '71992156,71992144' and raises a warning.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'int *'
	printf("											"
		   "										 	\n");
	printf("%s'% u,% d'\n",
		"\t-B10I, Space for +:\n\t\x20",
		-42, -42);
		// Prints '4294967254,-42', does not add a space, and raises a warning.
		// warning: flag ' ' results in undefined behavior with 'u' 
		// conversion specifier
	printf("%s'% u,% d'\n",
		"\t+B16UI, Space for +:\n\t\x20", 
		0xFFFFFFFF, 0xFFFFFFFF);
		// Prints '4294967295,-1', does not add a space, and raises a warning.
		// warning: flag ' ' results in undefined behavior with 'u' 
		// conversion specifier
	printf("%s'%+u,%+d'\n",
		"\t-B10I, +/- sign:\n\t\x20",
		-42, -42);
		// Prints '4294967254,-42', does not append a + sign, and raises a 
		// warning.
		// warning: flag '+' results in undefined behavior with 'u' 
		// conversion specifier
	printf("%s'%+u,%+d'\n",
		"\t+B16UI, +/- sign:\n\t\x20", 
		0xFFFFFFFF, 0xFFFFFFFF);
		// Prints '4294967295,-1', does not append a + sign, and raises a 
		// warning.	
		// warning: flag '+' results in undefined behavior with 'u' 
		// conversion specifier
	printf("											"
		   "										 	\n");
	printf("%s'%#u,%#d'\n",
		"\t-B10I, 0x Prefix:\n\t\x20",
		-42, -42);
		// Prints '4294967254,-42', does not append the prefix, and raises 
		// a warning.
		// warning: flag '#' results in undefined behavior with 'u' 
		// conversion specifier
	printf("%s'%#u,%#d'\n",
		"\t+B16UI, 0x Prefix:\n\t\x20", 
		0xFFFFFFFF, 0xFFFFFFFF);
		// Prints '4294967295,-1', does not append the prefix, and raises a 
		// warning.
		// warning: flag '#' results in undefined behavior with 'u' 
		// conversion specifier
	printf("											"
		   "										 	\n");
	printf("%s'%-010u,%-010d'\n",
		"\t+B10U, Zero padding + Left justified + Min Field Length(10):\n\t\x20", 
		2294U, 2294U);
		// Acts the same way as Left justified alone. Raises a warning.
		// warning: flag '0' is ignored when flag '-' is present
	printf("											"
		   "										 	\n");
}
*/

// ############################################################################

void	hexadecimal_specifier(int do_it)
{
	if (!do_it)
		return ;
	printf("Hexadecimal specifier and flags:\n");

	printf("%s'%x,%X'\n", 
		"\t-B8I, %x standard specifier:\n\t\x20", -052, -052);
		// Prints 'ffffffd6,FFFFFFD6'. 32 bits words. How does it work?
		// -42 is converted to unsigned int via signed 2 complements then
		// converted to hex.
	printf("%s'%x,%X'\n", 
		"\t+B16I, %x standard specifier:\n\t\x20", 0xab2F, 0xab2F);
		// Prints 'ab2f,AB2F'.
	printf("%s'%x,%X'\n", 
		"\t+B10U, %x standard specifier:\n\t\x20", 42U, 42U);
		// Prints '2a,2A' as expected.
	printf("												"
		   "										 		\n");
	printf("%s'%#x,%#X'\n",
		"\tB16U, 0x prefix:\n\t\x20", 0xab2FU, 0xab2FU);
		// Prints '0xab2f,0XAB2F'. Conversion works as expected.
	printf("												"
		   "										 		\n");
	printf("%s'%1x,%1X'\n",
		"\t+B10U, Min Length(1):\n\t\x20", 0x2aU, 0x2aU);
	printf("%s'%4x,%4X'\n",
		"\t+B10U, Min Length(4):\n\t\x20", 0x2aU, 0x2aU);
		// Prints '  2a,  2A'
	printf("%s'%#1x,%#1X'\n",
		"\t+B10U, Min Length(4) + 0x prefix:\n\t\x20", 0x2aU, 0x2aU);
		// Prints '0x2a,0X2A'
	printf("												"
		   "										 		\n");
	printf("%s'%-x,%-X'\n", 
		"\t+B10U, Left Justified:\n\t\x20",
		42U, 42U);
	printf("%s'%-4x,%-4X'\n", 
		"\t+B10U, Left Justified + Min Length(4):\n\t\x20",
		42U, 42U);
		// Prints '2a  ,2A  '
	printf("%s'%-10x,%-10X'\n",
		"\t+B10U, Left Justified + Min Length(10):\n\t\x20",
		42U, 42U);
		// Prints '2a        ,2A        '
	printf("%s'%#-4x,%#-4X'\n", 
		"\t+B10U, Left Justified + Min Length(4) + 0x Prefix:\n\t\x20", 
		42U, 42U);
		// Prints '0x2a,0X2A'
	printf("%s'%-#10x,%-#10X'\n", 
		"\t+B10U, Left Justified + Min Length(10) + 0x Prefix:\n\t\x20", 
		42U, 42U);
		// Prints '0x2a      ,0X2A      '
	printf("												"
		   "										 		\n");
	printf("%s'%0x,%0X'\n", 
		"\t+B10U, Zero filled:\n\t\x20",
		42U, 42U);
	printf("%s'%04x,%04X'\n", 
		"\t+B10U, Zero filled + Min Length(4):\n\t\x20", 
		42U, 42U);
		// Prints '002a,002A'
	printf("%s'%010x,%010X'\n",
		"\t+B10U, Zero filled + Min Length(10):\n\t\x20",
		42U, 42U);
		// Prints '000000002a,000000002A'
	printf("%s'%#010x,%#010X'\n",
		"\t+B10U, Zero filled + Min Length(10) + 0x prefix:\n\t\x20",
		42U, 42U);
		// Prints '0x0000002a,0X0000002A'
	printf("												"
		   "										 		\n");
	printf("%s'%.1x,%.1X'\n", 
		"\t+B10U, Precision(1):\n\t\x20",
		0x2aU, 0x2aU);
	printf("%s'%.4x,%.4X'\n", 
		"\t+B10U, Precision(4):\n\t\x20", 
		0x2aU, 0x2aU);
		// Prints '002a,002A'
	printf("%s'%#.4x,%#.4X'\n", 
		"\t+B10U, 0x prefix + Precision(4):\n\t\x20",
		0x2aU, 0x2aU);
		// Prints '0x002a,0X002A'
	printf("												"
		   "										 		\n");
	printf("%s'%5.1x,%5.1X'\n", 
		"\t+B10U, Precision(1) + Min Length(5):\n\t\x20",
		0x2aU, 0x2aU);
		// Prints '   2a,   2A'
	printf("%s'%5.4x,%5.4X'\n", 
		"\t+B10U, Precision(4) + Min Length(5):\n\t\x20", 
		0x2aU, 0x2aU);
		// Prints ' 002a, 002A'
	printf("%s'%#5.4x,%#5.4X'\n", 
		"\t+B10U, Precision(4) + Min Length(5) + 0x prefix:\n\t\x20",
		0x2aU, 0x2aU);
		// Prints '0x002a,0X002A'
	printf("												"
		   "												\n");
	printf("%s'%05.4x,%05.4X'\n", 
		"\t+B10U, Precision(4) + Min Length(5) + Zero filled:\n\t\x20",
		0x2aU, 0x2aU);
		// Prints ' 002a, 002A'.
		// '0' is overidden by Precision(4). Strangely enough, no warning is 
		// raised.
}

/*
void	hexadecimal_specifier_err(int do_it)
{
	if (!do_it)
		return ;
	printf("Hexadecimal specifier errors:\n");
	printf("%s'%x,%X'\n", 
		"\t+B10UL, wrong type, %x standard specifier:\n\t\x20", 16UL, 16UL);
		// Prints '10,10', conversion works but a warning is raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'unsigned long'
	printf("%s'%x,%X'\n", 
		"\t(void*)+B16I, wrong type, %x standard specifier:\n\t\x20",
		(void *)0xAAA, (void *)0xAAA);
		// Prints 'aaa,AAA', conversion works but a warning is raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'void *'.
	printf("%s'%x,%X'\n",
		"\t(int*)+B16I, wrong type, %x standard specifier:\n\t\x20",
		(int *)0xAAA, (int *)0xAAA);
		// Prints 'aaa,AAA', conversion works but a warning is raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'int *'
	printf("%s'%x,%X'\n",
		"\tCR[13], wrong type, %x standard specifier:\n\t\x20",
		"(int *)0xAAA", "(int *)0xAAA)");
		// Prints '4b21952,4B2195F'. A "conversion" is done and a warning is 
		// raised.
		// warning: format specifies type 'unsigned int' but the argument has
		// type 'char *'
	printf("												"
		   "										 		\n");
	printf("%s'% x,% X'\n",
		"\tB16U, Space for +:\n\t\x20", 0xab2FU, 0xab2FU);
		// Prints 'ab2f,AB2F'. Conversion works but a warning is raised.
		// warning: flag ' ' results in undefined behavior with 'x' 
		// conversion specifier.
	printf("%s'%+x,%+X'\n",
		"\tB16U, +/- sign prefix:\n\t\x20", 0xab2FU, 0xab2FU);
		// Prints 'ab2f,AB2F'. Conversion works but a warning is raised.
		// warning: flag '+' results in undefined behavior with 'x' 
		// conversion specifier.
	printf("												"
		   "										 		\n");
	printf("%s'%-010x,%-010X'\n",
		"\t+B10U, Zero filled + Left Justified + Min Length(10):\n\t\x20", 
		42U, 42U);
		// Prints '2a      ,2A      '
		// Equivalent to Left Justified + Min Length(10), as '0' is ignored 
		// when - is present. Raises a warning.
		// warning: flag '0' is ignored when flag '-' is present
	printf("												"
		   "										 		\n");
}
*/

// ############################################################################

void	pointer_specifier(int do_it)
{
	void	*p0;
	int		*p1;
	char	*p2;

	if (!do_it)
		return ;
	printf("Pointers specifier and flags:\n");
	printf("%s'%p'\n",
		"\t(void*)PTR, standard %p specifier:\n\t\x20",
		p0);
		// Prints '0x89808cc40db60044'. Wow, な-が-い.
	printf("%s'%p'\n",
		"\t(int*)PTR, standard %p specifier:\n\t\x20",
		p1);
		// Prints '0x0'
	printf("%s'%p'\n",
		"\t(char*)PTR, standard %p specifier:\n\t\x20",
		p2);
		// Prints '0x100'
	printf("%s'%p'\n",
		"\t (void*)B16UL, standard %p specifier:\n\t\x20",
		(void *)(uintptr_t)0x2aUL);
		// Prints '0x2a'
	printf("%s'%p'\n",
		"\t(void*)B8I, standard %p specifier:\n\t\x20",
		(void *)010);
		// Prints '0x8'
	printf("%s'%p'\n",
		"\t(void*)B10I, standard %p specifier:\n\t\x20",
		(void *)4242);
		// Prints '0x1092'
	printf("%s'%p'\n",
		"\t(void*)B16I, standard %p specifier:\n\t\x20",
		(void *)0xFFFF);
		// Prints '0xffff'
	printf("												"
		   "										 		\n");
	printf("%s'%1p'\n",
		"\t(void*)B16UL, Min Field Length(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000'
	printf("%s'%7p'\n",
		"\t(void*)B16UL, Min Field Length(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints ' 0x1000'
	printf("%s'%11p'\n",
		"\t(void*)B16UL, Min Field Length(11):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '     0x1000'
	printf("												"
		   "										 		\n");
	printf("%s'%-p'\n",
		"\t(void*)B16UL, Left Justified:\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000'
	printf("%s'%-1p'\n",
		"\t(void*)B16UL, Left Justified + Min Field Length(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000'
	printf("%s'%-7p'\n",
		"\t(void*)B16UL, Left Justified + Min Field Length(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000 '
	printf("%s'%-15p'\n",
		"\t(void*)B16UL, Left Justified + Min Field Length(11):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000     '
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
		256); 
		// Prints '0x100' (correct hex value) and raises a warning.
		// warning: format specifies type 'void *' but the argument 
		// has type 'int'
	printf("%s'%p'\n",
		"\tB16I, wrong type, standard %p specifier:\n\t\x20",
		0xEFF); 
		// Prints '0xeff' (correct hex value) and raises a warning.
		// warning: format specifies type 'void *' but the argument
		// has type 'int'
	printf("%s'%p'\n",
		"\t(UL)(void *), wrong type, standard %p specifier:\n\t\x20",
		(uintptr_t)p0);
		// Prints '0x89808cc40db60044'. The value returned matches the
		// hexadecimal one printed by %p. Raises a warning.
		// warning: format specifies type 'void *' but the argument has type
		// 'uintptr_t' (aka 'unsigned long').
	printf("%s'%p'\n",
		"\tB16UL, wrong type, standard %p specifier:\n\t\x20",
		((uintptr_t){ 0x1000UL })); 
		// Prints '0x1000', the correct value so that's good.
		// warning: format specifies type 'void *' but the argument has type
		// 'uintptr_t' (aka 'unsigned long')
	printf("												"
		   "										 		\n");
	printf("%s'% p'\n",
		"\t(int*)PTR, Space for + prefix:\n\t\x20", p1); 
		// Prints '0x0'
		// warning: flag ' ' results in undefined behavior with 'p' 
		// conversion specifier
	printf("%s'%+p'\n",
		"\t(int*)PTR, +/- prefix:\n\t\x20", p1); // 
		// Prints '0x0'
		// warning: flag '+' results in undefined behavior with 'p' 
		// conversion specifier
	printf("%s'%#p'\n",
		"\t(int*)PTR, 0x prefix:\n\t\x20", p1); // 
		// Prints '0x0', no additional 0x.
		// warning: flag '#' results in undefined behavior with 'p' 
		// conversion specifier
	printf("												"
		   "										 		\n");
	printf("%s'%0p'\n",
		"\t(void*)B16UL, Zero Filled:\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000'
		// warning: flag '0' results in undefined behavior with 'p' conversion 
		// specifier.
	printf("%s'%01p'\n",
		"\t(void*)B16UL, Zero Filled + Min Field Length(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000'
		// warning: flag '0' results in undefined behavior with 'p' conversion 
		// specifier.
	printf("%s'%07p'\n",
		"\t(void*)B16UL, Zero Filled + Min Field Length(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x01000'. 1 zero added between 0x and 1000.
		// warning: flag '0' results in undefined behavior with 'p' conversion 
		// specifier.
	printf("%s'%011p'\n",
		"\t(void*)B16UL, Zero Filled + Min Field Length(11):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x000001000'. 5 zeros added between 0x and 1000.
		// warning: flag '0' results in undefined behavior with 'p' conversion 
		// specifier.
	printf("												"
		   "										 		\n");
	printf("%s'%-015p'\n",
		"\t(void*)B16UL, Zero Fi. + Left Just. + Min Field Length(11):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000     '
		// warning: flag '0' results in undefined behavior with 'p' conversion 
		// specifier.
		// warning: flag '0' is ignored when flag '-' is present.
	printf("												"
		   "										 		\n");
	printf("%s'%.1p'\n",
		"\t(void*)B16UL, Precision(1):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x1000' and raises a warning.
		// warning: precision used with 'p' conversion specifier, 
		// resulting in undefined behavior 
	printf("%s'%.7p'\n",
		"\t(void*)B16UL, Precision(7):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x0001000' and raises a warning.
		// warning: precision used with 'p' conversion specifier, 
		// resulting in undefined behavior
	printf("%s'%.15p'\n",
		"\t(void*)B16UL, Precision(15):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '0x000000000001000' 11 zeros + 1000. Raises a warning.
		// warning: precision used with 'p' conversion specifier, 
		// resulting in undefined behavior
	printf("												"
		   "										 		\n");
	printf("%s'%10.7p'\n",
		"\t(void*)B16UL, Precision(7) + Min Field Len(10):\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints ' 0x0001000' and raises a warning.
		// warning: precision used with 'p' conversion specifier, 
		// resulting in undefined behavior
	printf("%s'%011.7p'\n",
		"\t(void*)B16UL, Precision(7) + Min Field Len(11) + Zero F.:\n\t\x20",
		(void *)(uintptr_t)0x1000UL);
		// Prints '  0x0001000' and raises two warning.
		// warning: precision used with 'p' conversion specifier, 
		// resulting in undefined behavior
		// flag '0' results in undefined behavior with 'p' conversion specifier 
		// '.' overrides '0' anyway.
	printf("												"
		   "										 		\n");
}
*/

// ############################################################################

void	just_pourcent(int do_it)
{
	if (!do_it)
		return ;
	printf("%s'42%%'\n",
		"\tJust pourcent:\n\t\x20");
}

// ############################################################################

// SPECIFIERS REVIEW
	// NOT TREATED:  
	// TREATED: %c, %s, %i, %d, %u %x %p %% 

// FLAGS REVIEW
	// NOT TREATED:  
	// TREATED: ' ' '+' | '#' | '-' '0'

// OPTIONS REVIEW
	// NOT TREATED:  precision
	// TREATED: min length,

// ############################################################################

int	main(void)
{
	// format_string(1);
	// character_specifier(1);
	// string_specifier(1);
	// integer_specifier(1);
	// unsigned_specifier(1);
	hexadecimal_specifier(1);
	// pointer_specifier(1);
	// just_pourcent(1);
	// ------------------------- //
	// format_string_err(1);
	// character_specifier_err(1);
	// string_specifier_err(0);
	// integer_specifier_err(1);
	// unsigned_specifier_err(1);
	// hexadecimal_specifier_err(1);
	// pointer_specifier_err(1);
}

// ############################################################################

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
