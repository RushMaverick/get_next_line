/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:28:44 by rrask             #+#    #+#             */
/*   Updated: 2023/03/01 14:33:14 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*remain_get(char *read_line, char *stash)
{
	int i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return(read_line);
		read_line[i] = stash[i];
		i++;	
	}
	return (read_line);
}

char	*read_it(char *stash, int fd)
{
	char *buf;
	char *line;
	int i;
	int read_bytes;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	
	while (read_bytes) //As long as there is something to read
	{
		buf = ft_strjoin(stash, buf);
		i = 0;
		while (buf[i])
		{
			//ft_strlcpy(char *dst, const char *src, size_t dstsize)
			if (buf[i] == '\n') // It falls apart here. Line should not have '\n' in the first place. stash and buf should also not have the newline inside
			{
				line = ft_strjoin(line, buf);
				return(line);
			}
			i++;
		}
		line = ft_strjoin(line, buf);
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	return(line);
}

char	*get_next_line(fd)
{
	static char	*stash;
	char		*read_line;
	int			readbytes;
	
	read_line = malloc(sizeof(char) * BUFFER_SIZE);
	if (!read_line)
		return (NULL);
	if (!stash)
		stash = malloc(sizeof(char) * BUFFER_SIZE);
	stash = read_it(stash, fd);
	read_line =  remain_get(read_line, stash);
	// stash = update_stash(stash); update stash to be what it needs to be for the next round
	return (read_line);
}
