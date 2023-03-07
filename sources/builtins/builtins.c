/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:24:08 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/06 18:49:19 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_builtins(t_minishell *data)
{
	if (!ft_strcmp(data->cmds->full_cmd[0], "pwd"))
		return (ft_built_in_pwd(), 1);
	if (!ft_strcmp(data->cmds->full_cmd[0], "env") && \
	(!data->cmds->full_cmd[1] || !*data->cmds->full_cmd[1]))
		return (ft_built_in_env(data->envp), 1);
	if (!ft_strcmp(data->cmds->full_cmd[0], "export"))
		return (ft_built_in_export(&data->head_env, data->cmds->full_cmd), 1);
	if (!ft_strcmp(data->cmds->full_cmd[0], "cd"))
		return (1);
	if (!ft_strcmp(data->cmds->full_cmd[0], "unset"))
		return (1);
	return (0);
}

void	ft_special_builtins(t_minishell *data)
{
	if (!data->cmds->next && data->cmds->full_cmd[0])
	{
		if (!ft_strcmp(data->cmds->full_cmd[0], "cd"))
			return (ft_built_in_cd(&data->head_env, data->cmds->full_cmd));
		if (!ft_strcmp(data->cmds->full_cmd[0], "exit"))
			return (ft_built_in_exit(data));
		if (!ft_strcmp(data->cmds->full_cmd[0], "export") 
			&& data->cmds->full_cmd[1])
			return (ft_built_in_export(&data->head_env, 
			data->cmds->full_cmd)); 
		if (!ft_strcmp(data->cmds->full_cmd[0], "unset"))
			return (ft_built_in_unset(&data->head_env, \
			data->cmds->full_cmd));
	}
}
