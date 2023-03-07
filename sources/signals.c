/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:00:12 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/06 12:56:10 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_ctrl_c(int signum, siginfo_t *info, void *context);
void	handle_ctrl_c_heredoc(int signum, siginfo_t *info, void *context);
void	handle_ctrl_c_exec(int signum, siginfo_t *info, void *context);
void	handle_ctrl_d_exec(int signum, siginfo_t *info, void *context);

void	set_interactive_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	sa.sa_sigaction = handle_ctrl_c;
	sigaction(SIGINT, &sa, NULL);
}

void	set_exec_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	sa.sa_sigaction = handle_ctrl_c_exec;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_sigaction = handle_ctrl_d_exec;
	sigaction(SIGQUIT, &sa, NULL);
}

void	set_heredoc_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	sa.sa_sigaction = handle_ctrl_c_heredoc;
	sigaction(SIGINT, &sa, NULL);
}

void	unplug_signals(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
