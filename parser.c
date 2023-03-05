/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:12:12 by jgermany          #+#    #+#             */
/*   Updated: 2023/03/04 14:32:52 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	process_specifier(char *format)
{
	// a function that will analyse the % * part
	// and do something with it...

	// starts from the first %
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == 'd' || format[i] == 'i')
			; // It's a decimal specifier
			// take the arg from the va_list
			// convert it maybe
			// print it via putnbr or something
	}
	// do the conversion from the va_list if necessary...
}