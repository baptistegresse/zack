/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_slash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:37:03 by zrebhi            #+#    #+#             */
/*   Updated: 2023/02/15 16:32:16 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_free_strs(char **strs);

static int	ft_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i] != 0)
		{
			words++;
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char	*ft_dupstr(char const *s, int i, int j)
{
	char	*dup;
	int		x;

	dup = malloc(sizeof(char) * (j - i + 2));
	if (!dup)
		return (0);
	x = 0;
	while (s[i] && i < j)
		dup[x++] = s[i++];
	dup[x] = '/';
	dup[x + 1] = 0;
	return (dup);
}

static	char	**ft_lines(char const *s, char c, char **strs, int x)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (s[j] == c || (!s[j] && s[j - 1] != c))
		{
			strs[x] = ft_dupstr(s, i, j);
			if (strs[x] == 0)
				return (ft_free_strs(strs));
			x++;
			i = j;
		}
	}
	return (strs);
}

char	**ft_split_slash(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (ft_words(s, c) + 2));
	if (!strs)
		return (NULL);
	strs = ft_lines(s, c, strs, 0);
	if (strs)
		strs[ft_words(s, c)] = 0;
	return (strs);
}
