/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/11 18:22:11 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	process_character_specifier(t_meta *meta)
{
	int	c;

	if (is_type(meta, CV_CHR))
		c = va_arg(meta->args, int);
	if (is_type(meta, CV_PRC))
		c = '%';
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

	if (is_type(meta, CV_PTR))
		tmp.u = va_arg(meta->args, unsigned long);
	else if (is_type(meta, CV_INT))
		tmp.s = va_arg(meta->args, int);
	else if (is_type(meta, CV_UINT | CV_HEX))
		tmp.u = va_arg(meta->args, unsigned int);
	if (is_type(meta, CV_PTR | CV_UINT | CV_HEX))
		nbr = (t_nbr){.sign = 0, .magn = tmp.u};
	else if (is_type(meta, CV_INT) && tmp.s < 0)
		nbr = (t_nbr){.sign = 1, .magn = -tmp.s};
	else if (is_type(meta, CV_INT) && tmp.s >= 0)
		nbr = (t_nbr){.sign = 0, .magn = tmp.s};
	if (is_type(meta, CV_PTR | CV_HEXL))
		ft_putnbr_base_cc(&nbr, BASE16_LW, meta);
	else if (is_type(meta, CV_INT | CV_UINT))
		ft_putnbr_base_cc(&nbr, BASE10, meta);
	else if (is_type(meta, CV_PTR | CV_HEXU))
		ft_putnbr_base_cc(&nbr, BASE16_UP, meta);
	*meta->i += 1;
}

void	process_specifier(const char *c, t_meta *meta)
{
	meta->type = c;
	if (is_type(meta, CV_CHR | CV_PRC))
		process_character_specifier(meta);
	else if (is_type(meta, CV_STR))
		process_string_specifier(meta);
	else if (is_type(meta, CV_HEX | CV_INT | CV_PTR | CV_UINT))
		process_number_specifier(meta);
	else
		*meta->i += 1;
}
