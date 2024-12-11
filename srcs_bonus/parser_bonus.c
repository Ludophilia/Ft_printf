/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:05:44 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/11 16:10:18 by jegerman         ###   ########.fr       */
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

static int	proc_flags(const char *spec, t_meta *meta)
{
	int	i;

	i = 0;
	while (spec[i] && is_valid_flg(spec[i]))
	{
		if (spec[i] == ' ')
			meta->flags |= FLG_SPAC;
		else if (spec[i] == '+')
			meta->flags |= FLG_PLUS;
		else if (spec[i] == '-')
			meta->flags |= FLG_DASH;
		else if (spec[i] == '#')
			meta->flags |= FLG_POUN;
		else if (spec[i] == '0')
			meta->flags |= FLG_ZERO;
		i++;
	}
	return (i);
}

static int	proc_width_options(const char *spec, t_meta *meta)
{
	int	i;

	i = 0;
	if (spec[i] && ft_isdigit(spec[i]))
	{
		meta->flags |= FLG_FIEL;
		meta->field_v = ft_atoi(spec);
	}
	while (spec[i] && ft_isdigit(spec[i]))
		i++;
	if (spec[i] == '.') // What about its implicit value?
	{
		meta->flags |= FLG_PREC;
		i++;
	}
	if (spec[i] && ft_isdigit(spec[i]))
		meta->prec_v = ft_atoi(spec + i);
	while (spec[i] && ft_isdigit(spec[i]))
		i++;
	return (i);
}

int	is_valid_specif(const char *spec, t_meta *meta)
{
	int	i;

	i = proc_flags(spec, meta);
	i += proc_width_options(spec, meta);
	if (spec[i] && is_valid_conv(spec[i]))
	{
		*meta->i += (i - 1);
		return (1);
	}
	return (0);
}
