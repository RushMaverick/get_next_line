#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER 20

char *insert_it(int fd, char *temp, char *stash);

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;
// 	size_t	mult;

// 	if (count == 0 || size == 0)
// 		return (ft_calloc(1, 1));
// 	mult = count * size;
// 	if (mult / count != size)
// 		return (NULL);
// 	ptr = malloc(mult);
// 	if (!ptr)
// 		return (0);
// 	ft_bzero(ptr, mult);
// 	return (ptr);
// }

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
		joined = calloc(strlen(stash) + strlen(temp) + 1, sizeof(char));//change to ft_strlen
	}
	if (!joined)
		return (NULL);
	istheres(joined, stash, temp);
	return (joined);
}

char	*get_it(int fd)
{
	static char	*stash;
	char		*temp;

	temp = calloc(BUFFER + 1, sizeof(char)); // remove this
	stash = insert_it(fd, temp, stash);
	return (stash);
}

char *insert_it(int fd, char *temp, char *stash)
{
	int readbytes;

	readbytes = 1;
	while (readbytes)
	{
		ft_memset(temp, 0, strlen(temp)); //change to ft_strlen
		readbytes = read(fd, temp, BUFFER);
		stash = ft_strjoin(stash, temp);
	}
	//Check libft for function that checks for a certain character,like null terminator or newline
	return (stash);
}

int	main(void)
{
	char	*huh;
	int		fd;

	fd = open("moi.txt", O_RDONLY);
	huh = get_it(fd);
	printf("!%s!\n", huh);
	return (0);
}
