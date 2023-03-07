/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:37:40 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/07 17:20:37 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_built_in_env(char **envp)
{
	size_t	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strchr(envp[i], '='))
		printf("%s\n", envp[i]);
	}
}
