/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t05p01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:35:45 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/13 13:52:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t05.h"

int	test_format_str_with_ptr_specifier_return_value_t0(void)
{
	int		ret;
	char	*format;

	format = "%p";
	ret = PRINTF(format, NULL);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t1(void)
{
	int			ret;
	char		*format;

	format = "%p";
	ret = PRINTF(format, (void *)0xf);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t2(void)
{
	int			ret;
	char		*format;

	format = "%p";
	ret = PRINTF(format, (void *)0x10);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t3(void)
{
	int			ret;
	char		*format;

	format = "%p%p%p%p";
	ret = PRINTF(format, (void *)0x1, NULL, -1, -16);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	test_format_str_with_ptr_specifier_return_value_t4(void)
{
	int			ret;
	char		*format;

	format = "Whyarethose... %pointing%pthings%pthat%pimportant%p!";
	ret = PRINTF(format, (void *)0x12345678, NULL,
			(void *)0x345789, (void *)0x222222b, (void *)0xdef12347d);
	if (DEBUG
		&& dprintf(2, DBG_PF_NAME"(\"%s\", ...) -> %i\n", format, ret))
		;
	return (1);
}

int	main(void)
{
	if (test_format_str_with_ptr_specifier_return_value_t0()
		&& test_format_str_with_ptr_specifier_return_value_t1()
		&& test_format_str_with_ptr_specifier_return_value_t2()
		&& test_format_str_with_ptr_specifier_return_value_t3()
		&& test_format_str_with_ptr_specifier_return_value_t4())
		return (0);
	return (1);
}
