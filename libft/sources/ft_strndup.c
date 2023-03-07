/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:21:49 by bgresse           #+#    #+#             */
/*   Updated: 2023/02/21 16:22:42 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*new;

	new = malloc(n + 1);
	if (new)
	{
		ft_strncpy(new, s, n);
		new[n] = '\0';
	}
	return (new);
}
