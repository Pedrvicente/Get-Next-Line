/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-al <pedde-al@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:42:15 by pedde-al          #+#    #+#             */
/*   Updated: 2025/12/01 13:22:32 by pedde-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	size_t	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  i;
    size_t  s1_len;
    size_t  s2_len;
    char    *str;

    s1_len = 0;
    s2_len = 0;
    if (s1)
        s1_len = ft_strlen(s1);
    if (s2)
        s2_len = ft_strlen(s2);
    str = (char *)malloc(s1_len + s2_len + 1);
    if (!str)
        return (NULL);
    i = -1;
    while (s1 && ++i < s1_len)
        str[i] = s1[i];
    i = -1;
    while (s2 && ++i < s2_len)
        str[s1_len + i] = s2[i];
    str[s1_len + s2_len] = '\0';
    return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = ft_strlen(s) + 1;
	str = (char *)malloc(size);
	if (!(str))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	else if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
