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
#define BUFFER_SIZE 10

#include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);

#endif