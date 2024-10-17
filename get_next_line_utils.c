/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-10 12:06:13 by nroson-m          #+#    #+#             */
/*   Updated: 2024-10-10 12:06:13 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*get_actual_line(char *lines)
{
	int		len;
	char	*newlines;

	len = 0;
	if (!lines[len])
		return (NULL);
	while (lines[len] && lines[len] != '\n')
		len++;
	newlines = (char *)malloc((len + 2) * sizeof(char));
	if (!newlines)
		return (NULL);
	len = 0;
	while (lines[len] && lines[len] != '\n')
	{
		newlines[len] = lines[len];
		len++;
	}
	if (lines[len] == '\n')
	{
		newlines[len] = lines[len];
		len++;
	}
	newlines[len] = '\0';
	return (newlines);
}

char	*ft_afterlines(char *lines)
{
	int		i;
	int		j;
	char	*newlines;

	i = 0;
	j = 0;
	while (lines[i] && lines[i] != '\n')
		i++;
	if (!lines[i])
	{
		free(lines);
		return (NULL);
	}
	newlines = (char *)malloc((sizeof(char)) * (ft_strlen(lines) - i + 1));
	if (!newlines)
		return (NULL);
	i = i + 1;
	while (lines[i])
		newlines[j++] = lines[i++];
	newlines[j] = '\0';
	free(lines);
	return (newlines);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
