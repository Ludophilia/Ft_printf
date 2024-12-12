/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/12 16:26:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


// void	print_filler(bool zfill, t_meta *meta)
// {
// 	while (meta->field_v-- > 0)
// 		ft_putchar_cc((char [2]){' ', '0'}[zfill], meta);
// }

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

	if (meta->flags & CV_PTR)
		tmp.u = va_arg(meta->args, unsigned long);
	else if (meta->flags & CV_INT)
		tmp.s = va_arg(meta->args, int);
	else if (meta->flags & (CV_UINT | CV_HEX))
		tmp.u = va_arg(meta->args, unsigned int);
	if (meta->flags & (CV_PTR | CV_UINT | CV_HEX))
		nbr = (t_nbr){.sign = 0, .magn = tmp.u};
	else if ((meta->flags & CV_INT) && tmp.s < 0)
		nbr = (t_nbr){.sign = 1, .magn = -tmp.s};
	else if ((meta->flags & CV_INT) && tmp.s >= 0)
		nbr = (t_nbr){.sign = 0, .magn = tmp.s};
	if (meta->flags & (CV_PTR | CV_HEXL))
		ft_putnbr_base_cc(&nbr, BASE16_LW, meta);
	else if (meta->flags & (CV_INT | CV_UINT))
		ft_putnbr_base_cc(&nbr, BASE10, meta);
	else if (meta->flags & CV_HEXU)
		ft_putnbr_base_cc(&nbr, BASE16_UP, meta);
	*meta->i += 1;
}

void	process_specifier(const char *c, t_meta *meta)
{
	set_type(c, meta);
	if (meta->flags & (CV_CHR | CV_PRC))
		process_character_specifier(meta);
	else if (meta->flags & CV_STR)
		process_string_specifier(meta);
	else if (meta->flags & (CV_HEX | CV_INT | CV_PTR | CV_UINT))
		process_number_specifier(meta);
	else
		*meta->i += 1;
}
