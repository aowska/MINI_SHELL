/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:13:13 by awacowsk          #+#    #+#             */
/*   Updated: 2024/11/10 21:03:49 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_shell.h"

#include <stdio.h>
#include <string.h>

void check_parag(char **args)
{
	char *start_quote;
	char *end_quote;
	size_t len;
	char quote_char;

	if (*args && (**args == '"' || **args == '\''))
	{
		quote_char = **args;

		start_quote = strchr(*args, quote_char);
		if (start_quote)
			memmove(start_quote, start_quote + 1, strlen(start_quote));

		end_quote = strrchr(*args, quote_char);
		if (end_quote)
			*end_quote = '\0';
	}
	len = strlen(*args);
	if (len > 0 && (*args)[len - 1] == ';')
		(*args)[len - 1] = '\0';
}

int fd_echo(t_cmd_node *input, char **env)
{
	t_cmd_node *temp;
	int no_newline;

	temp = input;
	no_newline = 0;
	if (!input)
		return (1);
	input = input->next;
	if (input && strcmp(input->token, "-n") == 0)
	{
		no_newline = 1;
		input = input->next;
	}
	while (temp)
	{
		if (temp->type == REDIRECT_APPEND)
			return (resirect_append(temp), 0);
		else if (temp->type == REDIRECT_OUTPUT)
			return (resirect_output(temp), 0);
		else if (temp->type == REDIRECT_INPUT)
			return (printf("\n"), 0);
		else if (temp->type == HEREDOC)
		{
			if(heredoc(temp) != NULL)
				return (printf("\n"), 0);
			else
				return (0);
		}
		else if (temp->type == VARIABLE)
			return (fd_variable(temp, env, no_newline), 0);
		temp = temp->next;
	}
	while (input)
	{
		check_parag(&input->token);
		printf("%s", input->token);
		input = input->next;
	}
	if (!no_newline)
		printf("\n");
	return (0);
}
