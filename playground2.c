#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 20

char *handle_newline(char *oneline, char *stash);
char *get_oneline(char *oneline, char *stash, int fd);

char *get_it(fd)
{
	static char *stash;
	char *oneline;

	stash = calloc(BUFFER_SIZE + 1, sizeof(char));
	oneline = calloc(BUFFER_SIZE + 1, sizeof(char));
	oneline = get_oneline(oneline, stash, fd);
	return (oneline);
}

char *get_oneline(char *oneline, char *stash, int fd)
{
	int readbytes;

	readbytes = read(fd, oneline, BUFFER_SIZE);
	oneline = handle_newline(oneline, stash);
	return (oneline);
}
//Winner Winner\nChicken Dinner

char *handle_newline(char *oneline, char *stash)
{
	int i;
	char *handled_line;

	i = 0;
	handled_line = calloc(strlen(oneline) + 1, sizeof(char));
	while (oneline[i])
	{
		if (oneline[i] == '\n' || oneline[i] == '\0')
		{
			i++;
			while (oneline[i])
			{
				stash[i] = oneline[i];
				i++;
				// store_remainder(stash, oneline, i);//Static variable can somehow be used to store where you are at all times.
			}
			return(handled_line);
		}
		handled_line[i] = oneline[i];
		i++;
	}
	return (oneline);
}

int	main(void)
{
	char	*huh;
	int		fd;
	int		i;

	i = 2;
	fd = open("moi.txt", O_RDONLY);
	while (i)
	{
		huh = get_it(fd);
		i--;
		printf("%s\n", huh);
	}
	return (0);
}