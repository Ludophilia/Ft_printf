/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:33:43 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/15 16:49:19 by jegerman         ###   ########.fr       */
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
	if (flag(FL_PREC, m) && m->prec_v > magn_len)
		magn_len += (m->prec_v - magn_len);
	return (magn_len);
}

char	*init_magnitude_buffer(t_nbr *nbr, t_meta *m)
{
	char 	*buffer;
	size_t	mgn_len;

	// How to get nbr_len
	mgn_len = get_magnitude_len(nbr, m);
	buffer = ft_calloc(mgn_len + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	
	// Do you want to know what's next? LET'S GO
	
	return (buffer)
}

// Here, you write precision

// Here, you write what 
int	buffer_char(const char c, char )
{

}