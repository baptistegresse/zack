/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:30:52 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/12 17:00:37 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		x;
	int		p;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (to_find[i] != '\0')
		i++;
	x = 0;
	while (str[x] != '\0')
	{
		p = 0;
		if (str[x] == to_find[p])
		{
			while (str[x + p] == to_find[p])
			{
				p++;
				if (p == i)
					return (str + x);
			}
		}
		x++;
	}
	return (0);
}
