#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER 10

char *insert_it(int fd, char *temp, char *buf);

char *get_it(int fd)
{
	static char *buf;
	char *temp;
	temp = malloc(sizeof(char) * BUFFER + 1);
	insert_it(fd, temp, buf);
	return (temp);
}

char *insert_it(int fd, char *temp, char *buf)
{
	read(fd, temp, BUFFER);
	return(buf);
}

int main (void)
{
	char *huh;
	int fd = open("moi.txt", O_APPEND);
	huh = get_it(fd);
	printf("%s", huh);
	huh = get_it(fd);
	printf("%s", huh);
	huh = get_it(fd);
	printf("%s", huh);
	return(0);
}
