/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/14 16:54:56 by jegerman         ###   ########.fr       */
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
		m->field_v--;
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
		m->field_v--;
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

// Move it
void	set_number(t_nbr *nbr, t_meta *m)
{
	t_usl	tmp;

	if (flag(CV_PTR, m))
		tmp.u = va_arg(m->args, unsigned long);
	else if (flag(CV_INT, m))
		tmp.s = va_arg(m->args, int);
	else if (flag(CV_UINT | CV_HEX, m))
		tmp.u = va_arg(m->args, unsigned int);
	if (flag(CV_PTR | CV_UINT | CV_HEX, m))
		*nbr = (t_nbr){.sign = 0, .magn = tmp.u};
	else if (flag(CV_INT, m) && tmp.s < 0)
		*nbr = (t_nbr){.sign = 1, .magn = -tmp.s};
	else if (flag(CV_INT, m) && tmp.s >= 0)
		*nbr = (t_nbr){.sign = 0, .magn = tmp.s};
}

static void	process_number_specifier(t_meta *m)
{
	t_nbr	nbr;

	set_number(&nbr, m);

	// field value
	// filler not zer0ofile if not '-'

	
	if (flag(CV_PTR | CV_HEXL, m))
		ft_putnbr_base_cc(&nbr, BASE16_LW, m);
	else if (flag(CV_INT | CV_UINT, m))
		ft_putnbr_base_cc(&nbr, BASE10, m);
	else if (flag(CV_HEXU, m))
		ft_putnbr_base_cc(&nbr, BASE16_UP, m);

	// filler not zer0ofile if '-'


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
