/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:31:37 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/25 15:39:40 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_free_size(t_m_free *m_free)
{
	t_free	*tmp;
	int		index;

	index = 0;
	tmp = m_free->list;
	if (tmp)
		index = 1;
	if (!tmp)
		return (index);
	while (tmp->next)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}
