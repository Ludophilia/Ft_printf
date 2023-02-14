# Ft_printf, all testcases

## Prototype

	int	ft_printf(const char *format, ...);

## Return values

* the processed format string on stdout (1)
* the number of characters processed as an int 

## Context

### Overview

Create ft_printf, a function that works the same as printf referenced in
stdio.h.

printf is a function that takes:

* a format str (format) as its first argument
* and a variable number of arguments of different types, from character 
to hexadecimal number

### Format specifiers

Each arg beyond the format str is used in the format str according to the following rules:

* a format specifier (ex: %c) in the format str at a position N will 
be replaced by the argument of the same type at posiiton N in the 
va_list. 

	* There are different types of format specifiers:
		* %c : character placeholder
		* %s : C character string placeholder (so null terminated ?)

		* %d : signed integer placeholder
		* %i : signed integer (some say unsigned) placeholder
		* %u : unsigned integer placeholder

		* %p : void * pointer placeholder (hexadecimal, lowercase, starts with 0x)
		* %x : hexadecimal placeholder (a to f are lowercase)
		* %X : hexadecimal placeholder (A to F are uppercase)
		
		* %% : prints %
	
	* A mismatch or an absence of match between a type specifier in
	the format str and the positional arg will generate: 
		* an error 
		* an undefined behavior
		* or a type conversion in some case (eg from integer to unsigned integer)

	
## Test material
	hon hon hon baguette non non non merci je prefere le vin


## Testcases



~~(C) 2023, 🟢🔴 Productions~~