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

void	polish_list(t_list **list)
{
	t_list *last_node;
	t_list *clean_node;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL|| clean_node == NULL)
		return ;
	last_node = find_last_node(*list);

	i = 0;
	k = 0;
	while(last_node->str_buf[i] != '\0'
		&& last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] != '\0'
		&& last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->nex = NULL;
	dealloc(lsit, clean_node, buf);
}

void	copy_str(t_list *list, char *str)
{
	size_t		i;
	size_t		k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

size_t	len_to_newline(t_list *list)
{
	size_t i;
	size_t len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
					len++;
					return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

char	*get_line(t_list *lst)
{
	size_t		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	nex_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

//len_to_newline v counts chars till newline
//copy_str v

size_t	found_newline(t_list *lst)
{
	size_t	index;

	if (!lst)
		return (NULL);
	while(lst->content[index] != '\0')
	{
		if (lst->content[index] == '\n')
			return (1);
		index++;
	}
	return (NULL); 
}

t_list	*find_last_node(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	append(t_list **list, char *buf)
{
	t_list *new_node;
	t_list *last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;

	new_node->str_buf = buf;
	new_node->next = NULL;
}

//find_last_node v

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while(!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

//create_list v
//append v
//found newline v

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

//create_list v
//get_line v
//polish_list v

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