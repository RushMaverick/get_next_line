/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:28:44 by rrask             #+#    #+#             */
/*   Updated: 2023/02/23 18:56:42 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// char *handle_newline(char *oneline, char *stash, int fd)
// {
// 	int i;
// 	int stash_index;
// 	int readbytes;
// 	char *handled_line;

// 	i = 0;
// 	readbytes = read(fd, oneline, BUFFER_SIZE);
// 	if (!readbytes)
// 		return(NULL);
// 	oneline = ft_strjoin(stash, oneline);
// 	handled_line = ft_calloc(ft_strlen(oneline) + 1, sizeof(char));
		//Count to \n and then ft_calloc correct size
// 	while (oneline[i])
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

char *handle_newline(char *read_line, int fd)
{
	char *handled_line;
	int index;
	
	index = 0;
	handled_line = ft_calloc(ft_strlen(read_line) + 1, sizeof(char));
	while (read_line[index])
	{
		if (read_line[index] == '\n')
			break;
		handled_line[index] = read_line[index];
		index++;
	}
	return (handled_line);	
}

char	*read_it(char *stash, int fd)
{
	char	*read_line;
	int		readbytes;
	int		stashindex;
	int		lineindex;

	read_line = ft_calloc(BUFFER_SIZE, sizeof(char));
	readbytes = read(fd, read_line, BUFFER_SIZE);
	if (!readbytes)
		return (NULL);
	while (1)
	{
		stashindex = 0;
		if (stash)
		{
			stash = handle_newline(read_line, fd);
			return (stash);
		}
		stash[stashindex] = read_line[lineindex];
		stashindex++;
		lineindex++; 
	}
	return (NULL);
}

char	*get_next_line(fd)
{
	static char	*stash;
	char		*oneline;
	int			readbytes;

	oneline = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!oneline)
		return (NULL);
	if (!stash)
	{
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	}
	oneline = read_it(stash, fd);
	return (oneline);
}
