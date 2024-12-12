/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/12 17:59:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"



static void	process_character_specifier(t_meta *meta)
{
	int	c;

	// Add width and left alignment management
	if (meta->flags & CV_CHR)
		c = va_arg(meta->args, int);
	if (meta->flags & CV_PRC)
		c = '%';

	// if ((meta->flags & FLG_FIEL) && is_type(meta, CV_CHR))
	// 	meta->field_v--;

	// if ((meta->flags & (FLG_DASH | FLG_FIEL)) == FLG_FIEL
	// 	&& is_type(meta, CV_CHR))
	// 	print_filler(false, meta);

	ft_putchar_cc(c, meta);

	*meta->i += 1;
}

static void	process_string_specifier(t_meta *meta)
{
	char	*str;

	str = va_arg(meta->args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_cc(str, meta);
	*meta->i += 1;
}

static void	process_number_specifier(t_meta *meta)
{
	t_usl			tmp;
	t_nbr			nbr;

	if (has_flag(CV_PTR, meta))
		tmp.u = va_arg(meta->args, unsigned long);
	else if (has_flag(CV_INT, meta))
		tmp.s = va_arg(meta->args, int);
	else if (has_flag(CV_UINT | CV_HEX, meta))
		tmp.u = va_arg(meta->args, unsigned int);
	if (has_flag(CV_PTR | CV_UINT | CV_HEX, meta))
		nbr = (t_nbr){.sign = 0, .magn = tmp.u};
	else if (has_flag(CV_INT, meta) && tmp.s < 0)
		nbr = (t_nbr){.sign = 1, .magn = -tmp.s};
	else if (has_flag(CV_INT, meta) && tmp.s >= 0)
		nbr = (t_nbr){.sign = 0, .magn = tmp.s};
	if (has_flag(CV_PTR | CV_HEXL, meta))
		ft_putnbr_base_cc(&nbr, BASE16_LW, meta);
	else if (has_flag(CV_INT | CV_UINT, meta))
		ft_putnbr_base_cc(&nbr, BASE10, meta);
	else if (has_flag(CV_HEXU, meta))
		ft_putnbr_base_cc(&nbr, BASE16_UP, meta);
	*meta->i += 1;
}
void	process_specifier(const char *c, t_meta *meta)
{
	set_type(c, meta);
	if (has_flag(CV_CHR | CV_PRC, meta))
		process_character_specifier(meta);
	else if (has_flag(CV_STR, meta))
		process_string_specifier(meta);
	else if (has_flag(CV_HEX | CV_INT | CV_PTR | CV_UINT, meta))
		process_number_specifier(meta);
	else
		*meta->i += 1;
}
