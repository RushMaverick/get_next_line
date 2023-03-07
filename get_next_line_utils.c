/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:01:01 by rrask             #+#    #+#             */
/*   Updated: 2023/03/07 14:32:16 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *line, char const *buf)
{
	char	*joined;

	if (!buf)
		return ((char *)line);
	if (!line)
		return((char *)buf);
	else
	{
		joined = ft_calloc(ft_strlen(line) + ft_strlen(buf) + 1, sizeof(char));//change to ft_strlen and ft_calloc
	}
	if (!joined)
		return (NULL);
	istheres(joined, line, buf);
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

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
	ft_memset(ptr, 0, mult);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc((sizeof(char) * ft_strlen(s1) + 1));
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
