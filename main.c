/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:43:04 by jgermany          #+#    #+#             */
/*   Updated: 2023/02/13 22:03:21 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// printf("SHINJUKU I love you! *** motherfuckers!!\n");
	// int	mf;
	
	// mf = 1;
	printf("%u, %d\n", -22, -22);
	printf("%u, %d\n\n", 22, 22);
	printf("%u, %d\n", -0xF, -0xF);
	printf("%u, %d\n\n", 0xF, 0xF);
	printf("%u, %d\n", -07, -07);
	printf("%u, %d\n\n", 07, 07);
	return (0);
}