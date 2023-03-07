/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:12:41 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/07 20:42:05 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_ctrl_c(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_status = 128 + signum;
}

void	handle_ctrl_d_exec(int signum, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	printf("Quit (core dumped)\n");
	g_status = 128 + signum;
	exit(g_status);
}

void	handle_ctrl_c_exec(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	write(1, "\n", 1);
	g_status = 128 + signum;
	exit(g_status);
}

void	handle_ctrl_c_heredoc(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	write(1, "\n", 1);
	g_status = 128 + signum;
	_exit(g_status);
}
