// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_split_quotes.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/11 19:37:03 by zrebhi            #+#    #+#             */
// /*   Updated: 2023/02/24 15:14:31 by zrebhi           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/libft.h"

// void		ft_quotes(char const *s, int *j);
// int			ft_separator(char c, char *charset);
// char		**ft_free_strs(char **strs);

// static int	ft_words(char const *s, char c)
// {
// 	int	i;
// 	int	words;

// 	i = 0;
// 	words = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		ft_quotes(s, &i);
// 		if (s[i] != c && s[i] != 0)
// 		{
// 			words++;
// 			i++;
// 		}
// 		while (s[i] && s[i] != c && !ft_separator(s[i], "\'\""))
// 			i++;
// 	}
// 	return (words);
// }

// static char	*ft_dupstr(char const *s, int i, int j)
// {
// 	char	*dup;
// 	int		x;

// 	dup = malloc(sizeof(char) * (j - i + 1));
// 	if (!dup)
// 		return (0);
// 	x = 0;
// 	while (s[i] && i < j)
// 		dup[x++] = s[i++];
// 	dup[x] = 0;
// 	return (dup);
// }

// static	char	**ft_lines(char const *s, char c, char **strs, int x)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		j = i;
// 		ft_quotes(s, &j);
// 		while (s[j] && s[j] != c)
// 		{
// 			j++;
// 			ft_quotes(s, &j);
// 		}
// 		if (s[j] == c || (!s[j] && s[j - 1] != c))
// 		{
// 			strs[x] = ft_dupstr(s, i, j);
// 			printf("strs[%d] : %s\n", x, strs[x]);
// 			if (strs[x] == 0)
// 				return (ft_free_strs(strs));
// 			x++;
// 			i = j;
// 		}
// 	}
// 	return (strs);
// }

// char	**ft_split_quotes(char const *s, char c)
// {
// 	char	**strs;
// 	int		i = -1;

// 	if (!s)
// 		return (0);
// 	strs = malloc(sizeof(char *) * (ft_words(s, c) + 1));
// 	if (!strs)
// 		return (NULL);
// 	strs = ft_lines(s, c, strs, 0);
// 	if (strs)
// 		strs[ft_words(s, c)] = 0;
// 	while(strs[++i])
// 		printf("strs[%d] : %s\n", i, strs[i]);
// 	return (strs);
// }

// // int	main()
// // {
// // 	int	i;
// // 	char *line = "echo nique\"ton\"oncle";
// // 	char **strs;
	
// // 	i = -1;
// // 	strs = ft_split_quotes(line, ' ');
// // 	printf("---------------\n");
// // 	while(strs[++i])
// // 		printf("strs[%d] : %s\n", i, strs[i]);
// // }
