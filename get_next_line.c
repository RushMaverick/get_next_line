/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:28:44 by rrask             #+#    #+#             */
/*   Updated: 2023/02/22 14:24:08 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(fd)
{
	static char *stash;
	char *oneline;
	int readbytes;

	oneline = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!stash)
	{
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));	
	}
	readbytes = read(fd, oneline, BUFFER_SIZE);
	oneline = ft_strjoin(stash, oneline);
	oneline = handle_newline(oneline, stash);

	return (oneline);
}
