/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:12 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putnbr_base_cc(t_nbr *nbr, char *digits, int *count)
{
	size_t	radix;
	t_nbr	*tmp;

	radix = ft_strlen(digits);
	tmp = &(t_nbr){.magn = nbr->magn / radix, .sign = nbr->sign};
	if (nbr->magn >= radix)
		ft_putnbr_base_cc(tmp, digits, count);
	if (nbr->sign == 1 && nbr->magn < radix)
		ft_putchar_cc('-', count);
	ft_putchar_cc(digits[nbr->magn % radix], count);
}
