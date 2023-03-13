/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/13 18:53:39 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printer/printer.h"
#include "parser.h"
#include "../libft/libft.h"


static int	is_valid_flg(char c)
{
	if (c == '\x20' || c == '+' || c == '#' || c == '-' || c == '0')
		return (1);
	return (0);
}

int	proc_flags(char *spec, t_flag *flags)
{
	int	i;

	i = 0;
	while (spec[i] && is_valid_flg(spec[i]))
	{
		if (spec[i] == '\x20')
			flags->space_f = 1;
		else if (spec[i] == '+')
			flags->plus_f = 1;
		else if (spec[i] == '-')
			flags->dash_f = 1;
		else if (spec[i] == '#')
			flags->pound_f = 1;
		else if (spec[i] == '0')
			flags->zero_f = 1;
		i++;
	}
	return (i);
}

int proc_options(char *spec, t_flag *flags)
{
	int	i;

	i = 0;
	if (spec[i] && ft_isdigit(spec[i]))
		flags->field_v = ft_atoi(spec + i);
	while (spec[i] && ft_isdigit(spec[i]))
		i++;
	if (spec[i] == '.')
		i++;
	if (spec[i] && ft_isdigit(spec[i]))
		flags->prec_v = ft_atoi(spec + i);
	while (spec[i] && ft_isdigit(spec[i]))
		i++;
	return (i);
}

// -> A function "process specifier" that determine what to do with
// the flag information according to the specifier
// -> How to reduce the num of elements here?
// use a general statement like pointer_to_func(next_arg, base,
// counter_pon)
int	proc_conv(char *spec, va_list *args, t_flag *flags, int *ccount)
{
	int	i;
	
	i = 0;
	// How will the flags and options will affect putchar_cctr and the rest??
	// - ...
	(void)flags; // <GET THIS SHIT OFF MEEEE!!!!
	if (spec[i] == 'd' || spec[i] == 'i')
		putnbr_base_cctr(va_arg(*args, int), BASE10, ccount);
	else if (spec[i] == 'u')
		putnbr_base_cctr(va_arg(*args, unsigned int), BASE10, ccount);
	else if (spec[i] == 'c')
		putchar_cctr(va_arg(*args, int), ccount);
	else if (spec[i] == '%')
		putchar_cctr('%', ccount);
	else if (spec[i] == 's')
		putstr_cctr(va_arg(*args, char *), ccount);
	else if (spec[i] == 'x')
		putnbr_base_cctr(va_arg(*args, unsigned int), BASE16L, ccount);
	else if (spec[i] == 'X')
		putnbr_base_cctr(va_arg(*args, unsigned int), BASE16U, ccount);
	else if (spec[i] == 'p')
	{
		putstr_cctr("0x", ccount); // Soooooooon my son, you'll disappear.
		putnbr_base_cctr(va_arg(*args, uintptr_t), BASE16L, ccount);
	}
	i++; // if spec in "diuc%sxXp" i++. this guard makes i = 1 only if the 
	// right specifier appeared.
	return (i);
}

// Process a conversion specification in format string. A conversion spec is :
// %[flag][,flag...][field width][precision][length]conversion_specifier
// It's way too long, and not very clean...
int	proc_specif(char *spec, va_list *args, int *ccount)
{
	t_flag	*flags;
	int		i;

	flags = ft_calloc(1, sizeof(t_flag));
	i = proc_flags(spec, flags);
	i += proc_options(spec + i, flags);
	i += proc_conv(spec + i, args, flags, ccount); // if this returns 0, 
	// then must i = 0;
	free(flags);
	return (i);
}

// printf("\n\tflags: ' ': %d, '+': %d, '*': %d, "
// 	"'.': %d, '-': %d, '0': %d, '#': %d\n",
// 	flags->space_f, flags->plus_f, flags->field_v,
// 	flags->prec_v, flags->dash_f, flags->zero_f, 
// 	flags->pound_f
// );