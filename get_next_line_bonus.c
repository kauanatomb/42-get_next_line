/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:20:41 by ktombola          #+#    #+#             */
/*   Updated: 2025/05/06 16:21:04 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_stash(int fd, char *stash);
static char	*extract_line(char *stash);
static char	*clear_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
	{
		if (stash[fd])
			free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = fill_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clear_stash(stash[fd]);
	return (line);
}

static char	*fill_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;
	char	*tmp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return ((free(stash)), NULL);
	while (i > j)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*clear_stash(char *stash)
{
	int		i;
	int		remainder_len;
	int		j;
	char	*new_stash;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	remainder_len = ft_strlen(stash + ++i);
	new_stash = (char *)malloc(remainder_len + 1);
	if (!new_stash)
		return ((free(stash)), NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
