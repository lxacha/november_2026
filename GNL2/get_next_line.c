/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefebv@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:42:46 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/21 21:16:15 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append_to_node(t_list **list, char *buf)
{
	t_list *new_node;

	// got to declare node before append content
	new_node = malloc(sizeof(t_list));	
	if (new_node == NULL)
		return ;
	new_node->buf_read = ft_strdup(buf);
	*list = new_node;	
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	static t_list *list = NULL; 

	read(fd, buf, BUFFER_SIZE);
	append_to_node(&list, buf);
	printf("%s \n", (list)->buf_read);

	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argv[1])
	{
		int fd = open(argv[1], O_RDONLY);
		get_next_line(fd);
	}
	else 
		return (0);
}
