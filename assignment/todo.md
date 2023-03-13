# Ft_Printf, what to do next?


## Create libftprintf.a

- [X] Correct the Makefile that creates libftprintf.a so it builds libft.a too
- [X] Problems to rebuild project when update with make -C. What to do?

## Manage a conversion to the minimum for example

- [X] Start by managing %i/%d with one int argument
- [X] Why not try %i/%d with more int argument

## Manage more conversions to the minimum

- [X] Let's try with another specifier: %c
- [X] Let's try with another specifier: %u
- [x] Let's try with another specifier: %s
- [x] Let's try with another specifier: %x, %X
- [x] Let's try with another specifier: %p
- [x] Let's try with another specifier: %%

## Manage the return type

- [x] Manage the return type. What should be returned ? Number of characters 
printed on stdout.

## Manage one flag for example

- [x] Think about the general strategy to manage multiple flags
-	[ ] First try, is it enough?
- [ ] Implement this strategy and test it with one flag at minimum.

## Manage the parsing system 
	- [ ] Parser.c, repair the system that produces the offset before even
	continuing thinking about processing the flags.
	- [ ] Improve the parsing system so it can manage the cases where a
	specification is miswritten.

## Manage the rest basic printf flags

*Well, we're waiting*

## Evil test your work

- [ ] Find the different testcases 
	- [ ] %p
		- [ ] 0 should return (nil) and not 0x0...
	- [ ] flags
		- [ ] multiple times the same flag ? Rep: no effect.
			  - [ ] multiple times the same flag but no conversion specifier ? 
			  each flag printed once.
		- [ ] negative precision ? How is atoi affected?
		- [ ] negative precision ? How is 
	- [ ] %
		- [ ] % alone is printed on stdout?