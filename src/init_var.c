/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:31:57 by aelsetih          #+#    #+#             */
/*   Updated: 2024/10/28 19:32:08 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

static t_exp_node	*newexp_node(char *str)
{
	t_exp_node	*new;

	new = (t_exp_node *)malloc(sizeof(t_exp_node));
	if (!new)
		return (NULL);
	new->exp_node = ft_strdup(str);
	new->next = NULL;
	return (new);
}

static t_env_node	*newenv_node(char *str)
{
	t_env_node	*new;

	new = (t_env_node *)malloc(sizeof(t_env_node));
	if (!new)
		return (NULL);
	new->env_node = ft_strdup(str);
	new->next = NULL;
	return (new);
}

static void	expadd_backnode(t_exp_node **lst, t_exp_node *new)
{
	t_exp_node	*list;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	list = *lst;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
}

static void	envadd_backnode(t_env_node **lst, t_env_node *new)
{
	t_env_node	*list;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	list = *lst;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
}

t_cmd_shell	*init_cmd(char **envp)
{
	t_cmd_shell		*cmd;
	t_env_node		*new_env_node;
	t_exp_node		*new_exp_node;
	int				i;
	int				len;

	cmd = (t_cmd_shell *)malloc(sizeof(t_cmd_shell));
	if (!cmd)
		return (NULL);
	len = 0;
	while (envp[len])
		len++;
	cmd->env = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cmd->env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		cmd->env[i] = ft_strdup(envp[i]);
		new_env_node = newenv_node(envp[i]);
		new_exp_node = newexp_node(envp[i]);
		envadd_backnode(&(cmd->env_node), new_env_node);
		expadd_backnode(&(cmd->exp_node), new_exp_node);
		i++;
	}
	cmd->env[i] = NULL;
	cmd->argv = NULL;
	return (cmd);
}