/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:53:06 by kochniak          #+#    #+#             */
/*   Updated: 2025/10/31 14:42:23 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_to_container(int fd, char *container)
{
	char	*buf;
	int		n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	while (n > 0 && (!container || !ft_strchr(container, '\n')))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n > 0)
		{
			buf[n] = '\0';
			container = ft_strjoin(container, buf);
		}
	}
	free(buf);
	if (n < 0)
	{
		if (container)
			free(container);
		return (NULL);
	}
	return (container);
}

char	*extract_line(char *container)
{
	int		i;
	char	*line;

	if (!container || !container[0])
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, container, i + 1);
	return (line);
}

char	*update(char *container)
{
	char	*p;
	char	*new;

	p = ft_strchr(container, '\n');
	if (!p)
	{
		free(container);
		return (NULL);
	}
	new = ft_strdup(p + 1);
	free(container);
	if (!new || !new[0])
	{
		if (new)
			free(new);
		return (NULL);
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*container[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	container[fd] = write_to_container(fd, container[fd]);
	if (!container[fd])
		return (NULL);
	line = extract_line(container[fd]);
	container[fd] = update(container[fd]);
	return (line);
}
