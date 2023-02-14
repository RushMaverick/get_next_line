#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER 20

char	*insert_it(int fd, char *temp, char *stash);

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

char	*get_it(int fd)
{
	static char	*stash;
	char		*temp;

	temp = calloc(BUFFER + 1, sizeof(char)); // remove this
	insert_it(fd, temp, stash);
	return (stash);
}

char	*insert_it(int fd, char *temp, char *stash)
{
	int	i;
	int readbytes = 1;

	i = 0;
	while (readbytes)
	{
		//Check libft for function that checks for a certain character, like null terminator or newline
		readbytes = read(fd, temp, BUFFER);
		printf("%d\n", readbytes);
		printf("|%s|\n", temp);
	}

	return (stash);
}

int	main(void)
{
	char	*huh;
	int		fd;

	fd = open("moi.txt", O_APPEND);
	huh = get_it(fd);
	// printf("%s", huh);
	return (0);
}
