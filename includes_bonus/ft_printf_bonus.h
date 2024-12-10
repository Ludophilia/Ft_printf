/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:50 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/10 11:56:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

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

typedef union u_usl
{
	unsigned long	u;
	long			s;
}	t_usl;

typedef struct s_meta
{
	const char	*type;
	va_list		args;
	int			*i;
	int			count;
}	t_meta;

int		ft_putchar_cc(const char c, t_meta *meta);
int		ft_putstr_cc(const char *str, t_meta *meta);
int		ft_putnbr_base_cc(t_nbr *nbr, char *digits, t_meta *meta);

void	process_specifier(const char *c, t_meta *meta);

int		ft_printf(const char *format, ...);

#endif
