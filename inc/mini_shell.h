/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:32:20 by aelsetih          #+#    #+#             */
/*   Updated: 2024/10/20 15:32:21 by aelsetih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include "mini_shell_struct.h"
# include "../ft_printf/ft_printf.h"

t_cmd_shell	*init_cmd();
char	**fft_split(const char *str);
void	handle_input(t_cmd_shell *cmd);
void	parsing(t_cmd_shell *cmd);
void	ft_pwd(void);
void    fd_ls(void);
int     fd_echo(t_cmd_node *input);
void	free_cmd_node(t_cmd_node *node);
void    save_in_file(t_cmd_node *input);


#endif
