/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/06 22:10:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	process_specifier(char *format, va_list *args)
{
	// a function that will analyse the % * part
	// and do something with it...
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
			ft_putnbr_fd(va_arg(*args, unsigned int), 1);
			break ;
		}
	}
	return (i);
}