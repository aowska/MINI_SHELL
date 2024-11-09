/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell_strucht.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:20:35 by aelsetih          #+#    #+#             */
/*   Updated: 2024/10/28 19:20:36 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_STRUCT_H
# define MINI_SHELL_STRUCT_H

typedef enum s_node_type
{
	PWD,
	CD,
	ECHO,
	PIPE,
	LS,
	REDIRECT_INPUT,
	REDIRECT_OUTPUT,
	REDIRECT_APPEND,
	HEREDOC,
	VARIABLE,
	EXIT,
	ARGUMENT
}	t_node_type;


typedef struct s_cmd_node
{
	char	*token;
	t_node_type	type;
	struct s_cmd_node	*next;
	struct s_cmd_node	*prev;
}	t_cmd_node;

typedef struct s_cmd_shell
{
	char	**argv;
	t_cmd_node	*node;
}	t_cmd_shell;

#endif
