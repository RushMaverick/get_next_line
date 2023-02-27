/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:28:44 by rrask             #+#    #+#             */
/*   Updated: 2023/02/27 11:10:48 by rrask            ###   ########.fr       */
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

char	*read_it(char *stash, int fd)
{
	int read_bytes;
	int index;
	int rl_index;
	char *read_line = NULL;
	char *temp_line = NULL;
	
	read_line = ft_calloc(BUFFER_SIZE, sizeof(char));
	temp_line = ft_calloc(BUFFER_SIZE, sizeof(char));
	read_bytes = read(fd, stash, BUFFER_SIZE);
	rl_index = 0;
	while (read_bytes) 
	{
		index = 0;
		if (rl_index < 0)
			ft_strjoin(read_line, stash);
		while (stash[index])
		{
			if (stash[index] == '\n')
			{
				return (read_line);	
			}
			read_line[rl_index] = stash[index];
			index++;
			rl_index++;
		}
		read_bytes = read(fd, stash, BUFFER_SIZE);
	}
	return (stash);
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
	stash = read_it(stash, fd);
	return (stash);
}
