/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:33:43 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/18 14:35:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	set_number(t_nbr *nbr, t_meta *m)
{
	t_usl	tmp;

	if (flag(CV_PTR, m))
		tmp.u = va_arg(m->args, unsigned long);
	else if (flag(CV_INT, m))
		tmp.s = va_arg(m->args, int);
	else if (flag(CV_UINT | CV_HEX, m))
		tmp.u = va_arg(m->args, unsigned int);
	if (flag(CV_PTR | CV_HEXL, m))
		*nbr = (t_nbr){.sign = 0, .magn = tmp.u, .base = BASE16_LW};
	else if (flag(CV_HEXU, m))
		*nbr = (t_nbr){.sign = 0, .magn = tmp.u, .base = BASE16_UP};
	else if (flag(CV_UINT, m))
		*nbr = (t_nbr){.sign = 0, .magn = tmp.u, .base = BASE10};
	else if (flag(CV_INT, m) && tmp.s < 0)
		*nbr = (t_nbr){.sign = 1, .magn = -tmp.s, .base = BASE10};
	else if (flag(CV_INT, m) && tmp.s >= 0)
		*nbr = (t_nbr){.sign = 0, .magn = tmp.s, .base = BASE10};
}

static size_t	get_magnitude_len(t_nbr *nbr, t_meta *m)
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

char	*set_magnitude_buffer(t_nbr *nbr, t_meta *m)
{
	char 			*buffer;
	int				i;
	size_t			mgn_len;

	set_number(&nbr, m);
	mgn_len = get_magnitude_len(nbr, m);
	buffer = ft_calloc(mgn_len + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	if (flag(FL_PREC, m) && m->prec_v > nbr->magn_len)
	{
		m->prec_v -= nbr->magn_len;
		while (m->prec_v-- > 0)
			buffer[i++] = '0';
	}
	buffer_nbr_base(nbr, buffer, &i, m);
	return (buffer);
}
