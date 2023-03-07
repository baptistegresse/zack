/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:54:37 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/11 11:48:01 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_whitesapce(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	return (i);
}

static int	ft_sign(const char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		return (sign);
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	long long int	finale;
	int				i;
	int				sign;

	sign = ft_sign(str);
	finale = 0;
	i = ft_whitesapce(str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (finale != ((finale * 10 + (sign * (str[i] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		finale = finale * 10 + ((str[i] - '0') * sign);
		i++;
	}
	return ((int)finale);
}
