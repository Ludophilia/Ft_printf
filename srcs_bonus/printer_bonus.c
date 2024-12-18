/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:12 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/18 16:23:54 by jegerman         ###   ########.fr       */
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
