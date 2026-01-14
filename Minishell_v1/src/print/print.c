/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:52:37 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/26 18:23:13 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	print_single_redirect(t_redirect *redir, int index)
// {
// 	char	*type_str;

// 	switch (redir->type)
// 	{
// 	case NO_REDIR:
// 		type_str = "NO_REDIR";
// 		break ;
// 	case REDIR_STDIN:
// 		type_str = "REDIR_STDIN (<)";
// 		break ;
// 	case REDIR_STDOUT:
// 		type_str = "REDIR_STDOUT (>)";
// 		break ;
// 	case REDIR_HEREDOC:
// 		type_str = "REDIR_HEREDOC (<<)";
// 		break ;
// 	case REDIR_APPEND:
// 		type_str = "REDIR_APPEND (>>)";
// 		break ;
// 	default:
// 		type_str = "UNKNOWN";
// 		break ;
// 	}
// 	printf("    🔁 Redirect #%d: Type = %s, File = %s, here_doc_fd = %d\n",
// 		index, type_str, redir->filename ? redir->filename : "(null)",
// 		redir->here_doc_fd);
// }

// void	print_redirects(t_redirect *redirects, int nb_redirect)
// {
// 	int	i;

// 	i = 0;
// 	while (i < nb_redirect)
// 	{
// 		print_single_redirect(&redirects[i], i);
// 		i++;
// 	}
// }

// void	print_command_list_full(t_element *lst_cmd)
// {
// 	int			cmd_index;
// 	t_node_cmd	*cmd;
// 	int			i;

// 	cmd_index = 0;
// 	printf("\n=== LISTE DES COMMANDES ===\n");
// 	while (lst_cmd)
// 	{
// 		//#todo a mettre damn exec
// 		cmd = (t_node_cmd *)lst_cmd->content;
// 		printf("\n📦 Commande #%d:\n", cmd_index);
// 		if (cmd && cmd->cmd)
// 		{
// 			i = 0;
// 			while (cmd->cmd[i])
// 			{
// 				printf("  argv[%d] = %s\n", i, cmd->cmd[i]);
// 				i++;
// 			}
// 			if (i == 0)
// 				printf("  (argv vide)\n");
// 		}
// 		else
// 			printf("  (commande vide)\n");
// 		printf("  Redirections (nb = %d):\n", cmd ? cmd->nb_redirect : 0);
// 		if (cmd && cmd->redirect && cmd->nb_redirect > 0)
// 			print_redirects(cmd->redirect, cmd->nb_redirect);
// 		else
// 			printf("    (aucune redirection)\n");
// 		lst_cmd = lst_cmd->next;
// 		cmd_index++;
// 	}
// 	printf("\nNombre total de commandes : %d\n", cmd_index);
// }

// void	print_arr_env(char **new_env)
// {
// 	int	i;

// 	if (new_env == NULL || *new_env == NULL)
// 		return ;
// 	i = 0;
// 	printf("____ENV________\n\n");
// 	while (new_env[i])
// 	{
// 		printf("%s\n", new_env[i]);
// 		i++;
// 	}
// }
