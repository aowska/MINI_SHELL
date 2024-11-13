/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:04:50 by aelsetih          #+#    #+#             */
/*   Updated: 2024/11/10 21:24:44 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	parsing(t_cmd_shell *cmd)
{
	int i;
	if (cmd->node->type == PWD)
		ft_pwd();
	else if(cmd->node->type == LS)
		fd_ls();
	else if(cmd->node->type == ECHO)
		fd_echo(cmd->node,cmd->env);
	else if (cmd->node->type == CAT)
		fd_cat(cmd->node);
	else if (cmd->node->type == ENV)
	{
		 i = 0;
        while (cmd->env[i])
            printf("%s\n", cmd->env[i++]);
	}
	if (cmd->node != NULL)
	{
		free_cmd_node(cmd->node);
		cmd->node = NULL;	
	}
}
