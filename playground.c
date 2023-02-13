#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER 100

char *split_it(char *temp, char *buf);

char *get_it(int fd)
{
	static char *buf;
	char *temp;
	temp = malloc(sizeof(char) * BUFFER + 1);
	read(fd, temp, BUFFER);
	temp[BUFFER] = '\0';
	split_it(temp, buf);
	return (buf);
}

char *split_it(char *temp, char *buf)
{
	int i; 

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			buf = "I have no words.";
			return (buf);
		}
		i++;
	}
	return(buf);
}

int main (void)
{
	char *huh;
	int fd = open("moi.txt", O_APPEND);
	huh = get_it(fd);
	printf("%s", huh);
	return(0);
}
