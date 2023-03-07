/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:15:51 by rrask             #+#    #+#             */
/*   Updated: 2023/03/07 14:36:15 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_stash(char *read_line)
{
	char	*remainder;
	int		i;

	i = 0;
	remainder = ft_strdup(read_line);
	while (remainder[i])
	{
		if (remainder[i] == '\n')
		{
			i++;
			read_line = ft_strdup(&remainder[i]);
			free(remainder);
			return (read_line);
		}
		i++;
	}
	return (read_line);
}

char	*get_it(char *stash)
{
	int		index;
	char	*read_line;

	index = 0;
	while (stash[index])
		index++;
	read_line = ft_calloc(index + 1, sizeof(char));
	if (!read_line)
		return (stash);
	index = 0;
	while (stash[index])
	{
		if (stash[index] == '\n')
		{
			read_line[index] = stash[index];
			free(stash);
			return (read_line);
		}
		read_line[index] = stash[index];
		index++;
	}
	free(stash);
	return (read_line);
}

char	*read_it(char *stash, int fd)
{
	char	*buf;
	char	*line;
	char	*temp;
	int		i;
	int		read_bytes;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_bytes = read(fd, buf, BUFFER_SIZE);
	if (!read_bytes)
	{
		free(line);
		free(buf);
		return (stash);
	}
	buf = ft_strjoin(stash, buf);
	free(stash);
	if (read_bytes == 0)
	{
		free(line);
		free(stash);
		return (buf);
	}
	while (read_bytes > 0)
	{
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				temp = ft_strjoin(line, buf);
				free(buf);
				free(line);
				line = temp;
				return (line);
			}
			i++;
		}
		temp = ft_strjoin(line, buf);
		free(line);
		free(buf);
		line = temp;
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*read_line;

	if (fd <= 0)
		return (NULL);
	read_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_line)
	{
		free(read_line);
		return (NULL);
	}
	if (!stash)
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_line = read_it(stash, fd);
	if (fd > 0)
	{
		stash = update_stash(read_line);
		read_line = get_it(read_line);
	}
	return (read_line);
}
