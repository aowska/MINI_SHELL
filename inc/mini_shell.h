/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:32:20 by aelsetih          #+#    #+#             */
/*   Updated: 2024/11/09 21:08:32 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
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
void    resirect_append(t_cmd_node *input);
void	resirect_output(t_cmd_node *input);


#endif
