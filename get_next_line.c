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

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *update_stash(char *read_line)
{
	char *remainder;
	int i;

	i = 0; 
	remainder = ft_strdup(read_line);
	while (remainder[i])
	{
		if (remainder[i] == '\n')
		{
			i++;
			read_line = ft_strdup(&remainder[i]);
			free(remainder);
			return(read_line);
		}
		i++;
	}
	return (read_line);
}

char	*get_it(char *stash)
{
	int i;
	char *read_line;

	i = 0;
	read_line = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			read_line[i] = stash[i];
			i++;
			return(read_line);
		}
		read_line[i] = stash[i];
		i++;	
	}
	return (read_line);
}

// -g -fsanitize=address

char	*read_it(char *stash, int fd)
{
	char *buf;
	char *line;
	int i;
	int read_bytes;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_bytes = read(fd, buf, BUFFER_SIZE);
	
	while (read_bytes || (!read_bytes && stash))
	{
		buf = ft_strjoin(stash, buf);
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n') 
			{
				line = ft_strjoin(line, buf);
				free(buf);
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
	
	read_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_line)
		return (NULL);
	if (!stash)
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_line = read_it(stash, fd);
	stash = update_stash(read_line); 
	read_line = get_it(read_line);
	return (read_line);
}

// #include "get_next_line.h"
// #include <stdio.h>
// #include <string.h>

// char *get_remainder(char *stash, char *buf)
// {
// 	int i;

// 	i = 0;
// 	while (buf[i])
// 	{
// 		if (buf[i] == '\n')
// 		{
// 			i++;
// 			stash = ft_strdup(&buf[i]);
// 			return(stash);
// 		}
// 		i++;
// 	}
// 	return (stash);
// }

// char *read_it(char *stash, int fd)
// {
// 	char *buf;
// 	char *line;
// 	int read_bytes;
// 	int i;

// 	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	line = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	read_bytes = read(fd, buf, BUFFER_SIZE);
// 	if (stash)
// 		buf = ft_strjoin(stash, buf);
// 	i = 0;
// 	while (read_bytes > 0 || stash)
// 	{
// 		while(buf[i])
// 		{
// 			if (buf[i] == '\n')
// 			{
// 				//Check if there is anything left in buf after newline and store it in stash. then return line
// 				free(buf);
// 				return(line);
// 			}
// 			line[i] = buf[i];
// 			i++;
// 		}
// 		read_bytes = read(fd, buf, BUFFER_SIZE);
// 	}
// 	return (line);
// }

// char *get_next_line(int fd)
// {
// 	static char *stash;
// 	char *read_line;

// 	if (!fd)
// 		return (NULL);
// 	read_line = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	if (!read_line)
// 		return (NULL);
// 	if (!stash)
// 		stash = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	stash = read_it(stash, fd);
// 	// read_line = get_it(stash);
// 	// stash = update_stash(stash);
// 	return (stash);
// }