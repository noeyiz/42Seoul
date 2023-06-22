/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:14:37 by jikoo             #+#    #+#             */
/*   Updated: 2023/05/31 16:50:55 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char **backup, char *buffer)
{
	char	*line;

	line = NULL;
	if (ft_strlen(*backup))
		line = ft_strldup(*backup, 0, ft_strlen(*backup));
	free(*backup);
	*backup = NULL;
	free(buffer);
	buffer = NULL;
	return (line);
}

static char	*ft_get_line_nl(char **backup, char *buffer, int idx)
{
	char	*line;
	char	*temp;

	line = ft_strldup(*backup, 0, idx + 1);
	temp = ft_strldup(*backup, idx + 1, ft_strlen(*backup) - idx - 1);
	free(*backup);
	*backup = temp;
	free(buffer);
	buffer = NULL;
	return (line);
}

static char	*ft_read_text(int fd, char **backup, char *buffer)
{
	int		idx;
	int		read_size;
	char	*temp;

	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		if (read_size == 0)
			break ;
		buffer[read_size] = '\0';
		temp = ft_strjoin(*backup, buffer);
		free(*backup);
		*backup = temp;
		idx = ft_find_nextline(*backup);
		if (idx != -1)
			return (ft_get_line_nl(backup, buffer, idx));
	}
	return (ft_get_line(backup, buffer));
}

char	*get_next_line(int fd)
{
	int			idx;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (backup)
		{
			free(backup);
			backup = NULL;
		}
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!backup)
		backup = ft_strldup("", 0, 0);
	idx = ft_find_nextline(backup);
	if (idx != -1)
		return (ft_get_line_nl(&backup, buffer, idx));
	return (ft_read_text(fd, &backup, buffer));
}
