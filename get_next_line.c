/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:28:44 by rrask             #+#    #+#             */
/*   Updated: 2023/02/28 17:48:05 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

// char *handle_newline(char *oneline, char *stash, int fd)
// {
// 	int i;
// 	int stash_index;
// 	int readbytes;
// 	char *handled_line;

// 	i = 0;
// 	;
// 	if (!readbytes)
// 		return(NULL);
// 	oneline = ft_strjoin(stash, oneline);
// 	handled_line = ft_calloc(ft_strlen(oneline) + 1, sizeof(char));
		//Count to \n and then ft_calloc correct size
// 	while ((readbytes = read(fd, oneline, BUFFER_SIZE) > 0)
// 	{
// 		stash_index = 0;
// 		if (oneline[i] == '\n')
// 		{
// 			i++;
// 			while (oneline[i])
// 			{
// 				stash[stash_index] = oneline[i];
// 				i++;
// 				stash_index++;
// 			}
// 			return(handled_line);
// 		}
// 		handled_line[i] = oneline[i];
// 		i++;
// 	}
// 	return (oneline);
// }

// char	*read_it(char *stash, int fd)
// {
// 	int read_bytes;
// 	int index;
// 	int rl_index;
// 	char *buf;
// 	char *remains;

// 	buf = malloc(sizeof(char) * BUFFER_SIZE);
// 	read_bytes = read(fd, stash, BUFFER_SIZE);
// 	rl_index = 0;
// 	while (read_bytes)
// 	{
// 		index = 0;
// 		while (stash[index])
// 		{
// 			if (stash[index] == '\n')
// 			{
// 				remains = ft_strjoin(remains, stash);
// 				return (buf);	
// 			}
// 			buf[rl_index] = stash[index];
// 			index++;
// 			rl_index++;
// 		}
// 		read_bytes = read(fd, stash, BUFFER_SIZE);
// 	}
// 	return (buf);
// }

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
		i = 0;
		while (line[i])
		{
			if (line[i] == '\n') // It falls apart here. Line should not have '\n' in the first place. stash and buf should also not have the newline inside
			{
				stash = ft_strchr(line, '\n');
				buf = ft_strjoin(stash, buf);
				return(line);
			}
			i++;
		}
		line = ft_strjoin(line, buf);
		// line = ft_strdup(buf);
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
	{
		stash = malloc(sizeof(char) * BUFFER_SIZE);
	}
	read_line = read_it(stash, fd);
	return (read_line);
}
