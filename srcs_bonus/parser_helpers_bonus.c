/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:26:51 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/21 14:57:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

bool	is_valid_flg(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

bool	is_valid_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	pre_proc_prec(const char *spec, int limit, t_meta *meta)
{
	int	i;

	i = -1;
	while (spec[++i] && i < limit)
	{
		if (spec[i] == '.' && flag(CV_STR | CV_INT | CV_UINT | CV_HEX, meta)
			&& (is_valid_conv(spec[i + 1]) || ft_isdigit(spec[i + 1])))
		{
			meta->flags |= FLG_PREC;
			return (1);
		}
	}
	return (0);
}

int	set_conv(char c, t_meta *meta)
{
	if (c == 'c')
		meta->flags |= CV_CHR;
	else if (c == 's')
		meta->flags |= CV_STR;
	else if (c == 'p')
		meta->flags |= CV_PTR;
	else if (c == 'd' || c == 'i')
		meta->flags |= CV_INT;
	else if (c == 'u')
		meta->flags |= CV_UINT;
	else if (c == 'x' || c == 'X')
		meta->flags |= CV_HEX;
	else if (c == '%')
		meta->flags |= CV_PRC;
	if (c == 'x')
		meta->flags |= CV_HEXL;
	else if (c == 'X')
		meta->flags |= CV_HEXU;
	return (1);
}
