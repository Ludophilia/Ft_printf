/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:13 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/22 16:48:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
		if (format[i] == '%' && is_valid_specif(format + ++i, &meta))
			process_specifier(&meta);
		else
			ft_putchar_cc(format[i++], &meta);
	}
	va_end(meta.args);
	return (meta.count);
}
