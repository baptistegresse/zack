/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:31:31 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/11 11:50:15 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	string = (char *)malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (!string)
		return (NULL);
	while (*s)
	{
		string[i] = f(i, *s);
		i++;
		s++;
	}
	string[i] = '\0';
	return (string);
}
