/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:53:34 by jegerman          #+#    #+#             */
/*   Updated: 2024/12/19 13:33:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	flags(unsigned int flags, t_meta *meta)
{
	return ((meta->flags & (flags)) == (flags));
}

int	not_flags(unsigned int flags, t_meta *meta)
{
	return ((meta->flags & (flags)) == 0);
}

int	flag(unsigned int flags, t_meta *meta)
{
	return (meta->flags & (flags));
}

int	not_flag(unsigned int flags, t_meta *meta)
{
	return (!(meta->flags & (flags)));
}
