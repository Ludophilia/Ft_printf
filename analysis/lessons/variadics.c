/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:43:26 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/04 16:11:18 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	variadics_example(int c, ...)
{
	va_list	vstart;

	va_start(vstart, c);
	ft_putchar(c);
	c = va_arg(vstart, int);
	while (c)
	{
		ft_putchar(c);
		c = va_arg(vstart, int); // What's the last argument? Does it end while?
	}
	va_end(vstart);
}

int	main(void)
{
	variadics_example('Y', 'o', 'H', 'R', 'a', 10, 0);
}