/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:49:07 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/07 20:58:37 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	un_putnbr_fd(unsigned int nb, int fd)
{
	if (fd < 0)
		return ;
	if (nb >= 10 || nb <= -10)
		un_putnbr_fd(nb / 10, fd);
	if (nb < 0 && nb > -10)
		un_putnbr_fd('-', fd);
	if (nb < 0)
		nb = '0' + -(nb % 10);
	else
		nb = '0' + (nb % 10);
	ft_putchar_fd(nb, fd);
}
