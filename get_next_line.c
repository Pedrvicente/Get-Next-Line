/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-al <pedde-al@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:50:39 by pedde-al          #+#    #+#             */
/*   Updated: 2025/12/02 16:27:19 by pedde-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stach(int fd, char *stach)
{
	char	*buffer;
	char	*tmp;
	int		bytes_read;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	bytes_read = 1;
	while (bytes_read > 0 && (!stach || !ft_strchr(stach, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return NULL;
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stach, buffer);
		free(stach);
		stach = tmp;
	}
	free (buffer);
	return (stach);
}

char	*extract_line(char *stach)
{
	char	*line;
	size_t	i;
	
	if (!stach || stach[0] == '\0')
		return NULL;
	i = 0;
	while(stach[i] && stach[i] != '\n')
		i++;
	if (stach[i] == '\n')
		line = ft_substr(stach, 0, i + 1);
	else
		line = ft_substr(stach, 0, i);
	return (line);
}

char	*update_stach(char *stach)
{
	size_t	i;
	char	*new_stach;

	i = 0;
	while(stach[i] && stach[i] != '\n')
		i++;
	if (stach[i] != '\n')
	{
		free(stach);
		return NULL;
	}
	else
		new_stach = ft_substr(stach, i + 1, ft_strlen(stach));
	free(stach);
	return (new_stach);
}

char *get_next_line(int fd)
{
	static char *stach;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stach = read_and_stach(fd, stach);
	if (!stach)
		return (NULL);
	line = extract_line(stach);
	if (!line)
    {
        free(stach);
        stach = NULL;
        return (NULL);
    }
	stach = update_stach(stach);
	return (line);
}
