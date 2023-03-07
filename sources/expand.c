/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:18:09 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/02 16:08:25 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strjoin_char(char const *s1, char c);
char	*ft_remove_quote_in_string(char *string, bool quote, bool dquote);
char	*ft_check_key(t_env *head, char *key);

char	*ft_expand_var(t_env **head, char *cmds)
{
	size_t	i;
	char	*new_cmds;
	bool 	dquote;
	bool 	quote;

	quote = false;
	dquote = false;
	i = 0;
	new_cmds = ft_strdup("");
	while (cmds[i])
	{
		if (cmds[i] == '\'')
			quote = !quote;
		if (cmds[i] == '\"')
			dquote = !dquote;
		if (quote && !dquote && cmds[i + 1])
		{
			while (cmds[i] && cmds[i + 1] != '\'')
				new_cmds = ft_strjoin_char(new_cmds, cmds[i++]);
		}
		if (cmds[i] == '$' && (dquote || (!dquote && !quote))
			&& cmds[i + 1] && ft_isalnum(cmds[i + 1]))
		{
			i++;
			new_cmds = ft_strjoin(new_cmds,
					ft_check_key(*head, cmds + i));
			while (cmds[i + 1] && (ft_isalnum(cmds[i + 1])
					|| cmds[i + 1] == '_'))
				i++;
		}
		else if (cmds[i] == '$' && (dquote || (!dquote && !quote))
			&& cmds[i + 1] == '?')
		{
			i++;
			new_cmds = ft_strjoin(new_cmds, ft_itoa(g_status));
		}
		else
			new_cmds = ft_strjoin_char(new_cmds, cmds[i]);
		i++;
	}
	return (new_cmds);
}

char	**ft_remove_quotes(char **cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i])
	{
		if (ft_strchr(cmds[i], '\'') || ft_strchr(cmds[i], '\"'))
			cmds[i] = ft_remove_quote_in_string(cmds[i], false, false);
		i++;
	}
	return (cmds);
}
