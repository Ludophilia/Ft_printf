/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 15:04:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	process_filler_width(void *data, t_meta *m)
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

static void	process_character_specifier(t_meta *m)
{
	int	c;

	c = '%';
	if (flag(CV_CHR, m) && not_flag(CV_PRC, m))
		c = va_arg(m->args, int);
	if (flag(FLG_FIEL, m))
		process_filler_width(NULL, m);
	if (flags(FLG_FIEL | CV_CHR, m) && not_flags(CV_PRC | FLG_DASH, m))
		print_filler(NOZEROFILL, m);
	ft_putchar_cc(c, m);
	if (flags(FLG_FIEL | CV_CHR | FLG_DASH, m) && not_flag(CV_PRC, m))
		print_filler(NOZEROFILL, m);
	*m->i += 1;
}

static void	process_string_specifier(t_meta *m)
{
	char	*str;
	int		i;

	str = va_arg(m->args, char *);
	if (str == NULL && flag(FLG_PREC, m) && m->prec_v < 6)
		str = "";
	else if (str == NULL)
		str = "(null)";
	if (flag(FLG_FIEL, m))
		process_filler_width(str, m);
	if (not_flag(FLG_DASH, m) && m->field_v > 0)
		print_filler(NOZEROFILL, m);
	i = 0;
	while (flag(FLG_PREC, m) && str[i] && i < m->prec_v)
		ft_putchar_cc(str[i++], m);
	if (not_flag(FLG_PREC, m))
		ft_putstr_cc(str, m);
	if (flag(FLG_DASH, m) && m->field_v > 0)
		print_filler(NOZEROFILL, m);
	*m->i += 1;
}

static void	process_number_specifier(t_meta *m)
{
	t_nbr	nbr;

	if (set_magnitude_buffer(&nbr, m) == NULL)
		return ;
	if (flag(FLG_FIEL, m))
		process_filler_width(&nbr, m);
	if (flag(CV_PTR | FLG_PLUS | FLG_SPAC, m) || nbr.sign
		|| (flags(FLG_ZERO | FLG_FIEL, m) && not_flag(FLG_PREC, m)))
		print_prefix(&nbr, m);
	if (flag(FLG_ZERO, m) && not_flag(FLG_PREC, m))
		print_filler(ZEROFILL, m);
	else if (not_flag(FLG_ZERO, m) || (flag(FLG_ZERO, m)
			&& (flag(FLG_PREC, m) || (!nbr.magn && flag(CV_PTR, m)))))
		print_filler(NOZEROFILL, m);
	if (flag(FLG_PREC, m) && not_flags(FLG_FIEL | FLG_ZERO, m))
		print_prefix(&nbr, m);
	ft_putstr_cc(nbr.prc_magn, m);
	if (flag(FLG_DASH, m))
		print_filler(NOZEROFILL, m);
	free(nbr.prc_magn);
	*m->i += 1;
}

void	process_specifier(const char *c, t_meta *m)
{
	set_conv(*c, m);
	if (flag(CV_CHR | CV_PRC, m))
		process_character_specifier(m);
	else if (flag(CV_STR, m))
		process_string_specifier(m);
	else if (flag(CV_HEX | CV_INT | CV_PTR | CV_UINT, m))
		process_number_specifier(m);
	else
		*m->i += 1;
}
