/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/09 22:40:20 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	process_specifier(char *specifier, va_list *args)
{
	// "It's way too long", if you know what I mean (the norm, nothing else)
	int	i;

	i = -1;
	while (specifier[++i]) // starts from the first %
	{
		if (specifier[i] == 'd' || specifier[i] == 'i')
		{
			ft_putnbr_fd(va_arg(*args, int), 1);
			break ;
		}
		else if (specifier[i] == 'c')
		{
			ft_putchar_fd(va_arg(*args, int), 1);
			break ;
		}
		else if (specifier[i] == 'u')
		{
			ll_putnbr_fd(va_arg(*args, unsigned int), 1);
			break ;
		}
		else if (specifier[i] == 's')
		{
			ft_putstr_fd(va_arg(*args, char *), 1);
			break ;
		}
		else if (specifier[i] == 'x' || specifier[i] == 'X')
		{
			char	*base16;

			if (specifier[i] == 'x')
				base16 = "0123456789abcdef";
			else
				base16 = "0123456789ABCDEF";
			ll_putnbr_base_fd(va_arg(*args, unsigned int), base16, 1);
			break ;
		}
		else if (specifier[i] == 'p')
		{		
			ft_putstr_fd("0x", 1);
			ll_putnbr_base_fd(va_arg(*args, uintptr_t), "0123456789abcdef", 1);
			// may be too much
			break ;
		}
		else if (specifier[i] == '%' && specifier[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
			break ;
		}
	}
	return (i);
}