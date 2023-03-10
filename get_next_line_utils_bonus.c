/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:52:09 by rrask             #+#    #+#             */
/*   Updated: 2023/03/10 13:49:43 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	istheres(char *joined, char const *s1, char const *s2)
{
	int		i;
	int		j;

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

char	*ft_strjoinfree(char const *buf, char const *read_buf)
{
	char	*joined;

	joined = ft_calloc(ft_strlen(buf) + ft_strlen(read_buf) + 1, sizeof(char));
	if (!joined)
		return (NULL);
	istheres(joined, buf, read_buf);
	free((void *)buf);
	return (&*joined);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)str)[i++] = '\0';
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
