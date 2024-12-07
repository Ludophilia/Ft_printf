/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/07 13:28:02 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_character_specifier(t_meta *meta)
{
	int	c;

	c = va_arg(meta->args, int);
	ft_putchar_cc(c, meta);
	*meta->i += 2;
}

static void	process_string_specifier(t_meta *meta)
{
	char	*str;

	if (*meta->type == 's')
		str = va_arg(meta->args, char *);
	else if (*meta->type == '%')
		str = (char [1]){'%'};
	if (*meta->type == 's' && str == NULL)
		str = "(null)";
	ft_putstr_cc(str, meta);
	*meta->i += 2;
}

static void	process_number_specifier(t_meta *meta)
{
	t_usl			tmp;
	t_nbr			nbr;

	if (*meta->type == 'p')
		tmp.u = va_arg(meta->args, unsigned long);
	else if (*meta->type == 'd' || *meta->type == 'i')
		tmp.s = va_arg(meta->args, int);
	else if (*meta->type == 'u' || *meta->type == 'x' || *meta->type == 'X')
		tmp.u = va_arg(meta->args, unsigned int);
	if (*meta->type == 'p' || *meta->type == 'u')
		nbr = (t_nbr){.sign = 0, .magn = tmp.u};
	else if ((*meta->type == 'd' || *meta->type == 'i') && tmp.s < 0)
		nbr = (t_nbr){.sign = 1, .magn = -tmp.s};
	else if ((*meta->type == 'd' || *meta->type == 'i') && tmp.s >= 0)
		nbr = (t_nbr){.sign = 0, .magn = tmp.s};
	if (*meta->type == 'p' || *meta->type == 'x')
		ft_putnbr_base_cc(&nbr, BASE16_LW, meta);
	else if (*meta->type == 'd' || *meta->type == 'i' || *meta->type == 'u')
		ft_putnbr_base_cc(&nbr, BASE10, meta);
	else if (*meta->type == 'X')
		ft_putnbr_base_cc(&nbr, BASE16_UP, meta);
	*meta->i += 2;
}

void	process_specifier(const char *c, t_meta *meta)
{
	meta->type = c;
	if (*meta->type == 'c')
		process_character_specifier(meta);
	else if (*meta->type == 's' || *meta->type == '%')
		process_string_specifier(meta);
	else if (*meta->type == 'p' || *meta->type == 'i' || *meta->type == 'd')
		process_number_specifier(meta);
}
