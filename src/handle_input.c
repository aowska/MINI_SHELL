/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:04:57 by aelsetih          #+#    #+#             */
/*   Updated: 2024/11/10 21:24:32 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

static t_node_type	get_node_type(const char *token, int i)
{
	if ((ft_strncmp(token, "exit", ft_strlen(token)) == 0) && i == 0)
		return (EXIT);
	if (ft_strncmp(token, "pwd", ft_strlen(token)) == 0)
		return PWD;
	if (ft_strncmp(token, "cd", ft_strlen(token)) == 0)
		return CD;
	if (ft_strncmp(token, "echo", ft_strlen(token)) == 0)
		return ECHO;
	if (ft_strncmp(token, "|", ft_strlen(token)) == 0)
		return PIPE;
	if (ft_strncmp(token, "ls", ft_strlen(token)) == 0)
		return LS;
	if (ft_strncmp(token, "cat", ft_strlen(token)) == 0)
		return (CAT);
	if (ft_strncmp(token, "<", ft_strlen(token)) == 0)
		return (REDIRECT_INPUT);
	if (ft_strncmp(token, ">", ft_strlen(token)) == 0)
		return (REDIRECT_OUTPUT);
	if (ft_strncmp(token, ">>", ft_strlen(token)) == 0)
		return (REDIRECT_APPEND);
	if (ft_strncmp(token, "<<", ft_strlen(token)) == 0)
		return (HEREDOC);
	if (ft_strrchr(token, '$') && !ft_strrchr(token, '\''))
		return (VARIABLE);
	if (ft_strncmp(token, "env", ft_strlen(token)) == 0)
		return (ENV);
	return ARGUMENT;
}

const char *node_type_to_string(t_node_type type)
{
    switch (type)
    {
        case PWD:              return "PWD";
        case CD:               return "CD";
        case ECHO:             return "ECHO";
        case PIPE:             return "PIPE";
		case LS:				return "LS";
		case CAT:				return "CAT";
        case REDIRECT_INPUT:   return "REDIRECT_INPUT";
        case REDIRECT_OUTPUT:  return "REDIRECT_OUTPUT";
        case REDIRECT_APPEND:  return "REDIRECT_APPEND";
        case HEREDOC:         return "HEREDOC";
        case VARIABLE:         return "VARIABLE";
		case ENV:				return "ENV";
        case ARGUMENT:         return "ARGUMENT";
        case EXIT:             return "EXIT";
        default:               return "UNKNOWN";
    }
}

static t_cmd_node	*lstnew_node(const char *str, int i)
{
	t_cmd_node	*new;

	new = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (!new)
		return (NULL);
	new->token = ft_strdup(str);
	new->type = get_node_type(new->token, i);
	new->next = NULL;
	new->prev = NULL;
	ft_printf("%s\n", new->token);
	ft_printf("%s\n", node_type_to_string(new->type));	
	return (new);
}

static void	ft_stackadd_backnode(t_cmd_node **lst, t_cmd_node *new)
{
	t_cmd_node	*list;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	list = *lst;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
	new->prev = list;
}

void	handle_input(t_cmd_shell *cmd)
{
	t_cmd_node	*new_node;
	int			i;

	i = 0;
	while (cmd->argv[i])
	{
		new_node = lstnew_node(cmd->argv[i], i);
		ft_stackadd_backnode(&(cmd->node), new_node);
		i++;
	}
	parsing(cmd);
}
