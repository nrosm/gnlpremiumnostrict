/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-10 12:06:11 by nroson-m          #+#    #+#             */
/*   Updated: 2024-10-10 12:06:11 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

char	*ft_handle_read_error(char *temp_buffer, char *lines)
{
	free(temp_buffer);
	if (lines)
	{
		free(lines);
		lines = NULL;
	}
	return (NULL);
}

char	*ft_readlines(int fd, char *lines)
{
	char	*temp_buffer;
	int		read_bytes;

	read_bytes = 1;
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	while ((!lines || !ft_strchr(lines, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_handle_read_error(temp_buffer, lines));
		temp_buffer[read_bytes] = '\0';
		lines = ft_strjoin(lines, temp_buffer);
		if (!lines)
			return (ft_handle_read_error(temp_buffer, NULL));
	}
	free(temp_buffer);
	return (lines);
}

char	*get_next_line(int fd)
{
	static char	*lines = NULL;
	char		*returned_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = ft_readlines(fd, lines);
	if (!lines)
		return (NULL);
	returned_line = get_actual_line(lines);
	lines = ft_afterlines(lines);
	if (!lines || *lines == '\0')
	{
		free(lines);
		lines = NULL;
	}
	return (returned_line);
}
