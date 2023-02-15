# Ft_printf, all testcases

## Prototype

	int	ft_printf(const char *format, ...);

## Return values

* the processed format string on stdout (1)
* the number of characters processed as an int 

## Context

### Overview

Create ft_printf, a function that works the same as printf referenced in stdio.h.

printf is a function that takes:

* a format str (format) as its first argument
* and a variable number of arguments of different types, from character 
to hexadecimal number

### Rules

Each arg beyond the format str is used in the format str according to the 
following rules:

* a conversion specifier (ex: %c) in the format str at a position N will 
be replaced by the argument ~~of the same type~~ **converted** (if possible ?) 
at position N in the va_list. 

<!-- * A mismatch or an absence of match between a type specifier in
the format str and the positional arg will generate: 
	* an error (really ? example plz)
	* an undefined behavior (really ? example plz)
	* or a type conversion in some case (eg from integer to unsigned integer) -->

### Conversion specifiers

#### Overview

There are different types of conversion or format specifiers. Their format is
habitually as follow : 
	
`% + [flag[, flag...]] + conversion_specifier`

Here are some of them:

* %c : character placeholder
* %s : C character string placeholder (so null terminated ?)

* %d : signed integer placeholder
* %i : signed integer placeholder
* %u : unsigned integer placeholder

* %p : (void *) pointer placeholder (hexadecimal, lowercase, starts with 0x)
* %x : hexadecimal placeholder (a to f are lowercase)
* %X : hexadecimal placeholder (A to F are uppercase)

* %% : prints %

#### Optionals flags

As stated before the format of conversions support flags 
`% + [flag[, flags...]]+ conversion_specifier`. Here are the possible flags:

<!-- * minimum field width modifier
* precision modifier
* length modifier -->

* \# - pound sign: the value should be converted to another form. As far we're 
concerned for (%x, %X) conversions, a nonzero result has the string "0x" (or 
"0X" for X conversions) prepended to it .
* ' ' - space: a blank should be left before a positive number (or empty 
string (WTF?)) produced by a signed conversion (%d, %i).
* \+ - plus sign: A sign (+ or -) should always be placed before a number 
produced by a signed conversion (%d, %i). By default, a sign is used only for 
negative numbers. **A + overrides a space if both are used.**

## Test material
	hon hon hon baguette non non non merci je prefere le vin

## Testcases

Arguments specifier mismatch

~~(C) 2023, 🟢🔴 Productions~~