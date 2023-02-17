#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER 20

char *insert_it(int fd, char *temp, char *stash);
char *handle_newline(char *temp, char *stash);

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bcpy;

	bcpy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bcpy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

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

char	*get_it(int fd)
{
	static char	*stash; // consider using static char for storing the read stuff and strjoin the temp to stash
	char		*newline;
	char		*temp;

	temp = calloc(BUFFER + 1, sizeof(char)); // remove this
	stash = calloc(BUFFER + 1, sizeof(char)); // remove this
	newline = insert_it(fd, temp, stash);
	return (newline);
}

char *handle_newline(char *temp, char *stash)
{
	int i;
	char *newline;

	i = 0;
	newline = calloc(strlen(temp) + 1, sizeof(char));//change to ft_strlen and ft_calloc

//	Winner Winner\nChic\nken Di\nnner

	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			i++;
			while (temp[i] != '\n' || temp[i] != '\0')
			{
				stash[i] = temp[i]; //not allocated memory
			}
		}
		newline[i] = temp[i];
		i++;
	}
	return (newline);
}

char *insert_it(int fd, char *temp, char *stash)
{
	int readbytes;
	char *newline;

	readbytes = 1;
	while (readbytes)
	{
		ft_memset(temp, 0, strlen(temp)); //change to ft_strlen
		readbytes = read(fd, temp, BUFFER);
		newline = handle_newline(temp, stash); //This might have to be handled after the loop. 
		stash = ft_strjoin(stash, temp);
	}
	free(temp);
	//Check libft for function that checks for a certain character,like null terminator or newline
	return (newline);
}

int	main(void)
{
	char	*huh;
	int		fd;
	int		i;

	i = 1;
	fd = open("moi.txt", O_RDONLY);
	while (i)
	{
		huh = get_it(fd);
		i--;
		printf("%s\n", huh);
	}
	return (0);
}
