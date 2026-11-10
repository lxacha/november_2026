/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:41:20 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/08 17:41:40 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	len;
	len = 0;
	if (!str)
		return (0);
	while(str[len])
		len++;
	return len;
}

t_list	*find_last_node(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	found_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf_read[i] && i < BUFFER_SIZE)
		{
			if (list->buf_read[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}