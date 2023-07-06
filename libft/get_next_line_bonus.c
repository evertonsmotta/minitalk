/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:43:38 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/12/20 19:20:16 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fd_free(char *temp_line, char *read_buf)
{
	char	*str;

	str = ft_strjoin_gnl(temp_line, read_buf);
	free(temp_line);
	temp_line = 0;
	return (str);
}

char	*fd_newline(char *temp_line)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	while (temp_line[i] && temp_line[i] != '\n')
		i++;
	if (!temp_line[i])
	{
		free(temp_line);
		temp_line = 0;
		return (NULL);
	}
	newline = ft_calloc((ft_strlen(temp_line) + 1), sizeof(char));
	i++;
	j = 0;
	while (temp_line[i])
		newline[j++] = temp_line[i++];
	free(temp_line);
	temp_line = 0;
	return (newline);
}

char	*fd_lastline(char *temp)
{
	char	*savedline;
	int		i;

	if (!*temp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	savedline = ft_calloc(i + 2, sizeof(char));
	i = -1;
	while (temp[++i] && temp[i] != '\n')
		savedline[i] = temp[i];
	if (temp[i] && temp[i] == '\n')
		savedline[i++] = '\n';
	return (savedline);
}

char	*fd_read(int fd, char *temp_line)
{
	char	*read_buf;
	int		byte;

	if (!temp_line)
		temp_line = ft_calloc(1, sizeof(char));
	read_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (byte > 0)
	{
		byte = read (fd, read_buf, BUFFER_SIZE);
		if (byte < 0)
		{
			free (read_buf);
			read_buf = 0;
			return (NULL);
		}
		read_buf[byte] = '\0';
		temp_line = fd_free(temp_line, read_buf);
		if (ft_strchr(read_buf, '\n') || ft_strchr(read_buf, EOF))
			break ;
	}
	free (read_buf);
	read_buf = 0;
	return (temp_line);
}

char	*get_next_line(int fd)
{
	static char	*temp_line[FOPEN_MAX];
	char		*read_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	temp_line[fd] = fd_read(fd, temp_line[fd]);
	if (!temp_line[fd])
		return (NULL);
	read_line = fd_lastline(temp_line[fd]);
	temp_line[fd] = fd_newline(temp_line[fd]);
	return (read_line);
}
