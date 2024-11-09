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

t_cmd_shell	*init_cmd(void)
{
	t_cmd_shell	*cmd;

	cmd = (t_cmd_shell *)malloc(sizeof(t_cmd_shell));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	return (cmd);
}
