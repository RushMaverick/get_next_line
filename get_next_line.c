/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:15:51 by rrask             #+#    #+#             */
/*   Updated: 2023/03/08 13:28:20 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*update_stash(char *read_line) // REMOVE STRDUP, cpy by indexes to remainder
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read_line[i] != '\n')
		i++;
	if (read_line[i] == '\n')
		i++;
	remainder = ft_calloc(ft_strlen(read_line) -i + 1, sizeof(char));
	if (!remainder)
		return (NULL);
	while (read_line[i])
	{
		remainder[j] = read_line[i];
		i++;
		j++;
	}
	return (remainder);
	// return (remainder);
	// {
	// 	if (remainder[i] == '\n')
	// 	{
	// 		i++;
	// 		read_line = ft_strdup(&remainder[i]);
	// 		return (read_line);
	// 	}
	// 	i++;
	// }
	// return (read_line);
}

char	*get_it(char *read_line)
{
	int		index;
	char	*line;
	unsigned int	len;

	index = 0;
	len = ft_strlen(read_line);
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (read_line[index] && read_line[index] != '\n')
	{
		line[index] = read_line[index];
		index++;
	}
	if (read_line[index] == '\n')
	{
		line[index] = read_line[index];
		index++;	
	}
	free(read_line);
	return (line);
	// while (read_line[index])
	// 	index++;
	// line = ft_calloc(index + 1, sizeof(char));
	// if (!line)
	// 	return (NULL);
	// index = 0;
	// while (read_line[index])
	// {
	// 	if (read_line[index] == '\n')
	// 	{
	// 		line[index] = read_line[index];
	// 		if(read_line)
	// 			free(read_line);
	// 		return (line);
	// 	}
	// 	line[index] = read_line[index];
	// 	index++;
	// }
	// if (read_line)
	// 	free(read_line);
	// return (line);
}

static int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*read_it(char *stash, int fd)
{
	char	*buf;
	int		read_bytes;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return(NULL);
	read_bytes = 1;
	while (!check_new_line(buf) && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		buf[read_bytes] = '\0';
		buf = ft_strjoinfree(stash, buf);
	}
	if (!read_bytes) //Check if sus
	{
		free(buf);
		return (stash);	
	}
	return (buf);
}
	// buf = joined;
	// while (read_bytes > 0)
	// {
	// 	i = 0;
	// 	while (buf[i])
	// 	{
	// 		if (buf[i] == '\n')
	// 		{
	// 			temp = ft_strjoinfree(line, buf);
	// 			line = temp;
	// 			return (line);
	// 		}
	// 		i++;
	// 	}
	// 	temp = ft_strjoinfree(line, buf);
	// 	line = temp;
	// 	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// 	read_bytes = read(fd, buf, BUFFER_SIZE);
	// }
	// if(buf)
	// 	free(buf);
	// return (line);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*read_line;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!stash)
		return (NULL);
	read_line = read_it(stash, fd); // readline here is actually the buf THE WHOLE THING
	// if (fd > 0)
	// {
	if (check_new_line(read_line))
		stash = update_stash(read_line); // HERE WE TAKE THE WHOLE THING AND CHOP AFTER \n
	read_line = get_it(read_line); // LAST THING IS WE GET EVERYTHING UNTIL \n TO PRINT IN THE TERMINAL
	// }
	return (read_line);
}
