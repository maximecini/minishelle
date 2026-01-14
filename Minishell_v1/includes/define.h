/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:34:09 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:39:13 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

extern int	g_last_status;
# define UNCLOSED_NONE 0
# define UNCLOSED_DOUBLE_QUOTE 1
# define UNCLOSED_SINGLE_QUOTE 2

# define EXPORT_NO_VALID 1

# define OR "||"
# define PIPE "|"
# define APPEND ">>"
# define HEREDOC "<<"
# define REDIR_OUT ">"
# define REDIR_IN "<"

#endif
