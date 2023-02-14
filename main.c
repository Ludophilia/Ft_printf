/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:43:04 by jgermany          #+#    #+#             */
/*   Updated: 2023/02/14 20:22:00 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	main(void)
{
	// printf("SHINJUKU I love you! *** motherfuckers!!\n");

	// printf("%c\n", 0x41);
	// printf("%c\n", "a");

	// printf("je souis '%s'\n", "travail");

	printf("%i, %d\n", -22, -22);
	printf("%i, %d\n", 0x16, 0x16);
	printf("%i, %d\n", -026, -026);
	printf("%i, %d\n", 07.7, 07.7);

	// printf("%u, %d\n", -22, -22);
	// printf("%u, %d\n\n", 22, 22);
	// printf("%u, %d\n", -07, -07);
	// printf("%u, %d\n\n", 07, 07);

	// int	*mf = malloc(1 * sizeof(int));
	// printf("%p\n", mf);
	// free(mf);
	// printf("%x, %X\n", -0xab2F, -0xab2F);
	// printf("%x, %X\n\n", 0xab2F, 0xab2F);
	return (0);
}