#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 20

char *handle_newline(char *oneline, char *stash);
char *get_oneline(char *oneline, char *stash, int fd);

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc((sizeof(char) * strlen(s1) + 1)); //change to ft_strlen
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	istheres(char *joined, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		joined[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[j] = s2[i];
		i++;
		j++;
	}
	joined[j] = '\0';
}

char	*ft_strjoin(char const *stash, char const *temp)
{
	char	*joined;

	if (!temp)
		return ((char *)stash);
	if (!stash)
		return(ft_strdup(temp));
	else
	{
		joined = calloc(strlen(stash) + strlen(temp) + 1, sizeof(char));//change to ft_strlen and ft_calloc
	}
	if (!joined)
		return (NULL);
	istheres(joined, stash, temp);
	return (joined);
}

char *get_it(fd)
{
	static char *stash;
	char *oneline;

	if (!stash)
	{
		stash = calloc(BUFFER_SIZE + 1, sizeof(char));	
	}
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
	int stash_index;
	char *handled_line;

	i = 0;
	handled_line = calloc(strlen(oneline) + 1, sizeof(char)); //Count to \n and then calloc correct size
	while (oneline[i])
	{
		stash_index = 0;
		if (oneline[i] == '\n' || oneline[i] == '\0')
		{
			i++;
			while (oneline[i])
			{
				stash[stash_index] = oneline[i];
				i++;
				stash_index++;
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

	fd = open("moi.txt", O_RDONLY);
	printf("%s\n", get_it(fd));
	printf("%s\n", get_it(fd));

	return (0);
}