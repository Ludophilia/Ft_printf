/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:50 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/11 14:36:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# define BASE10 "0123456789"
# define BASE16_LW "0123456789abcdef"
# define BASE16_UP "0123456789ABCDEF"

# define FLG_DASH (1 << 0)
# define FLG_ZERO (1 << 1)
# define FLG_PREC (1 << 2)

# define FLG_FIEL (1 << 3)

# define FLG_POUN (1 << 4)
# define FLG_SPAC (1 << 5)
# define FLG_PLUS (1 << 6)

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>

# include "../libs/libft/libft.h"

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
	const char		*type;
	unsigned char	flags;
	int				field_v;
	int				prec_v;
	va_list			args;
	int				*i;
	int				count;
}	t_meta;

int		ft_putchar_cc(const char c, t_meta *meta);
int		ft_putstr_cc(const char *str, t_meta *meta);
int		ft_putnbr_base_cc(t_nbr *nbr, char *digits, t_meta *meta);

void	process_specifier(const char *c, t_meta *meta);

int		is_valid_specif(const char *spec, t_meta *meta);

int		ft_printf(const char *format, ...);

#endif
