/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:11:36 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/04 18:08:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_character_specifier(t_meta *meta)
{
	int	c;

	c = va_arg(meta->args, int);
	ft_putchar_cc(c, meta->count);
	*meta->i += 2;
}

static void	process_string_specifier(t_meta *meta)
{
	char	*str;

	str = va_arg(meta->args, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_cc(str, meta->count);
	*meta->i += 2;
}

// %i %d ; %u ; %X ; %x missing
// int				tmp_s;
static void	process_number_specifier(t_meta *meta)
{
	unsigned long	tmp_u;
	t_nbr			nbr;

	if (*meta->type != 'p')
		return ;
	tmp_u = va_arg(meta->args, unsigned long);
	nbr = (t_nbr){.sign = 0, .magn = tmp_u};
	if (*meta->type == 'p' && tmp_u == 0)
	{
		ft_putstr_cc("(nil)", meta->count);
		*meta->i += 2;
		return ;
	}
	ft_putstr_cc("0x", meta->count);
	ft_putnbr_base_cc(&nbr, BASE16_LW, meta->count);
	*meta->i += 2;
}

void	process_specifier(const char *c, t_meta *meta)
{
	meta->type = c;
	if (*meta->type == 'c')
		process_character_specifier(meta);
	else if (*meta->type == 's')
		process_string_specifier(meta);
	else if (*meta->type == 'p')
		process_number_specifier(meta);
}
