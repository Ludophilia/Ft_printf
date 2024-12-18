/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/18 18:49:24 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	process_character_specifier(t_meta *m)
{
	int	c;

	c = '%';
	if (flag(CV_CHR, m) && not_flag(CV_PRC, m))
		c = va_arg(m->args, int);
	if (flags(FLG_FIEL | CV_CHR, m) && not_flag(CV_PRC, m))
		m->field_v -= 1;
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
	i = -1;
	while (str[++i] && ((flags(FLG_FIEL | FLG_PREC, m) && i < m->prec_v)
			|| (flag(FLG_FIEL, m) && not_flag(FLG_PREC, m))) && m->field_v)
		m->field_v -= 1;
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

// Number
// [filler][prefix|sign][precision|filler_zero][magnitude][filler]
static void	process_number_specifier(t_meta *m)
{
	t_nbr	nbr;
	char	*magn;

	// Store the number and the precision in a buffer
	magn = set_magnitude_buffer(&nbr, m);
	if (magn == NULL)
		return ;

	// Adjust the field width for the fillers
	if (flag(FLG_FIEL))
		m->field_v -= ft_strlen(magn);
	if (flags(FLG_FIEL | CV_INT, m)
		&& (nbr.sign || flag(FLG_PLUS | FLG_SPAC, m)))
		flags->field_v -= 1;
	else if (flag(FLG_FIEL) && nb.abs != 0
		&& (flags(CV_PTR, m) || flags(CV_HEX | FLG_POUN, m)))
		flags->field_v -= 2;

	// Add prefix
	if (flags(FLG_ZERO | FLG_FIEL, m) && not_flag(FLG_PREC, m))
		print_prefix(&nbr, m);
	// Add filler
	if (not_flag(FLG_ZERO, m) || (flag(FLG_ZERO, m)
			&& (flag(FLG_PREC, m) || (!nb.abs && flag(CV_PTR, m)))))
		print_filler(NOZEROFILL, m);
	else if (flag(FLG_ZERO, m) && not_flag(FLG_PREC, m))
		print_filler(ZEROFILL, m);

	// Add prefix
	if (flag(FLG_PREC) && not_flags(FLG_FIEL | FLG_ZERO))
		print_prefix(&nbr, m);
  
	ft_putstr(magn, m);
	
	// Add filler
	if (flag(FLG_DASH, m))
		print_filler(NOZEROFILL, m);

	free(magn);
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
