/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:28:57 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/11 11:49:33 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	i;
	int		j;

	j = 0;
	i = ft_strlen(s1);
	string = (char *)malloc((sizeof(char) * (i + 1)));
	if (!string)
		return (NULL);
	while (*s1)
	{
		string[j++] = *(s1++);
	}
	string[j] = '\0';
	return (string);
}
