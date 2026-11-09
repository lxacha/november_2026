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

typedef struct s_list
{
    char    *buf_read;
    struct s_list *next;
}       t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);

#endif