/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/08 22:41:35 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	process_specifier(char *format, va_list *args)
{
	// a function that will analyse the % * part
	// and do something with it, for sure...
	int	i;

	i = -1;
	while (format[++i]) // starts from the first %
	{
		if (format[i] == 'd' || format[i] == 'i')
		{
			ft_putnbr_fd(va_arg(*args, int), 1);
			break ;
		}
		else if (format[i] == 'c')
		{
			ft_putchar_fd(va_arg(*args, int), 1);
			break ;
		}
		else if (format[i] == 'u')
		{
			ll_putnbr_fd(va_arg(*args, unsigned int), 1);
			break ;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
			break ;
		}
	}
	return (i);
}