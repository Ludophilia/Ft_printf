/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t05p00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 14:51:53 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t05.h"

int	test_format_str_with_ptr_specifier_return_value_t0(void)
{
	int			ret[2];
	char		*format;

	format = "%p\n";
	ret[0] = printf(format, NULL);
	ret[1] = ft_printf(format, NULL);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t1(void)
{
	int			ret[2];
	char		*format;

	format = "%p\n";
	ret[0] = printf(format, (void *)0xf);
	ret[1] = ft_printf(format, (void *)0xf);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t2(void)
{
	int			ret[2];
	char		*format;

	format = "%p";
	ret[0] = printf(format, (void *)0x10);
	ret[1] = ft_printf(format, (void *)0x10);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t3(void)
{
	int			ret[2];
	char		*format;

	format = "%p%p%p%p";
	ret[0] = printf(format, (void *)0x1, NULL, -1, -16);
	ret[1] = ft_printf(format, (void *)0x1, NULL, -1, -16);
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t4(void)
{
	int			ret[2];
	char		*format;

	format = "Whyarethose... %pointing%pthings%pthat%pimportant%p!";
	ret[0] = printf(format, "c", NULL,
			"\001\x80\x7f franchement", "   \n", "");
	ret[1] = ft_printf(format, "c", NULL,
			"\001\x80\x7f franchement", "   \n", "");
	if (DEBUG
		&& dprintf(2, "printf(\"%s\", ...) -> %i\n", format, ret[0])
		&& dprintf(2, "ft_printf(\"%s\", ...) -> %i\n", format, ret[1]))
		;
	assert(ret[0] == ret[1]);
	return (1);
}

int	main(void)
{
	test_format_str_with_ptr_specifier_return_value_t0();
	test_format_str_with_ptr_specifier_return_value_t1();
	test_format_str_with_ptr_specifier_return_value_t2();
	test_format_str_with_ptr_specifier_return_value_t3();
	test_format_str_with_ptr_specifier_return_value_t4();
	return (0);
}
