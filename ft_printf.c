/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:13 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/03 18:01:38 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %s Prints a string (as defined by the common C convention).

// %p The void * pointer argument has to be printed in hexadecimal format.

// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.

// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.

void	ft_putchar_cc(const char c, int *count)
{
	write(1, &c, 1);
	++(*count);
}

void	ft_putstr_cc(const char *str, int *count)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 0)
		return ;
	write(1, str, len);
	*count += ft_strlen(str);
}

void	process_character_specifier(va_list args, int *i, int *count)
{
	int c;

	c = va_arg(args, int);
	ft_putchar_cc(c, count);
	*i += 2;
}

void	process_string_specifier(va_list args, int *i, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_cc(str, count);
	*i += 2;
}

void	process_specifier(const char *c, va_list args, int *i, int *count)
{
	if (*c == 'c')
		process_character_specifier(args, i, count);
	else if (*c == 's')
		process_string_specifier(args, i, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			process_specifier(format + i + 1, args, &i, &count);
		else
			ft_putchar_cc(format[i++], &count);
	}
	va_end(args);
	return (count);
}
