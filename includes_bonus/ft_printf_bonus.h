/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:58:50 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/11 18:16:35 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# define BASE10 "0123456789"
# define BASE16_LW "0123456789abcdef"
# define BASE16_UP "0123456789ABCDEF"

# define FLG_DASH 0b1
# define FLG_ZERO 0b10
# define FLG_PREC 0b100
# define FLG_FIEL 0b1000
# define FLG_POUN 0b10000
# define FLG_SPAC 0b100000
# define FLG_PLUS 0b1000000

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

typedef enum e_type
{
	CV_INT = 0b1,
	CV_HEX = 0b10,
	CV_HEXL = 0b100,
	CV_HEXU = 0b1000,
	CV_UINT = 0b10000,
	CV_PTR = 0b100000,
	CV_STR = 0b1000000,
	CV_CHR = 0b10000000,
	CV_PRC = 0b100000000
}	t_type;

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

bool	is_type(t_meta *meta, enum e_type type);

void	process_specifier(const char *c, t_meta *meta);

int		is_valid_specif(const char *spec, t_meta *meta);

int		ft_printf(const char *format, ...);

#endif
