#include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char *get_it(int fd);
char *func2(int fd, char *stash);
char *func3(char *str);

char *get_it(fd)
{
	static char *str;

	str = func2(fd, str);
	return (str);
}

char *func2(int fd, char *stash)
{
	char *readline;

	readline = calloc(strlen(stash), 5);

	
	while (1)
	{
		read(fd, readline, 5);
		stash = func3(readline);
	}
	return (readline);
}

char *func3(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == 'B')
			return (str);
		index--;
	}
	return (NULL);
}

int main (void)
{
	char *str;
	int fd;

	fd = open("moi.txt", O_RDONLY);
	str = get_it(fd);
	printf("%s\n", str);

	return (0);
}