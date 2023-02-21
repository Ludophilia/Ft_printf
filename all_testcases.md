# Ft_printf, all testcases

## Prototype

	int	ft_printf(const char *format, ...);

## Return values

* the processed format string on stdout(1)
* the number of characters processed as an int 

## Context

### Overview

Create ft_printf, a function that works the same as printf referenced in 
stdio.h.

printf is a function that takes:

* a format str as its first argument
* and a variable number of arguments of different types, from character 
to hexadecimal number

### Rules

Each arg beyond the format str is used in the format str according to the 
following rules:

* a conversion specification (ex: %c) in the format str at a position N will 
be replaced by the argument at position N in the va_list of the a required type,
**converted**. The matching between the positions of a specification and 
position of arguments (ex: spec 3 match 1st argument) can be controlled.
* A mismatch or an absence of match between a type specifier in
the format str and the positional arg will generate a warning and/or an error.

### Conversion specification

#### Overview

There are different types of conversion specification. Their format is
habitually as follow : 
	
`%[flag][,flag...][field width][precision][length]conversion_specifier`

#### Conversions specifier

Here are the conversion specifiers that will be implemented:

* %c : Character placeholder. If no l length modifier is present, the
**int argument** is converted to an **unsigned char**, and the resulting 
character is written on stdout.
* %s : C character string placeholder. Reminder: C character string are null
terminated. If no l length modifier is present: the **const char * argument** is 
expected to be a pointer to an array of character type. Characters from the 
array are written up to (but not including) a terminating null byte ('\0'); 
**if a precision is specified**, no more than the number specified
are written and no null byte need be present; **if the precision is not** 
**specified, or greater than the size of the array**, the array must contain a
terminating null byte.
* %d, %i : Signed integer placeholder. The **int argument** is converted to
**signed decimal notation** (base 10, signed). The precision, if any, gives 
the minimum number of digits that must appear; if the converted value 
requires fewer digits, it is **padded on the left with zeros**. The default 
precision is 1. When 0 is printed with an explicit precision 0, the output is 
empty.
* %u : unsigned integer placeholder. The **unsigned int** argument is converted 
to **unsigned decimal (base 10)** notation. The letters abcdef are used for x
conversions; the letters ABCDEF are used for X conversions. The **precision**, 
if any, gives the **minimum number of digits** that must appear; if the 
converted value requires fewer digits, it is padded on the left with zeros.
The default precision is 1. When 0 is printed with an explicit precision 0, 
the output is empty.

**PLEASE CHECK AGAIN THIS SHIT BELOW**

* %p : (void *) pointer placeholder (hexadecimal, lowercase, starts with 0x)
* %x : hexadecimal placeholder (a to f are lowercase)
* %X : hexadecimal placeholder (A to F are uppercase)

* %% : prints %

#### Flag

Here are the flags that will be treated for this exercice:

* \- (dash sign):
	* The converted value is to be left adjusted on the field boundary. 
	The default is right justification. The converted value is padded on the 
	right with blanks, rather than on the left with blanks or zeros.
	* For ~~%d, %i, %u, %x, %X~~ ~~%c, %s, %p?~~
	* Dynamics with '.' and '0':
		* A '-' overrides a '0' if both are given. 
		* (Interactions with '.' ?)
	
* 0 (zero sign):
	* The value should be zero padded. For %d, %i, %u, %x, %X 
	conversions, the converted value is padded on the left with zeros rather 
	than blanks. For other conversions, the behavior is undefined. 
	* For ~~%d, %i, %u, %x, %X~~
	* Dynamics with '.' and '-':
		* This '0' flag is ignored if:
			* used with '-' flag
			* a '.' precision is given with a numeric conversion (d, i, u, x, 
			and X)

* \# (pound sign): 
	* the value should be converted to another form. As far we're concerned for 
	(%x, %X) conversions, a nonzero result has the string "0x" (or "0X" for X 
	conversions) prepended to it.
	* For %x, %X

* ' ' (space):
	* a blank should be left before a **positive number** (or empty 
	string<sup>WTF?</sup>) produced by a signed conversion (%d, %i).
	* For %d, %i
	* Dynamics with '+':
		* A ' ' is ignored if '+' if used.

* \+ (plus sign):
	* A sign (+ or -) should always be placed before a number produced by a 
	signed conversion (%d, %i). By default, a sign is used only for negative 
	numbers. 
	* For %d, %i
	* Dynamics with ' ':
		* A '+' overrides a ' ' space if both are used.

#### Field width

* \* (star sign):
	* The min field width is an optional non-zero digit string specifying
	a minimum field width. (e.g : %10d) If the converted value has fewer 
	characters than the field width, it will be padded with **spaces** on the 
	left. Instead of a decimal digit string one may write "*" or "*m$" (e.g.: 
	%*d or %*2$d) to specify that the field width is given in the next argument,
	or in the m-th argument, respectively, which must be of type int.
	In no case does a nonexistent or small field width cause truncation of a 
	field; if the result of a conversion is wider than the field width, the 
	field is expanded to contain the conversion result.
	* For d, i, u, x, and X conversions. And c, s, p too?
	* Dynamics with '-':
		* If the converted value has fewer characters than the field width,
		it will be padded with **spaces** on the right. A negative field width
		is taken as a '-' flag followed by a positive field width.

#### Precision

* . (dot sign):
	* A dot sign followed by an optional decimal digit string 
	(e.g: %.5d or %.d). This gives the minimum number of digits to appear 
	for d, i, u, x, and X conversions. Instead of a decimal digit string one 
	may write "*" or "*m$" (e.g.: %.*d or %.2$d) to specify that the precision 
	is given in **the next argument**, or in the **m-th argument**, 
	respectively, which must be of type int. If the precision is given as just
	'.', the precision is taken to be zero. A negative precision is taken as 
	if the precision were omitted.
	* For d, i, u, x, and X conversions.
	* Dynamics with '0' and '-':
		* '.' override '0' if used with a numeric conversion (d, i, u, x, and X)
		* (Interactions with '-' ?)

#### Synthesis

*Should I build a table?*

In the end, **three things** have to be figured with ft_printf:
1. How each conversion specifier interacts with a literal ? What data will be
displayed on stdout? Ex: what happens when %u is used with a -IB10 
(Negative Integer base 10), or a IB8, or CR (character) or a -FL ?
2. How each flag affect the representation of the converted data? How data 
will be displayed on stdout? ex : 0 flag pads data representation with 0 for
certains conversions, # flag apprends 0x or 0X to the %x or %X specifier... 
3. How each flag affect other flags for each conversion specifiers?
What happens when you combine 2, 3, 4, 6 flags together?
ex : 0 flag pads data representation with  0 for certains conversions, but 
can't be used with . flag and - flag. For this exercise, we'll focus esp. on 
what happens when -, 0 and . are combined together,
**each possible 2-uplet/couple or 3-uplet/triple.**

## Test material
	hon hon hon baguette non non non merci je prefere le vin

## Testcases

Arguments specifier mismatch

~~(C) 2023, 🟢🔴 Productions~~