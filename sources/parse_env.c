/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:06:30 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/07 17:21:39 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_list_size(t_env *head);

void	ft_parse_env(t_env **head, char **envp)
{
	size_t	i;
	char	*equal;
	char	*key;
	char	*value;

	i = 0;
	if (!envp[0])
	{
		*head = add_node(*head, "_", "/usr/bin/env", true);
		*head = add_node(*head, "SHLVL", "1", true);
		*head = add_node(*head, "PWD", getcwd(NULL, 0), true);
	}
	while (envp[i])
	{
		equal = ft_strchr(envp[i], '=');
		if (equal)
		{
			key = ft_strndup(envp[i], equal - envp[i]);
			if (ft_strcmp(key, "SHLVL") == 0)
				value = ft_itoa(ft_atoi(equal + 1) + 1);
			else
				value = ft_strdup(equal + 1);
			*head = add_node(*head, key, value, true);
			free(key);
		}
		i++;
	}
}

char	*ft_get_env(t_env **head_env, char *key)
{
	t_env	*temp;

	temp = *head_env;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

char	**ft_pathfinder(t_env **head)
{
	char	*paths_line;
	char	**paths;

	paths_line = ft_get_env(head, "PATH");
	paths = ft_split_slash(paths_line, ':');
	return (paths);
}
