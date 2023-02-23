/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:01:01 by rrask             #+#    #+#             */
/*   Updated: 2023/02/23 11:44:03 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *handle_newline(char *oneline, char *stash)
{
	int i;
	int stash_index;
	char *handled_line;

	i = 0;
	handled_line = ft_calloc(strlen(oneline) + 1, sizeof(char)); //Count to \n and then ft_calloc correct size
	while (oneline[i])
	{
		stash_index = 0;
		if (oneline[i] == '\n')
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
		return((char *)temp);
	else
	{
		joined = ft_calloc(ft_strlen(stash) + ft_strlen(temp) + 1, sizeof(char));//change to ft_strlen and ft_calloc
	}
	if (!joined)
		return (NULL);
	istheres(joined, stash, temp);
	return (joined);
}

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

	dup = malloc((sizeof(char) * ft_strlen(s1) + 1)); //change to ft_strlen
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

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	mult;

	if (count == 0 || size == 0)
		return (NULL);
	mult = count * size;
	if (mult / count != size)
		return (NULL);
	ptr = malloc(mult);
	if (!ptr)
		return (0);
	ft_bzero(ptr, mult);
	return (ptr);
}