/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:24:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/14 17:19:44 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "printer.h"

void	putchar_cctr(char c, int *ccount)
{
	ft_putchar_fd(c, 1);
	*ccount += 1;
}

void	putstr_cctr(char *s, int *ccount)
{
	ft_putstr_fd(s, 1);
	*ccount += ft_strlen(s);
}

void	putnbr_base_cctr(long long nb, char *base, int *ccount)
{
	long long	radix;

	radix = ft_strlen(base);
	if (nb >= radix || nb <= -radix)
		putnbr_base_cctr(nb / radix, base, ccount);
	if (nb < 0)
		nb = -(nb % radix);
	else
		nb = (nb % radix);
	putchar_cctr(base[nb], ccount);
}

// Double wrapper?? Rename this unit printer_helpers or something like this...

void	putnbr_base(long long nb, char *base, t_flag *flags, int *ccount)
{
	// What should be done here, according to the flags ?

	// '+' - A sign (+/-) is placed before the number for %i/%d.
	// ' ' -
	
	// '#' -
	
	// '-' - 
	// '*' -
	// '.' - 
	// '0' - 
	unsigned int  conv_t;
	
	conv_t = flags->conv_t;
	if (nb < 0) // Move somewhere else?
		putchar_cctr('-', ccount);
	else if (nb >= 0 && flags->plus_f && (conv_t == 'i' || conv_t == 'd')) // dirty?
		putchar_cctr('+', ccount);
	putnbr_base_cctr(nb, base, ccount);
}
