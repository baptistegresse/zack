#include "../../includes/minishell.h"

static void	remove_env_node(t_env **head, char *key)
{
	t_env	*current;
	t_env	*prev;

	current = *head;
	prev = NULL;
	if (current != NULL && ft_strcmp(current->key, key) == 0)
	{
		*head = current->next;
		return (free(current->key), free(current->value), free(current));
	}
	while (current != NULL && ft_strcmp(current->key, key) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	prev->next = current->next;
	return (free(current->key), free(current->value), free(current));
}


void	ft_built_in_unset(t_env **head, char **key_list)
{
	size_t	i;
	t_env	*temp;

	i = 1;
	while (key_list[i])
	{
		temp = *head;
		while (temp)
		{
			if (ft_strcmp(temp->key, key_list[i]) == 0)
				remove_env_node(head, key_list[i]);
			temp = temp->next;
		}
		i++;
	}
	temp = *head;
}
