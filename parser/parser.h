/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:13:27 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/13 16:25:37 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# define BASE10 "0123456789"
# define BASE16U "0123456789ABCDEF"
# define BASE16L "0123456789abcdef"

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h> // REMOVE IT

typedef struct s_flag
{
	unsigned int	space_f: 1;
	unsigned int	plus_f: 1;
	unsigned int	pound_f: 1;
	unsigned int	dash_f: 1;
	unsigned int	zero_f: 1;
	unsigned int	field_v;
	unsigned int	prec_v;
}	t_flag;

int		proc_flags(char *spec, t_flag *flags);
int 	proc_options(char *spec, t_flag *flags);
int		proc_conv(char *spec, va_list *args, t_flag *flags, int *ccount);
int		proc_specif(char *spec, va_list *args, int *ccount);

#endif
