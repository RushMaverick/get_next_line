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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;

	if (!s2)
		return ((char *)s1);
	if (!s1)
		return((char *)s2);
	else
		joined = calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
	if (!joined)
		return (NULL);
	istheres(joined, s1, s2);
	return (joined);
}

char	*get_it(int fd)
{
	static char	*stash;
	char		*temp;
	int 		readbytes;

	readbytes = 1;
	temp = calloc(BUFFER + 1, sizeof(char)); // remove this
	stash = insert_it(fd, temp, stash);
	return (stash);
}

char *insert_it(int fd, char *temp, char *stash)
{
	// int i;
	int readbytes;

	// i = 0;
	readbytes = 1;
	while (readbytes)
	{
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

	fd = open("moi.txt", O_APPEND);
	huh = get_it(fd);
	printf("%s\n", huh);
	return (0);
}
