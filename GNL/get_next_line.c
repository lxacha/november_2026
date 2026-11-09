/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:35:59 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/06 18:13:46 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while(!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list *list = NULL;
	char	*current_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &current_read, 0) < 0)
		return (NULL);	
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list)
	return (next_line);
}

int		main(int argc, char **argv)
{
	if (argv[1])
	{
		int fd = open(argv[1], O_RDONLY);	
		get_next_line(fd);
		get_next_line(fd);
	}
	else
	{
		char *text_file_name = "whatever.txt";
		int fd = open(text_file_name, O_RDONLY);
		get_next_line(fd);
		get_next_line(fd);
	}
}