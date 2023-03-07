/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:37:03 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/06 15:35:38 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_quotes(char const *s, int *j);
int			ft_separator(char c, char *charset);
char		**ft_free_strs(char **strs);

static int	ft_words(char const *s, char *charset, int i, int words)
{
	while (s[i])
	{
		while (s[i] && ft_separator(s[i], " "))
			i++;
		ft_quotes(s, &i);
		if (ft_separator(s[i], charset))
		{
			words++;
			i++;
			if (s[i] == s[i - 1])
				i++;
			continue ;
		}
		if (!ft_separator(s[i], " ") && s[i])
			words++;
		while (s[i] && !ft_separator(s[i], charset) && !ft_separator(s[i], " "))
		{
			i++;
			ft_quotes(s, &i);
		}
	}
	return (words);
}

static char	*ft_dupstr(char const *s, int i, int j)
{
	char	*dup;
	int		x;

	dup = malloc(sizeof(char) * (j - i + 1));
	if (!dup)
		return (0);
	x = 0;
	while (s[i] && i < j)
		dup[x++] = s[i++];
	dup[x] = 0;
	return (dup);
}

typedef struct s_split
{
	int		i;
	int		j;
	int		x;
	char	**strs;
}			t_split;

static void	ft_lines2(char const *s, char *charset, t_split *lines)
{
	while (s[lines->j] && !ft_separator(s[lines->j], charset) && \
		!ft_separator(s[lines->j], " "))
	{
		ft_quotes(s, &lines->j);
		lines->j++;
	}
	if (ft_separator(s[lines->j], charset) || \
	ft_separator(s[lines->j], " ") || (!s[lines->j] && \
	!ft_separator(s[lines->j - 1], " ")))
	{
		lines->strs[lines->x] = ft_dupstr(s, lines->i, lines->j);
		if (lines->strs[lines->x] == 0)
			return ((void)ft_free_strs(lines->strs));
		lines->x++;
		lines->i = lines->j;
	}
}

static char	**ft_lines(char const *s, char *charset, t_split *lines)
{
	while (s[lines->i])
	{
		while (s[lines->i] && ft_separator(s[lines->i], " "))
			lines->i++;
		if (ft_separator(s[lines->i], charset))
		{
			if (s[lines->i] == s[lines->i + 1])
			{
				lines->strs[lines->x] = ft_dupstr(s, lines->i, lines->i + 2);
				lines->i++;
			}
			else
				lines->strs[lines->x] = ft_dupstr(s, lines->i, lines->i + 1);
			if (lines->strs[lines->x] == 0)
				return (ft_free_strs(lines->strs));
			lines->i++;
			lines->x++;
			continue ;
		}
		lines->j = lines->i;
		ft_lines2(s, charset, lines);
	}
	return (lines->strs);
}

char	**ft_split_tokens(char const *s, char *charset)
{
	t_split	lines;

	lines.i = 0;
	lines.x = 0;
	if (!s)
		return (0);
	lines.strs = malloc(sizeof(char *) * (ft_words(s, charset, 0, 0) + 1));
	if (!lines.strs)
		return (NULL);
	lines.strs = ft_lines(s, charset, &lines);
	if (lines.strs)
		lines.strs[ft_words(s, charset, 0, 0)] = 0;
	return (lines.strs);
}

// int	main()
// {
// 	int	i;
// 	char *line = "echo salut >> outfile";
// 	char **strs;

// 	i = -1;
// 	printf("%d words\n", ft_words(line, "<|>"));
// 	strs = ft_split_tokens(line, "<|>");
// 	printf("---------------\n");
// 	while(strs[++i])
// 	{
// 		printf("strs[%d] :%s\n", i, strs[i]);
// 	}
// }
