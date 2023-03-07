
#include "../../includes/minishell.h"

void ft_print_env_sorted(t_env *env)
{
	// Copie de la liste chaînée
	t_env *copy = env;
	int count = 0;
	while (copy != NULL)
	{
		count++;
		copy = copy->next;
	}

	t_env **array = malloc(count * sizeof(t_env *));
	if (array == NULL)
	{
		printf("Erreur d'allocation de mémoire\n");
		return;
	}

	copy = env;
	for (int i = 0; i < count; i++)
	{
		array[i] = copy;
		copy = copy->next;
	}

	// Tri à bulles
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (ft_strcmp(array[j]->key, array[j+1]->key) > 0)
			{
				t_env *temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

	// Affichage des éléments triés
	for (int i = 0; i < count; i++)
	{
		if (ft_strcmp(array[i]->value, ""))
		{
			printf("declare -x %s", array[i]->key);
			if (array[i]->equal)
				printf("=");
			printf("\"%s\"\n", array[i]->value);
		}
		else
		{
			printf("declare -x %s", array[i]->key);
			if (array[i]->equal)
				printf("=\"\"\n");
			else
				printf("\n");
		}
	}
	// Libération de la mémoire allouée
	free(array);
}

t_env *ft_get_env_node(t_env **head, char *key)
{
    t_env *temp = *head;

    while (temp != NULL)
    {
        if (ft_strcmp(temp->key, key) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void ft_modify_env_with_equal_sign(t_env **head, char *cmd_arg)
{
    t_env *env_var;
    char *key; 
    char *value;
	
	key = ft_strndup(cmd_arg, ft_strlen(cmd_arg) - ft_strlen(ft_strchr(cmd_arg, '=')));
	value = ft_strdup(ft_strchr(cmd_arg, '=') + 1);
	env_var = ft_get_env_node(head, key);
    if (env_var)
    {
        env_var->value = value;
        env_var->equal = true;
        free(key);
    }
    else
        *head = add_node(*head, key, value, true);
}

void ft_modify_env_without_equal_sign(t_env **head, char *cmd_arg)
{
    if (!ft_get_env_node(head, cmd_arg))
        *head = add_node(*head, cmd_arg, "", false);
}


int	ft_check_env_var_name(char *str)
{
	int i;

	i = 0;
	if (ft_isdigit(str[i]))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (0);
	}
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void ft_built_in_export(t_env **head, char **full_cmd)
{
    size_t	i;

    if (!full_cmd[1])
        return (ft_print_env_sorted(*head));
	i = 1;
    while (full_cmd[i])
    {
		if (ft_check_env_var_name(full_cmd[i]) == 0)
			break ;
        if (ft_strchr(full_cmd[i], '='))
            ft_modify_env_with_equal_sign(head, full_cmd[i]);
        else
            ft_modify_env_without_equal_sign(head, full_cmd[i]);
        i++;
    }
}