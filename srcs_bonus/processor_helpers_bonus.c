/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:53:34 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 15:35:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	flags(unsigned int flags, t_meta *meta)
{
	return ((meta->flags & (flags)) == (flags));
}

int	not_flags(unsigned int flags, t_meta *meta)
{
	return ((meta->flags & (flags)) == 0);
}

int	flag(unsigned int flags, t_meta *meta)
{
	return (meta->flags & (flags));
}

int	not_flag(unsigned int flags, t_meta *meta)
{
	return (!(meta->flags & (flags)));
}

void	process_filler_width(void *data, t_meta *m)
{
	int	i;

	if (flag(CV_STR, m) && data != NULL)
	{
		i = -1;
		while (((char *)data)[++i] && ((flag(FLG_PREC, m) && i < m->prec_v)
				|| (not_flag(FLG_PREC, m))) && m->field_v > 0)
			m->field_v -= 1;
	}
	else if (flag(CV_CHR, m) && not_flag(CV_PRC, m))
	{
		m->field_v -= 1;
	}
	else if (flag(CV_INT | CV_HEX | CV_PTR | CV_UINT, m) && data != NULL)
	{
		m->field_v -= ft_strlen(((t_nbr *)data)->prc_magn);
		if (flag(CV_INT, m)
			&& (((t_nbr *)data)->sign || flag(FLG_PLUS | FLG_SPAC, m)))
			m->field_v -= 1;
		if ((flag(CV_PTR, m) || flags(CV_HEX | FLG_POUN, m))
			&& ((t_nbr *)data)->magn != 0)
			m->field_v -= 2;
	}
}
