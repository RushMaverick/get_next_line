#include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

// char *get_it(int fd);
// char *func2(int fd, char *stash);
// char *func3(char *str);

// char *get_it(fd)
// {
// 	static char *str;

// 	str = func2(fd, str);
// 	return (str);
// }

// char *func2(int fd, char *stash)
// {
// 	char *readline;

// 	readline = calloc(strlen(stash), 5);

	
// 	while (1)
// 	{
// 		read(fd, readline, 5);
// 		stash = func3(readline);
// 	}
// 	return (readline);
// }

// char *func3(char *str)
// {
// 	int index;

// 	index = 0;
// 	while (str[index])
// 	{
// 		if (str[index] == 'B')
// 			return (str);
// 		index--;
// 	}
// 	return (NULL);
// }

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] != (unsigned char)c)
		return (NULL);
	return ((char *)&s[i]);
}

int main (void)
{
	char *str;
	char *s;
	int fd;

	fd = 'I';
	s = "HelloIs this on?";
	str = ft_strchr(s, fd);
	printf("%s\n", str);

	return (0);
}

char  *get_next_line(int fd)
{
	int reading;
	int i;
	char *buffer;
	char character;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 100000);
	while ((reading = read(fd, &character, 1)) > 0)
	{
		buffer[i] = character;
		if (character == '\n')
			break ;
	}
	if (reading <= 0 || i == 0 )
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer)
}