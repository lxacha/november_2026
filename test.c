/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:57:39 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/06 18:14:12 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	test_read(int	file_to_read)
{
	size_t	iter;
	char	buf[20000];

	iter = 0;
	if (!file_to_read)
		return ;
	read(file_to_read, buf, 200);
	
	printf("\n%s", buf);
}

int		main(int argc, char **argv)
{
	if (argv[1])
	{
		int fd = open(argv[1], O_RDONLY);	
		test_read(fd);
	}
}