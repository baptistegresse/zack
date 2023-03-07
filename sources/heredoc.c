/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:52:56 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/07 20:06:26 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_heredoc_signals(void);

static void	ft_input(t_cmdlist *cmds, t_env **head_env)
{
	char	*line;

	set_heredoc_signals();
	if (close(cmds->here_doc_pipe[0]) == -1)
		return (perror("close pipe"));
	if (dup2(cmds->here_doc_pipe[1], 2) == -1)
		return (perror("close dup2"));
	if (close(cmds->here_doc_pipe[1]) == -1)
		return (perror("close pipe"));
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("warning: here-document \
			delimited by end-of-file (wanted `%s')\n", cmds->limiter);
			break ;
		}
		if (!ft_strcmp(line, cmds->limiter))
			break ;
		line = ft_expand_var(head_env, line);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
		free(line);
	}
	exit(0);
}

void	ft_heredoc(t_cmdlist *cmds, t_env **head)
{
	pid_t	here_doc_pid;
	int		status;

	unplug_signals();
	if (cmds->here_doc > 1 && close(cmds->here_doc_pipe[0]) == -1)
		perror("pipe multi-heredoc");
	if (pipe(cmds->here_doc_pipe) == -1)
		return (perror("heredoc pipe"));
	here_doc_pid = fork();
	if (here_doc_pid == -1)
		return (perror("heredoc fork"));
	if (here_doc_pid == 0)
		ft_input(cmds, head);
	if (close(cmds->here_doc_pipe[1]) == -1)
		return (perror("close pipe"));
	waitpid(here_doc_pid, &status, 0);
	g_status = WEXITSTATUS(status);
	if (g_status)
		if (close(cmds->here_doc_pipe[0]) == -1)
			return (cmds->error = 1, perror("close pipe"));
}

void	ft_redirect_pipe(t_cmdlist **cmds);
char	**ft_remove_quotes(char **strs);
void	ft_print_error(char **parsed_line, int i);
int		ft_error(char **parsed_line, int i);

int	ft_check_heredoc(char *cmd_line, t_cmdlist *cmds, t_env **head)
{
	char	**parsed_line;
	int		i;

	parsed_line = ft_split_tokens(cmd_line, "<|>");
	if (!parsed_line)
		return (0);
	parsed_line = ft_remove_quotes(parsed_line);
	if (!parsed_line)
		return (0);
	i = -1;
	while (parsed_line[++i])
	{
		if (!ft_strcmp(parsed_line[i], ">"))
		{
			if (parsed_line[i + 1] && parsed_line[i + 2] && !ft_strcmp(parsed_line[i + 1], "|"))
			{
				i++;
				continue ;
			}	
		}	
		if (ft_error(parsed_line, i))
		{
			ft_print_error(parsed_line, i);
			g_status = 2;
			return (0);
		}
		if (!ft_strcmp(parsed_line[i], "|"))
			ft_redirect_pipe(&cmds);
		else if (!ft_strcmp(parsed_line[i], "<<"))
		{
			cmds->here_doc += 1;
			cmds->limiter = parsed_line[i + 1];
			ft_heredoc(cmds, head);
		}
	}
	return (1);
}