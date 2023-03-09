/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:07 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/09 20:51:39 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ll_putnbr_fd(long long int nb, int fd)
{
	if (fd < 0)
		return ;
	if (nb >= 10 || nb <= -10)
		ll_putnbr_fd(nb / 10, fd);
	if (nb < 0 && nb > -10)
		ft_putchar_fd('-', fd);
	if (nb < 0)
		nb = '0' + -(nb % 10);
	else
		nb = '0' + (nb % 10);
	ft_putchar_fd(nb, fd);
}

void	ll_putnbr_base_fd(long long int nb, char *base, int fd)
{
	long long	radix;

	if (fd < 0)
		return ;
	radix = ft_strlen(base);
	if (nb >= radix || nb <= -radix)
		ll_putnbr_base_fd(nb / radix, base, fd);
	if (nb < 0 && nb > -radix)
		ft_putchar_fd('-', fd);
	if (nb < 0)
		nb = -(nb % radix);
	else
		nb = (nb % radix);
	ft_putchar_fd(base[nb], fd);
}
