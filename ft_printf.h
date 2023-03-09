/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:49:43 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/09 21:54:31 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h> // oi mate, can ya remove that 'hit real fast
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		process_specifier(char *format, va_list *args);
void	ll_putnbr_fd(long long int nb, int fd);
void	ll_putnbr_base_fd(long long int nb, char *base, int fd);

#endif