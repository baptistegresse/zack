/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:12:12 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/06 16:24:21 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Creates a new node in our linked list of commands.*/

void	ft_newnode(t_cmdlist **cmds);

/* The 3 following functions handle the error message of bash
for invalid redirections. */

int	ft_error(char **parsed_line, int i)
{
	if ((!ft_strcmp(parsed_line[i], ">") \
		||!ft_strcmp(parsed_line[i], ">>") \
		|| !ft_strcmp(parsed_line[i], "<") \
		|| !ft_strcmp(parsed_line[i], "<<")) \
		|| !ft_strcmp(parsed_line[i], "|") \
		|| !ft_strcmp(parsed_line[i], "||"))
	{
		if (!parsed_line[i + 1])
			return (1);
		if ((!ft_strcmp(parsed_line[i + 1], ">") \
			||!ft_strcmp(parsed_line[i + 1], ">>") \
			|| !ft_strcmp(parsed_line[i + 1], "<") \
			|| !ft_strcmp(parsed_line[i + 1], "<<")) \
			|| !ft_strcmp(parsed_line[i + 1], "|") \
			|| !ft_strcmp(parsed_line[i + 1], "||"))
			return (2);
	}
	return (0);
}

void	ft_syntax_error(char **parsed_line, int i)
{
	ft_putstr_fd("syntax error near unexpected token '", 2);
	ft_putstr_fd(parsed_line[i], 2);
	ft_putstr_fd("'\n", 2);
}

void	ft_print_error(char **parsed_line, int i)
{
	if (ft_error(parsed_line, i) == 1)
	{
		if (!ft_strcmp(parsed_line[i], "|") || \
		!ft_strcmp(parsed_line[i], "||"))
			ft_syntax_error(parsed_line, i);
		else
			ft_putstr_fd("syntax error near unexpected token 'newline'\n", 2);
	}
	if (ft_error(parsed_line, i) == 2)
	{
		if (!ft_strcmp(parsed_line[i], "|") || \
		!ft_strcmp(parsed_line[i], "||"))
			ft_syntax_error(parsed_line, i + 1);
		else
			ft_syntax_error(parsed_line, i + 1);
	}
}

/* For each node of our cmd list,
stores the command in a char ** that we can send directly to execve.
Parameters int i and int j must be set to 0 on function call to save lines. */

void	ft_fullcmds(char **parsed_line, t_cmdlist *cmds, int i, int j)
{
	cmds->full_cmd = malloc(sizeof(char *) * 50);
	while (parsed_line[i])
	{
		if (!ft_strcmp(parsed_line[i], "|"))
		{
			cmds->full_cmd[j] = 0;
			cmds = cmds->next;
			cmds->full_cmd = malloc(sizeof(char *) * 50);
			j = 0;
			i++;
		}
		else if (!ft_strcmp(parsed_line[i], ">") \
			||!ft_strcmp(parsed_line[i], ">>") \
			|| !ft_strcmp(parsed_line[i], "<") \
			|| !ft_strcmp(parsed_line[i], "<<"))
		{
			i++;
			if (parsed_line[i])
				i++;
		}
		else
			cmds->full_cmd[j++] = parsed_line[i++];
	}
}

/* ft_cmdlist creates a linked list containing all the commands 
in the input line and useful informations for each of them. */

char	**ft_remove_quotes(char **strs);
void	ft_check_heredoc(char *cmd_line, t_cmdlist *cmds, t_env **head);
int		ft_redirection(char **parsed_line, t_cmdlist *cmds);

t_cmdlist	*ft_cmdlist(char *cmd_line, t_minishell *data)
{
	char		**parsed_line;
	t_cmdlist	*cmds;

	cmds = 0;
	ft_newnode(&cmds);
	ft_check_heredoc(cmd_line, cmds, &data->head_env);
	cmd_line = ft_expand_var(&data->head_env, cmd_line);
	parsed_line = ft_split_tokens(cmd_line, "<|>");
	parsed_line = ft_remove_quotes(parsed_line);
	if (!ft_redirection(parsed_line, cmds))
		return (0);
	ft_fullcmds(parsed_line, cmds, 0, 0);
	return (cmds);
}
