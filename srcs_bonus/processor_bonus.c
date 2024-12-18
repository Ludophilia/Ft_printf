/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/18 16:33:57 by jegerman         ###   ########.fr       */
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

// void	print_prefix(t_nbr nb, t_flag *flags, int *count)
// {
// 	if (is_int(flags))
// 	{
// 		if (!(nb.sign || flags->plus_f || flags->space_f))
// 			return ;
// 		if (nb.sign)
// 			putchar_cc('-', count);
// 		else
// 		{
// 			if (flags->plus_f)
// 				putchar_cc('+', count);
// 			else if (flags->space_f)
// 				putchar_cc(' ', count);
// 		}
// 	}
// 	else if ((is_hex(flags, 1, 1) || is_ptr(flags)) && nb.abs != 0 && !nb.sign)
// 	{
// 		if (!(flags->pound_f || is_ptr(flags)))
// 			return ;
// 		if (is_hex(flags, 1, 0) || is_ptr(flags))
// 			putstr_cc("0x", count);
// 		else if (is_hex(flags, 0, 1))
// 			putstr_cc("0X", count);
// 	}
// }

// For numbers, of course... You niggas should improve this.
int	print_prefix(t_nbr *nbr, t_meta *m)
{
	if (nbr->sign == 1 && nbr->magn < radix)
		ft_putchar_cc('-', m);
	else if (nbr->magn < radix && flag(CV_PTR, m))
		ft_putstr_cc("0x", m);
	// ???

	// 
	return (1);
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
	if (flags->zero_f && !flags->prec_f && flags->field_f)

	if (flags->zero_f && !flags->prec_f && flags->field_f)
		print_prefix(nb, flags, count);
	// Add filler
	if (!flags->zero_f || (flags->zero_f && (flags->prec_f || (!nb.abs && is_ptr(flags)))))
		print_filler(NOZEROFILL, m);
	else if (flags->zero_f && !flags->prec_f)
		print_filler(ZEROFILL, m);
	// Add prefix
	if (!(flags->zero_f && !flags->prec_f && flags->field_f))
		print_prefix(nb, flags, count);
	ft_putstr(magn, m);


	// Add filler
	if (flags->dash_f && flags->field_v > 0)
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
