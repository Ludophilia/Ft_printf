/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:33:43 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/15 18:01:12 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// You should measure the number and add precision, which is the room for more 
// zeroes in case the magn_len is not enough. nb_zeros = precision - magn_len 
size_t	get_magnitude_len(t_nbr *nbr, t_meta *m)
{
	size_t			magn_len;
	size_t			radix;
	unsigned long	magn;

	magn_len = 0;
	if (nbr->magn == 0)
		magn_len = 1;
	radix = ft_strlen(nbr->base);
	magn = nbr->magn;
	while (magn && ++magn_len)
		magn /= radix;
	nbr->magn_len = magn_len;
	if (flag(FL_PREC, m) && m->prec_v > magn_len)
		magn_len += (m->prec_v - magn_len);
	return (magn_len);
}

// void	buffer_precision(t_nbr *nbr, t_meta *m)
// {

// }

char	*init_magnitude_buffer(t_nbr *nbr, t_meta *m)
{
	char 			*buffer;
	int				i;
	size_t			mgn_len;

	mgn_len = get_magnitude_len(nbr, m);
	buffer = ft_calloc(mgn_len + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	// write precision
	i = 0;
	if (flag(FL_PREC, m) && m->prec_v > nbr->magn_len)
	{
		m->prec_v -= nbr->magn_len; // Good idea?
		while (m->prec_v--)
			buffer[i++] = '0';
	}
	// write magnitude
	
	return (buffer);
}

{
	//	
}

// Here, you write what 
int	buffer_char(const char c, char )
{

}

void	buffer_magnitude(t_nbr *nbr, t_meta *m)

int	ft_putnbr_base_cc(t_nbr *nbr, t_meta *meta)
{
	size_t	radix;
	t_nbr	*tmp;

	if (flag(CV_PTR, meta) && nbr->magn == 0 && ft_putstr_cc("(nil)", meta))
		return (1);
	radix = ft_strlen(nbr->base);
	tmp = &(t_nbr){.magn = nbr->magn / radix, .sign = nbr->sign,
		.base = nbr->base};
	if (nbr->magn >= radix)
		ft_putnbr_base_cc(tmp, meta);

	// Move somewhere else
	// if (nbr->sign == 1 && nbr->magn < radix)
	// 	ft_putchar_cc('-', meta);
	// else if (nbr->magn < radix && flag(CV_PTR, meta))
	// 	ft_putstr_cc("0x", meta);

	// Replace with a function that writes into a buffer
	ft_putchar_cc(digits[nbr->magn % radix], meta); // buffer char
	return (1);
}
