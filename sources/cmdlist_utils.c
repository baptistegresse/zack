/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrebhi <zrebhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:03:53 by zrebhi            #+#    #+#             */
/*   Updated: 2023/03/06 11:35:54 by zrebhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* The following 3 functions allow ft_newnode to work.*/

t_cmdlist	*ft_cmdnew(void)
{
	t_cmdlist	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->full_cmd = 0;
	new->infile = 0;
	new->outfile = 1;
	new->here_doc = 0;
	new->error = 0;
	new->next = 0;
	return (new);
}

t_cmdlist	*ft_cmdlast(t_cmdlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_cmdadd_back(t_cmdlist **lst, t_cmdlist *new)
{
	t_cmdlist	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_cmdlast(*(lst));
			temp->next = new;
		}
	}
}

/* Creates a new node in our linked list of commands.*/

void	ft_newnode(t_cmdlist **cmds)
{
	t_cmdlist	*new;

	new = ft_cmdnew();
	ft_cmdadd_back(cmds, new);
}

void	ft_print_cmdlist(t_cmdlist *cmds)
{
	int	i;

	while (cmds)
	{
		i = -1;
		while (cmds->full_cmd[++i])
			printf("%s\n", cmds->full_cmd[i]);
		printf("infile : %d\noutfile : %d\nhere_doc : %d\n", \
		cmds->infile, cmds->outfile, cmds->here_doc);
		cmds = cmds->next;
		printf("\n");
	}
}
