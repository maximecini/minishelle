/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:22:15 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/10/16 16:21:41 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

extern void	rl_replace_line(const char *text, int clear_undo);

/**
 * Handler pour Ctrl+C dans le prompt principal
 * Affiche une nouvelle ligne et redessine le prompt
 */
void	ctrl_c_handler(int a)
{
	(void)a;
	g_last_status = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/**
 * Setup signals for parent during command execution
 * Parent should ignore signals while children are running
 */
void	setup_parent_exec_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

/**
 * Restore interactive signals after command execution
 */
void	restore_interactive_signals(void)
{
	signal(SIGINT, ctrl_c_handler);
	signal(SIGQUIT, SIG_IGN);
}
