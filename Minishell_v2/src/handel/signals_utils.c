/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:30:00 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 16:21:47 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

/**
 * Setup signals for heredoc: ignore SIGINT in parent while waiting
 */
void	setup_heredoc_signals(void)
{
	signal(SIGINT, SIG_IGN);
}

/**
 * Restore normal signal handler after heredoc
 */
void	restore_heredoc_signals(void)
{
	signal(SIGINT, ctrl_c_handler);
}

/**
 * Setup signals for child processes during execution
 * Children should handle signals normally (default behavior)
 */
void	setup_child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
