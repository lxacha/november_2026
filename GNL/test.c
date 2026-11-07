/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:57:39 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/08 00:30:59 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

// void	test_read(int	file_to_read)
// {
// 	size_t	iter;
// 	size_t	been_read;
// 	char	buf_cont_str[150];

// 	memset(buf_cont_str, 'a' , 149);
// 	iter = 0;
// 	been_read = 0;
	
// 	if (!file_to_read)
// 		return ;
// 	while (buf_cont_str[iter] != '\n')
// 	{
// 		been_read += read(file_to_read, buf_cont_str, iter);
// 		if (strchr(buf_cont_str , '\n') != NULL)
// 		{
// 			read(file_to_read, buf_cont_str , been_read);
// 			break ;
// 		}
// 		iter ++;
// 	}
	
// 	printf("\n%s", buf_cont_str);
// }

size_t	contain_n_0(char *actual_read)
{
	size_t	index_n;

	index_n = 0;
	while (actual_read[index_n] != '\n' && actual_read[index_n] != '\0')
	{	
		index_n++;
		
	}		
	return (index_n);
}

int	phrase_append(char *str_cuted,char *actual_read)
{
	size_t	end;
	size_t	start;
	size_t	index_of_act_read;
	char	*temp;
	
	index_of_act_read = 0;
	start = ft_strlen(str_cuted);
	end = find_back_n(actual_read);	
	temp = malloc((start + end) * sizeof(char));
	//if  \n is found return (1);
	while(index_of_act_read <= end)

	
		
	//if \n is not found return (0);
}

char	*get_next_line(int fd);
{
	static char actual_read[BUFFER_SIZE];
	static char *str_cuted;
	
	if (!fd)
		return NULL;
	while(contain_n_0(actual_read) )
	{
		read(fd, actual_read, BUFFER_SIZE);
		phrase_append(str_cuted , actual_read);
	}
	return (str_cuted);
}

int		main(int argc, char **argv)
{
	char	*to_read = "whatever.txt";	
	if (argv[1])
	{
		int fd = open(argv[1], O_RDONLY);	
		get_next_line(fd);
	}
	else
	{
		int fd = open(to_read, O_RDONLY);
		get_next_line(fd);
		get_next_line(fd);
	}
	
}