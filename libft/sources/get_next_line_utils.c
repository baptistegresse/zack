/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:52:18 by zrebhi            #+#    #+#             */
/*   Updated: 2023/01/13 15:23:38 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *cache, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*cat;

	if (!cache)
	{
		cache = (char *)malloc(1 * sizeof(char));
		if (!cache)
			return (0);
		cache[0] = '\0';
	}
	if (!cache || !buffer)
		return (free(cache), free(buffer), NULL);
	cat = malloc(sizeof(char) * ((ft_strlen(cache) + ft_strlen(buffer)) + 1));
	if (!cat)
		return (free(cache), free(buffer), NULL);
	i = -1;
	j = 0;
	if (cache)
		while (cache[++i])
			cat[i] = cache[i];
	while (buffer[j])
		cat[i++] = buffer[j++];
	cat[ft_strlen(cache) + ft_strlen(buffer)] = 0;
	return (free(cache), cat);
}

char	*ft_strchr2(const char *s, int c)
{
	char	*str;
	int		i;
	char	c2;

	if (!s)
		return (0);
	str = (char *)s;
	c2 = c;
	i = 0;
	while (str[i])
	{
		if (str[i] == c2)
			return (&str[i]);
		i++;
	}
	if (c2 == 0)
		return (&str[i]);
	else
		return (0);
}

size_t	ft_linelen(const char *line)
{
	size_t	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}
