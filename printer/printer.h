/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:53:57 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/14 17:10:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H

# define PRINTER_H
# include "../parser/parser.h" // Circular reference? That's NOT good.

void		putchar_cctr(char c, int *ccount);
void		putstr_cctr(char *s, int *ccount);
void		putnbr_base_cctr(long long nb, char *base, int *ccount);
void		putnbr_base(long long nb, char *base, t_flag *flags, int *ccount);

#endif