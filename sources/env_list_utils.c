/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:18:32 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/07 17:16:33 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*new_node(char *key, char *value, bool equal)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	node->key = ft_strndup(key, ft_strlen(key));
	node->value = ft_strndup(value, ft_strlen(value));
	node->equal = equal;
	return (node);
}

t_env	*add_node(t_env *head, char *key, char *value, bool equal)
{
	t_env	*node;

	node = new_node(key, value, equal);
	node->next = head;
	return (node);
}

int	ft_list_size(t_env *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
