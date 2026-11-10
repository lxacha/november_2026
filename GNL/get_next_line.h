/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:37:43 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/07 23:04:50 by leolefeb         ###   ########.fr       */
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

typedef struct s_list
{
    char    *buf_read;
    struct s_list *next;
}       t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
void	polish_list(t_list **list);
void	copy_str(t_list *list, char *str);
size_t	len_to_newline(t_list *list);
char	*get_line(t_list *lst);
int	found_newline(t_list *list);
void	append(t_list **list, char *buf);
void	create_list(t_list **list, int fd);
char	*get_next_line(int fd);
t_list	*find_last_node(t_list *lst);

#endif