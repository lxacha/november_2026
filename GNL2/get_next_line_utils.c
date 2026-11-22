/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefebv@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 19:28:02 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/21 19:40:42 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

