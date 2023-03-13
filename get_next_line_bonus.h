/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:51:11 by rrask             #+#    #+#             */
/*   Updated: 2023/03/12 19:17:37 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_it(char *buf, int fd);
char	*update_stash(char *read_line);
char	*get_it(char *read_line);
int		ft_strchr(const char *s, int c);
char	*ft_strjoinfree(char const *line, char const *buf);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
