/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:50 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/04 17:29:32 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define BASE10 "0123456789"
# define BASE16_LW "0123456789abcdef"
# define BASE16_UP "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# include "libft/libft.h"

typedef struct s_nbr
{
	int				sign;
	unsigned long	magn;
}	t_nbr;

typedef struct s_meta
{
	const char	*type;
	va_list		args;
	int			*i;
	int			*count;
}	t_meta;

void	ft_putchar_cc(const char c, int *count);
void	ft_putstr_cc(const char *str, int *count);
void	ft_putnbr_base_cc(t_nbr *nbr, char *digits, int *count);

void	process_specifier(const char *c, t_meta *meta);

int		ft_printf(const char *format, ...);

#endif
