/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:49:43 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 13:31:59 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <stdint.h>

# include "../libs/libft/includes/libft.h"

# define B10 "0123456789"
# define B16U "0123456789ABCDEF"
# define B16L "0123456789abcdef"

typedef struct s_nbr
{
	bool			sign: 1;
	unsigned long	abs;
}	t_nbr;

typedef struct s_flag
{
	unsigned char	conv_t: 7;
}	t_flag;

void	print_char(char c, int *count);
void	print_str(char *str, int *count);
void	print_nbr(t_nbr nb, char *base, t_flag *flags, int *count);

int		process_format(const char *format, va_list *args, int *count);

int		ft_printf(const char *format, ...);

#endif