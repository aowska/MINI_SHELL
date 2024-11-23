/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:25:24 by alicjawacow       #+#    #+#             */
/*   Updated: 2024/11/10 21:30:51 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	fd_cat(t_cmd_node *input)
{
	t_cmd_node	*temp;

	temp = input;
	if (!input)
		return ;
	while (temp)
	{
		if (temp->type == REDIRECT_INPUT)
			return (resirect_input(temp), (void)0);
		else if (temp->type == HEREDOC)
			return (printf("%s", heredoc(temp)), (void)0);
		temp = temp->next;
	}
    return ;
}
