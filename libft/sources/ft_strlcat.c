/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:20:33 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/11 11:50:06 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	temp_src;
	size_t	temp_dst;
	size_t	temp;
	int		i;

	if (!dstsize)
		return (ft_strlen(src));
	temp_src = ft_strlen(src);
	temp_dst = ft_strlen(dst);
	if (dstsize <= temp_dst)
		return (temp_src + dstsize);
	temp = ft_strlen(dst);
	i = 0;
	while (src[i] && dstsize - temp_dst > 1)
	{
		dst[temp++] = src[i++];
		dstsize--;
	}
	dst[temp] = '\0';
	return (temp_src + temp_dst);
}
