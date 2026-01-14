/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_uchild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:31:24 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 15:33:18 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	cleanup_child_inherited(t_exec *exec)
{
	if (exec->pid)
		free(exec->pid);
	if (exec->pipefd)
		free(exec->pipefd);
	if (exec->tab)
		ft_free_split(exec->tab);
	if (exec->lst_cmd)
		ft_lstclear(&exec->lst_cmd, free_node_cmd_content);
	if (exec->lst_env)
		ft_lstclear(&exec->lst_env, free_node_env_content);
}
