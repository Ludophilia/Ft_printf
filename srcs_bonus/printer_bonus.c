/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:12 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/15 16:18:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_cc(const char c, t_meta *meta)
{
	write(1, &c, 1);
	meta->count++;
	return (1);
}

int	ft_putstr_cc(const char *str, t_meta *meta)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 0)
		return (1);
	write(1, str, len);
	meta->count += len;
	return (1);
}

void	print_filler(bool zfill, t_meta *meta)
{
	while (meta->field_v-- > 0)
		ft_putchar_cc((char [2]){' ', '0'}[zfill], meta);
}

// IMPROVE THIS, OF COURSE
int	print_prefix(t_nbr *nbr, t_meta *meta)
{
	if (nbr->sign == 1 && nbr->magn < radix)
		ft_putchar_cc('-', meta);
	else if (nbr->magn < radix && flag(CV_PTR, meta))
		ft_putstr_cc("0x", meta);

	return (1);
}

// A new function 

int	ft_putnbr_base_cc(t_nbr *nbr, t_meta *meta)
{
	size_t	radix;
	t_nbr	*tmp;

	if (flag(CV_PTR, meta) && nbr->magn == 0 && ft_putstr_cc("(nil)", meta))
		return (1);
	radix = ft_strlen(nbr->base);
	tmp = &(t_nbr){.magn = nbr->magn / radix, .sign = nbr->sign,
		.base = nbr->base};
	if (nbr->magn >= radix)
		ft_putnbr_base_cc(tmp, meta);

	// Move somewhere else
	// if (nbr->sign == 1 && nbr->magn < radix)
	// 	ft_putchar_cc('-', meta);
	// else if (nbr->magn < radix && flag(CV_PTR, meta))
	// 	ft_putstr_cc("0x", meta);

	// Replace with a function that writes into a buffer
	ft_putchar_cc(digits[nbr->magn % radix], meta);
	return (1);
}
