/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:13:20 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/12 17:59:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_filler(bool zfill, t_meta *meta)
{
	while (meta->field_v-- > 0)
		ft_putchar_cc((char [2]){' ', '0'}[zfill], meta);
}
