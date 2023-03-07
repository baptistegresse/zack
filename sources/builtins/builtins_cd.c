#include "../../includes/minishell.h"

void	ft_set_env(t_env **head, char *key, char *value, bool equal)
{
	t_env	*temp;

	temp = *head;
	while (temp)
	{
		if (!ft_strcmp(temp->key, key))
		{
			free(temp->value);
			temp->value = ft_strdup(value);
			temp->equal = equal;
			return ;
		}
		temp = temp->next;
	}
	*head = add_node(*head, key, value, equal);
}

void	ft_built_in_cd(t_env **head, char **full_cmd)
{
	char	cwd[PATH_MAX];

	if (chdir(full_cmd[1]) == -1)
		perror("chdir()");
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (ft_get_env(head, "PWD"))
			ft_set_env(head, "OLDPWD", ft_get_env(head, "PWD"), true);
		ft_set_env(head, "PWD", cwd, true);
	}
	else
		perror("getcwd()");
}
