# Ft_printf, all testcases

## Prototype

	int	ft_printf(const char *format, ...);

## Returned values

* the processed format string on stdout(1)
* the number of characters processed as an int 

## Goal

Create ft_printf, a function that works the same as printf referenced in 
stdio.h.

printf is a function that takes:

* a format str as its first argument
* and a variable number of arguments of different types, from character 
to hexadecimal number

Printf convert and render each arguments according to the a combination of
symbols called conversion specifier. A description of those specifiers can
be found in the analysis document.

## Test material
	hon hon hon baguette non non non merci je prefere le vin

## Testcases

Arguments specifier mismatch

~~(C) 2023, 🟢🔴 Productions~~