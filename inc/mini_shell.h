/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicjawacowska <alicjawacowska@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:32:20 by aelsetih          #+#    #+#             */
/*   Updated: 2024/11/10 21:25:59 by alicjawacow      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h> 
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <dirent.h>
# include "mini_shell_struct.h"
# include "../ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

// get next line 
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strcat(char *dest, char const *src);

t_cmd_shell	*init_cmd();
char	**fft_split(const char *str);
void	handle_input(t_cmd_shell *cmd);
void	parsing(t_cmd_shell *cmd);
void	ft_pwd(void);
void    fd_ls(void);
void	fd_cat(t_cmd_node *input);
int     fd_echo(t_cmd_node *input, char **env);
void	free_cmd_node(t_cmd_node *node);
void    resirect_append(t_cmd_node *input);
void	resirect_output(t_cmd_node *input);
void	resirect_input(t_cmd_node *input);
void	fd_variable(t_cmd_node *input, char **env, int no_newline);
void	heredoc(t_cmd_node *input);

#endif
