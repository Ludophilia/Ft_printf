/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:49:43 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/10 13:32:35 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <errno.h>
# include <stdint.h>
# include <stdbool.h>

# include "../libs/libft/includes/libft.h"

# define BUFFER_SIZE 20

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
	bool			space_f: 1;
	bool			plus_f: 1;
	bool			pound_f: 1;
	bool			dash_f: 1;
	bool			zero_f: 1;
	bool			field_f: 1;
	bool			prec_f: 1;
	int				field_v;
	int				prec_v;
}	t_flag;

t_list	*writer_init_node(char c);
size_t	writer_cont_len(t_list **head);
size_t	writer_print_list(t_list **head, int *count);
void	write_precision(t_flag *flags, t_list **head);
void	write_nbr_base(t_nbr nb, char *base, t_flag *flags, t_list **head);

bool	is_int(t_flag *flags);
bool	is_hex(t_flag *flags, bool lowercase, bool uppercase);
bool	is_ptr(t_flag *flags);
bool	is_str(t_flag *flags);
bool	is_chr(t_flag *flags, bool is_percent);
void	putchar_cc(char c, int *count);
void	putstr_cc(char *s, int *count);
void	print_prefix(t_nbr nb, t_flag *flags, int *count);
void	print_filler(t_flag *flags, bool zfill, int *count);
void	print_nbr_filler(t_nbr nb, t_flag *flags, bool before, int *count);
void	print_char(char c, t_flag *flags, int *count);
void	print_str(char *str, t_flag *flags, int *count);
void	print_nbr(t_nbr nb, char *base, t_flag *flags, int *count);

bool	is_valid_flg(char c);
bool	is_valid_type(char c);
void	proc_char_conv(char *spec, va_list *args, t_flag *flags, int *count);
void	proc_nbr_conv(char *spec, va_list *args, t_flag *flags, int *count);
int		process_format(const char *format, va_list *args, int *count);

int		ft_printf(const char *format, ...);

#endif