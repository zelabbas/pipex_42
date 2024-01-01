/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:32:21 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/30 11:21:26 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	char	*help_get(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*buf_tmp;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		buf_tmp = backup;
		backup = ft_strjoin(buf_tmp, buf);
		free(buf_tmp);
		buf_tmp = NULL;
		if (!backup)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract_line(char *line)
{
	size_t		count;
	char		*backup;

	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	if (line[count] == '\0')
		return (NULL);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (!backup)
	{
		if (line)
			free(line);
		line = NULL;
		return (NULL);
	}
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (backup)
			free(backup);
		return (NULL);
	}
	line = help_get(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
	{
		if (backup)
			free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = extract_line(line);
	return (line);
}
