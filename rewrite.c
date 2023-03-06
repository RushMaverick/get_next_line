#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *read_it(char *stash, int fd)
{
	char *buf;
	int read_bytes;

	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	read_bytes = read(fd, buf, BUFFER_SIZE);
	while (read_bytes || stash)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (buf);
}

char *get_next_line(int fd)
{
	static char *stash;
	char *read_line;

	if (!stash)
		stash = ft_calloc(BUFFER_SIZE, sizeof(char));
	stash = read_it(stash, fd);
	return (stash);
}