/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/05 16:17:46 by jegerman         ###   ########.fr       */
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

	str = va_arg(meta->args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_cc(str, meta);
	*meta->i += 2;
}

// %u ; %X ; %x missing
static void	process_number_specifier(t_meta *meta)
{
	t_usl			tmp;
	t_nbr			nbr;

	if (*meta->type == 'p')
		tmp.u = va_arg(meta->args, unsigned long);
	else if (*meta->type == 'd' || *meta->type == 'i')
		tmp.s = va_arg(meta->args, int);

	if (*meta->type == 'p')
		nbr = (t_nbr){.sign = 0, .magn = tmp.u};
	else if ((*meta->type == 'd' || *meta->type == 'i') && tmp.s < 0)
		nbr = (t_nbr){.sign = 1, .magn = -tmp.s};
	else if ((*meta->type == 'd' || *meta->type == 'i') && tmp.s >= 0)
		nbr = (t_nbr){.sign = 0, .magn = tmp.s};

	if (*meta->type == 'p')
		ft_putnbr_base_cc(&nbr, BASE16_LW, meta);
	else if (*meta->type == 'd' || *meta->type == 'i')
		ft_putnbr_base_cc(&nbr, BASE10, meta);

	*meta->i += 2;
}

void	process_specifier(const char *c, t_meta *meta)
{
	meta->type = c;
	if (*meta->type == 'c')
		process_character_specifier(meta);
	else if (*meta->type == 's')
		process_string_specifier(meta);
	else if (*meta->type == 'p' || *meta->type == 'i' || *meta->type == 'd')
		process_number_specifier(meta);
}
