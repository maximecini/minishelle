/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:38:14 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 17:37:25 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "libft.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <termios.h>
# include <unistd.h>
# define DBL_QUOTES 34
# define SIMPLE_QUOTES 39

# define WORD 0
# define REDIR_IN 1
# define REDIR_OUT 2
# define REDIR_APPEND 3
# define HEREDOC 4
# define PIPE 5
# define EOL 6

# define MAX_REDIRECTS 255
# define MAX_PIPELINE_CMDS 1024

extern int			g_last_status;

typedef struct s_expand_state
{
	char			*result;
	int				capacity;
	int				len;
	int				in_single_quote;
	int				in_double_quote;
	int				respect_single_quotes;
}					t_expand_state;

typedef struct s_redirect
{
	int				type;
	int				is_heredoc;
	int				expand_heredoc;
	char			*files;
	char			*eof;
}					t_redirect;

typedef struct s_cmd
{
	char			**cmd;
	int				*cmd_quoted;
	int				cmd_capacity;
	int				cmd_count;
	int				infile;
	int				outfile;
	int				status;
	int				pid;
	int				error;
	int				nb_redirect;
	t_redirect		*redirect;
}					t_cmd;

typedef struct s_token
{
	int				type;
	char			*value;
}					t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				add;
}					t_env;

typedef struct s_prompt_state
{
	t_list			**lst_token;
	t_list			**lst_cmd;
	char			***tab;
	char			*line;
	t_list			*lst_env;
	int				result;
	int				last_exit_code;
	int				should_exit;
	struct termios	original_term;
}					t_prompt_state;

typedef struct s_cleanup_ctx
{
	t_list			**lst_token;
	t_list			**lst_cmd;
	char			***tab;
	t_list			*lst_env;
	struct termios	*original_term;
	int				last_exit_code;
}					t_cleanup_ctx;

typedef struct s_heredoc_singleton
{
	t_cleanup_ctx	*ctx;
	int				fd;
	char			*eof_str;
	char			*path;
	char			*inherited_path;
}					t_heredoc_singleton;

/*
** Structure pour gérer l'état durant le trim/quote removal
*/
typedef struct s_trim_state
{
	char			*result;
	int				len;
	int				in_single_quote;
	int				in_double_quote;
}					t_trim_state;

#endif
