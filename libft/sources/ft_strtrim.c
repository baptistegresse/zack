/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:30:07 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/11 11:50:28 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ischeck(char c, char const *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	i;
	size_t	lens1;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	lens1 = ft_strlen(s1) - 1;
	while (ischeck(s1[i++], set))
		;
	i--;
	if (i >= ft_strlen(s1))
		return (ft_strdup(""));
	while (ischeck(s1[lens1--], set))
		;
	lens1++;
	string = ft_substr(s1, i, lens1 - i + 1);
	return (string);
}
