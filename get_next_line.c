// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/08 11:28:44 by rrask             #+#    #+#             */
// /*   Updated: 2023/03/03 18:36:32 by rrask            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"
// #include <stdio.h>
// #include <string.h>

// char *update_stash(char *stash)
// {
// 	char *remainder;
// 	int i;

// 	i = 0; 
// 	remainder = ft_strdup(stash);
// 	while (remainder[i])
// 	{
// 		if (remainder[i] == '\n')
// 		{
// 			i++;
// 			stash = ft_strdup(&remainder[i]);
// 			free(remainder);
// 			return(stash);
// 		}
// 		i++;
// 	}
// 	return (stash);
// }

// char	*remain_get(char *read_line, char *stash)
// {
// 	int i;

// 	i = 0;
// 	read_line = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	while (stash[i])
// 	{
// 		if (stash[i] == '\n')
// 			return(read_line);
// 		read_line[i] = stash[i];
// 		i++;	
// 	}
// 	return (read_line);
// }

// char	*read_it(char *stash, int fd)
// {
// 	char *buf;
// 	char *line;
// 	int i;
// 	int read_bytes;

// 	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	line = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	read_bytes = read(fd, buf, BUFFER_SIZE);
	
// 	while (read_bytes || (!read_bytes && stash)) //As long as there is something to read
// 	{
// 		buf = ft_strjoin(stash, buf);
// 		i = 0;
// 		while (buf[i])
// 		{
// 			if (buf[i] == '\n') 
// 			{
// 				line = ft_strjoin(line, buf);
// 				free(buf);
// 				return(line);
// 			}
// 			i++;
// 		}
// 		line = ft_strjoin(line, buf);
// 		read_bytes = read(fd, buf, BUFFER_SIZE);
// 	}
// 	return(line);
// }

// char	*get_next_line(fd)
// {
// 	static char	*stash;
// 	char		*read_line;
	
// 	read_line = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	if (!read_line)
// 		return (NULL);
// 	if (!stash)
// 		stash = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	stash = read_it(stash, fd);
// 	read_line =  remain_get(read_line, stash);
// 	stash = update_stash(stash); //use the length of stash to find the index on where to start from buf in read_it
// 	return (read_line);
// }

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *read_it(char *stash, int fd)
{
	char *buf;
	int read_bytes;

	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	read_bytes = read(fd, buf, BUFFER_SIZE);
	while (1)
	{
		
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (buf);
}

char *get_next_line(int fd)
{
	static char *stash;
	char *read_line;

	if (!stash)
		stash = ft_calloc(BUFFER_SIZE, sizeof(char));
	stash = read_it(stash, fd);
	return (stash);
}