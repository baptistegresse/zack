/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:31:02 by bgresse           #+#    #+#             */
/*   Updated: 2023/01/25 15:39:43 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_remove_if(t_free **begin_list, void *ptr_ref)
{
	t_free	*to_free;

	if (*begin_list)
	{
		if ((*begin_list)->ptr == ptr_ref)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			if (to_free->ptr)
				free(to_free->ptr);
			free(to_free);
			ft_free_remove_if(begin_list, ptr_ref);
		}
		else
			ft_free_remove_if(&(*begin_list)->next, ptr_ref);
	}
}

void	ft_free_remove(t_m_free *m_free, void *ptr)
{
	ft_free_remove_if(&m_free->list, ptr);
}
