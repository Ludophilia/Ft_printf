/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:24:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 15:35:35 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	putchar_cctr(char c, int *ccount_p)
{
	ft_putchar_fd(c, 1);
	*ccount_p += 1;
	return (1);
}

int	putstr_cctr(char *s, int *ccount_p)
{
	ft_putstr_fd(s, 1);
	*ccount_p += ft_strlen(s);
	return (1);
}

int	putnbr_base_cctr(long long nb, char *base, int *ccount_p)
{
	long long	radix;

	radix = ft_strlen(base);
	if (nb >= radix || nb <= -radix)
		putnbr_base_cctr(nb / radix, base, ccount_p);
	if (nb < 0 && nb > -radix)
		ft_putchar_fd('-', ccount_p);
	if (nb < 0)
		nb = -(nb % radix);
	else
		nb = (nb % radix);
	ft_putchar_fd(base[nb], ccount_p);
	return (1);
}
