/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:41:20 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/07 23:03:56 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	len;
	len = 0;
	if (!str)
		return NULL;
	while(str[len])
		len++;
	return len;
}