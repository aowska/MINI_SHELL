/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:04:50 by aelsetih          #+#    #+#             */
/*   Updated: 2024/11/05 20:04:54 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	parsing(t_cmd_shell *cmd)
{
	if (cmd->node->type == PWD)
		ft_pwd();
	else if(cmd->node->type == LS)
		fd_ls();
	else if(cmd->node->type == ECHO)
		fd_echo(cmd->node);

	if (cmd->node != NULL)
	{
		free_cmd_node(cmd->node);
		cmd->node = NULL;	
	}
}
