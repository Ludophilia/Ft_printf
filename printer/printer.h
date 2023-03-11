/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:53:57 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/11 14:50:30 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H

# define PRINTER_H

int		putchar_cctr(char c, int *ccount_p);
int		putstr_cctr(char *s, int *ccount_p);
int		putnbr_base_cctr(long long nb, char *base, int *ccount_p);

#endif