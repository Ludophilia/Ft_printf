/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t06.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:54:47 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/05 17:55:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T06_H

# define T06_H

#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#ifndef DEBUG
# define DEBUG 0
#endif

#ifndef PRINTF
# define PRINTF printf
#endif

#ifndef PRINTF_STR
# define PRINTF_STR "printf"
#endif

#endif