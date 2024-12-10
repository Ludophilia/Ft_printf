/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:13 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/10 18:14:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// FORMAT
// %[flags][width][precision]sp

// SPECIFIER (sp)
// c spdiuxX%

// ---------------------------

// -
// width


// 0 (d, i, u, x, X)
// # (x, X)
// + (d, i)
// space (d, i?)

// . (s, d, i, u, x, X)

// ---------------------------

// NEXT TESTS
// - Errors 
// - %c with - and width
// - 

bool	is_valid_flg(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

bool	is_valid_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

// unsigned int	flags;


static int	proc_flags(const char *spec, t_meta *meta)
{
	int	i;

	i = 0;
	while (spec[i] && is_valid_flg(spec[i]))
	{
		if (spec[i] == ' ')
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

static int	proc_width_options(const char *spec, t_meta *meta)
{
	int	i;

	i = 0;
	if (spec[i] && ft_isdigit(spec[i]))
	{
		flags->field_f = 1;
		flags->field_v = ft_atoi(spec + i);
	}
	while (spec[i] && ft_isdigit(spec[i]))
		i++;
	if (spec[i] == '.')
	{
		flags->prec_f = 1;
		i++;
	}
	if (spec[i] && ft_isdigit(spec[i]))
		flags->prec_v = ft_atoi(spec + i);
	while (spec[i] && ft_isdigit(spec[i]))
		i++;
	return (i);
}

// %[flags][width][precision]sp

int	is_valid_specifier(const char *spec, t_meta *meta)
{
	int	i;

	i = proc_flags(char *spec, t_meta *meta);
	i += 

	if (spec[i] && is_valid_type())
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_meta	meta;
	int		i;

	if (format == NULL)
		return (-1);
	i = 0;
	meta = (t_meta){.i = &i, .count = 0};
	va_start(meta.args, format);
	while (format[i])
	{
		if (format[i] == '%' && is_valid_specifier(format + i + 1, &meta))
			process_specifier(format + i + 1, &meta);
		else
			ft_putchar_cc(format[i++], &meta);
	}
	va_end(meta.args);
	return (meta.count);
}
