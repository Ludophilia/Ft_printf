/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:18:20 by jgermany          #+#    #+#             */
/*   Updated: 2024/12/14 17:45:45 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	write_char(char c, t_list **head)
{
	t_list	*curr_node;
	t_list	*new_node;
	size_t	len;

	curr_node = ft_lstlast(*head);
	len = ft_strlen((char *)(curr_node->content));
	if (len == BUFFER_SIZE)
	{
		new_node = writer_init_node(c);
		if (!new_node)
		{
			errno = ENOMEM;
			return ;
		}
		ft_lstadd_back(head, new_node);
	}
	else
		((char *)(curr_node->content))[len] = c;
}

void	write_precision(t_flag *flags, t_list **head)
{
	t_list	*prec_node;

	// Build a new node for precision only and add 0 before
	prec_node = writer_init_node(0);
	if (!prec_node)
	{
		errno = ENOMEM;
		return ;
	}
	flags->prec_v -= writer_cont_len(head);
	while (flags->prec_v-- > 0)
		write_char('0', &prec_node);

	// Add 0 before
	ft_lstlast(prec_node)->next = *head;
	*head = prec_node;
}

static void	write_str(char *s, t_list **head)
{
	int	i;

	i = -1;
	while (s[++i])
		write_char(s[i], head);
}

void	write_nbr_base(t_nbr nb, char *base, t_flag *flags, t_list **head)
{
	unsigned long	radix;

	if (nb.abs == 0 && flags->conv_t == 'p')
		write_str("(nil)", head);
	else if (nb.abs == 0 && flags->prec_f && !flags->prec_v)
		return ;
	else
	{
		radix = ft_strlen(base);
		if (nb.abs >= radix)
			write_nbr_base((t_nbr){nb.sign, nb.abs / radix}, base, flags, head);
		write_char(base[nb.abs % radix], head);
	}
}
