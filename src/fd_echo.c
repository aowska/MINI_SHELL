/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awacowsk <awacowsk@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-09 15:13:13 by awacowsk          #+#    #+#             */
/*   Updated: 2024-11-09 15:13:13 by awacowsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

void	check_parag(char **args)
{
	char	*start_quote;
	char	*end_quote;

	if (*args && **args == '"')
	{
		start_quote = ft_strchr(*args, '"');
		if (start_quote)
			ft_memmove(start_quote, start_quote + 1, ft_strlen(start_quote));
		end_quote = ft_strrchr(*args, '"');
		if (end_quote)
			*end_quote = '\0';
	}
}

int	fd_echo(t_cmd_node *input)
{
	t_cmd_node	*temp;

	temp = input;
	if (!input)
		return (1);

	while (temp)
	{
		if (temp->token == ">>")
			save_in_file(temp);
		temp = temp->next;
	}
	while (input)
	{
		check_parag(&input->token);
		printf("%s ", input->token);
		input = input->next;
	}

	printf("\n");
	return (0);
}