/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:31:03 by bgresse           #+#    #+#             */
/*   Updated: 2023/03/02 16:08:11 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*new_str;
	size_t	len1;
	size_t	i;

	if (!s1)
		return (NULL);
	len1 = ft_strlen(s1);
	new_str = malloc(sizeof(char) * (len1 + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	return (new_str);
}

char	*ft_remove_quote_in_string(char *string, bool quote, bool dquote)
{
	char	*new_string;
	size_t	i;

	i = 0;
	new_string = ft_strdup("");
	while (string[i])
	{
		if (string[i] == '\'')
			quote = !quote;
		if (string[i] == '\"')
			dquote = !dquote;
		if (quote && string[i + 1])
		{
			i++;
			while (string[i] && string[i] != '\'')
				new_string = ft_strjoin_char(new_string, string[i++]);
			quote = !quote;
		}
		else if (dquote && string[i + 1])
		{
			i++;
			while (string[i] && string[i] != '\"')
				new_string = ft_strjoin_char(new_string, string[i++]);
			dquote = !dquote;
		}
		else
			new_string = ft_strjoin_char(new_string, string[i]);
		i++;
	}
	return (new_string);
}

char	*ft_check_key(t_env *head, char *key)
{
	size_t	i;
	char	*temp_key;

	i = 0;
	while (key[i] && (ft_isalnum(key[i]) || key[i] == '_'))
		i++;
	temp_key = ft_substr(key, 0, i);
	while (head)
	{
		if (ft_strcmp(head->key, temp_key) == 0)
			return (ft_strdup(head->value));
		head = head->next;
	}
	return (ft_strdup(""));
}
