/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:37:31 by aelsetih          #+#    #+#             */
/*   Updated: 2024/11/05 20:37:33 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	free_cmd_node(t_cmd_node *node)
{
	t_cmd_node	*temp;

	while	(node)
	{
	temp = node;
	node = node->next;
	free(temp->token);
	free(temp);
	}
}
