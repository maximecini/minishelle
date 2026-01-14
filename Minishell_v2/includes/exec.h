/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:15:00 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 22:46:39 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libft.h"
# include "struct.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// Structure pour l'exécution adaptée à votre minishell
typedef struct s_exec
{
	t_list	*lst_env;
	int		nb_cmd;
	int		*pipefd;
	int		prev_fd;
	pid_t	*pid;
	int		status;
	t_list	*lst_cmd;
	char	**tab;
}			t_exec;

// Fonctions principales d'exécution
int			execute_pipeline(t_list *lst_cmd, t_list **lst_env, char **tab,
				t_cleanup_ctx *ctx);
int			execute_single_command(t_cmd *cmd, t_list *lst_env);

// Gestion des pipes
int			setup_pipes(t_exec *exec);
void		setup_child_pipes(t_exec *exec, int cmd_index);
void		close_pipes(t_exec *exec, int cmd_index);

// Gestion des duplications de STDIO
int			save_stdio(int fds[2]);
void		restore_stdio(int fds[2]);

// Gestion des redirections
int			validate_redirect(t_redirect *redirect);
int			setup_redirections(t_cmd *cmd);
int			open_input_file(char *filename);
int			open_output_file(char *filename, int type);

// Exécution des commandes
void		execute_child_process(t_cmd *cmd, t_exec *exec);
char		*find_command_path(char *cmd, t_list *lst_env);
char		**env_list_to_array(t_list *lst_env);

// Gestion des erreurs et nettoyage
void		cleanup_exec(t_exec *exec);
int			wait_for_children(t_exec *exec);
void		handle_exec_error(char *cmd, char *error_msg);
void		cleanup_child_inherited(t_exec *exec);

#endif
