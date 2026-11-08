#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

void phrasing(char *buf_actual)
// remove whats after /n

void store(char *buf_stored, char *buf_actual, size_t n_index)
//store buf actual in buf_stored starting from n until /0

void concat_store_actual(char *buf_actual, char *stored)
//concat store in actual clear store

size_t get_back_n(char *buf_actual)
//return -1 if no n, returns n position if n


char	*get_next_line(int fd)
{
	char	*buf_actual;
	char	*buf_stored;
	
	read(fd, buf_actual, 10);
	if (buf_stored && !buf_actual)
		return (buf_stored);
	if (buf_stored)
		concat_store_actual(buf_actual , buf_stored);
	if(buf_actual)
	{
		if(get_back_n(buf_actual) >= 0)
		{
			if(buf_actual[get_back_n(buf_actual)+1] != '/0')
				store(buf_stored, buf_actual , get_back_n(buf_actual));
			phrasing(char *buf_actual);
			return (buf_actual);
		}
		else
			store(buf_stored, buf_actual , 0)
	}
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