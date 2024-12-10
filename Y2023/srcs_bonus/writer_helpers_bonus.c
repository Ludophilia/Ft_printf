/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_helpers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:48:16 by jgermany          #+#    #+#             */
/*   Updated: 2024/01/05 15:59:04 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_list	*writer_init_node(char c)
{
	t_list	*node;
	char	*content;

	content = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!content)
		return (0);
	if (c)
		*content = c;
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (0);
	}
	return (node);
}

size_t	writer_cont_len(t_list **head)
{
	size_t	len;
	t_list	*node;

	len = 0;
	node = *head;
	while (node)
	{
		len += ft_strlen((char *)node->content);
		node = node->next;
	}
	return (len);
}

size_t	writer_print_list(t_list **head, int *count)
{
	t_list	*curr_node;
	size_t	size;

	curr_node = *head;
	size = 0;
	while (curr_node)
	{
		size += ft_strlen((char *)(curr_node->content));
		putstr_cc((char *)(curr_node->content), count);
		curr_node = curr_node->next;
	}
	return (size);
}
