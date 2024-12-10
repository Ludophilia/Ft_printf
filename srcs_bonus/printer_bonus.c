/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:12 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/10 11:56:56 by jegerman         ###   ########.fr       */
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

int	ft_putnbr_base_cc(t_nbr *nbr, char *digits, t_meta *meta)
{
	size_t	radix;
	t_nbr	*tmp;

	if (*meta->type == 'p'
		&& nbr->magn == 0 && ft_putstr_cc("(nil)", meta))
		return (1);
	radix = ft_strlen(digits);
	tmp = &(t_nbr){.magn = nbr->magn / radix, .sign = nbr->sign};
	if (nbr->magn >= radix)
		ft_putnbr_base_cc(tmp, digits, meta);
	if (nbr->sign == 1 && nbr->magn < radix)
		ft_putchar_cc('-', meta);
	else if (nbr->magn < radix && *meta->type == 'p')
		ft_putstr_cc("0x", meta);
	ft_putchar_cc(digits[nbr->magn % radix], meta);
	return (1);
}
