/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:05:44 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/21 14:56:51 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	pre_proc_specif(const char *spec, t_meta *meta)
{
	int	i;

	i = 0;
	while (spec[i] && is_valid_conv(spec[i]) == 0)
		i++;
	if (spec[i] && is_valid_conv(spec[i]) && set_conv(spec[i], meta))
	{
		pre_proc_prec(spec, i, meta);
		return (1);
	}
	meta->flags = 0;
	return (0);
}

static int	proc_flags(const char *spec, t_meta *meta)
{
	int	i;

	i = 0;
	while (spec[i] && is_valid_flg(spec[i]))
	{
		if (spec[i] == '-')
			meta->flags |= FLG_DASH;
		else if (spec[i] == ' ' && flag(CV_INT, meta))
			meta->flags |= FLG_SPAC;
		else if (spec[i] == '+' && flag(CV_INT, meta))
			meta->flags |= FLG_PLUS;
		else if (spec[i] == '#' && flag(CV_HEX, meta))
			meta->flags |= FLG_POUN;
		else if (spec[i] == '0' && not_flag(FLG_DASH | FLG_PREC, meta)
			&& flag(CV_INT | CV_UINT | CV_HEX, meta))
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
	while (spec[i] && flag(FLG_FIEL, meta) && ft_isdigit(spec[i]))
		i++;
	if (spec[i] == '.')
		i++;
	if (spec[i] && flag(FLG_PREC, meta) && is_valid_conv(spec[i]))
		meta->prec_v = 0;
	else if (spec[i] && flag(FLG_PREC, meta) && ft_isdigit(spec[i]))
		meta->prec_v = ft_atoi(spec + i);
	while (spec[i] && ft_isdigit(spec[i]))
		i++;
	return (i);
}

int	is_valid_specif(const char *spec, t_meta *meta)
{
	int	i;

	meta->flags = 0;
	if (pre_proc_specif(spec, meta) == 0)
		return (0);
	meta->field_v = -1;
	meta->prec_v = -1;
	i = 0;
	i += proc_flags(spec + i, meta);
	i += proc_width_options(spec + i, meta);
	if (spec[i] && is_valid_conv(spec[i]))
	{
		*meta->i += (i);
		return (1);
	}
	return (0);
}
