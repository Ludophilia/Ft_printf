/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:58:49 by jgermany          #+#    #+#             */
/*   Updated: 2023/02/28 23:12:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	ft_printf("Ça marche frère.\n");
}

// Now we have to compile this main.
	// * ft_printf have to be compiled first as libftprintf.a and used as a lib
	// with this main
	// * libftprintf.a have to be compiled with libft.a
	// * libft.a have to be compiled from its sources. 
	// ...
