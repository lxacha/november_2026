/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefebv@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:50:35 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/23 00:13:11 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
#define GNL_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	char	*buf_read;
	struct s_list *next;
}	t_list;

// get_next_line.c
char	*get_next_line(int fd);
//void	append_to_node(t_list **list, char *buf);
// get_next_line_utils.c
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);

#endif
