/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:49:43 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/06 21:35:00 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h> // oi mate, can ya remove that 'hit real fast
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	process_specifier(char *format, va_list *args);

#endif