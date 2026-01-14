/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:45:13 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 16:23:45 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static unsigned long	next_heredoc_suffix(void)
{
	static unsigned long	counter;

	return (counter++);
}

static char	*append_pid(char *base)
{
	char	*pid;
	char	*prefix;

	if (!base)
		return (NULL);
	pid = ft_itoa(getpid());
	if (!pid)
		return (free(base), (NULL));
	prefix = ft_strjoin(base, pid, 0, 0);
	free(base);
	free(pid);
	return (prefix);
}

static char	*append_counter(char *prefix)
{
	char	*suffix;
	char	*path;

	suffix = ft_itoa(next_heredoc_suffix());
	if (!suffix)
		return (free(prefix), (NULL));
	path = ft_strjoin(prefix, suffix, 0, 0);
	free(prefix);
	free(suffix);
	return (path);
}

char	*make_tempfile_path(void)
{
	char	*prefix;

	prefix = append_pid(ft_strdup(HD_BASE));
	if (!prefix)
		return (NULL);
	return (append_counter(prefix));
}
