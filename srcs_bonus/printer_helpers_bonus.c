/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:13:20 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/11 18:25:43 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

bool	is_type(t_meta *meta, enum e_type type)
{
	unsigned int	res;

	res = 0;
	if (type & CV_CHR)
		res += (*meta->type == 'c');
	if (type & CV_STR)
		res += (*meta->type == 's');
	if (type & CV_PTR)
		res += (*meta->type == 'p');
	if (type & CV_INT)
		res += (*meta->type == 'd' || *meta->type == 'i');
	if (type & CV_UINT)
		res += (*meta->type == 'u');
	if (type & CV_HEXL)
		res += (*meta->type == 'x');
	if (type & CV_HEXU)
		res += (*meta->type == 'X');
	if (type & CV_HEX)
		res += (*meta->type == 'x' || *meta->type == 'X');
	if (type & CV_PRC)
		res += (*meta->type == '%');
	return (res);
}
