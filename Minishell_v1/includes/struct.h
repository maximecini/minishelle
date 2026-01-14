/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:35:46 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:36:28 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_redirection_type
{
	NO_REDIR,
	REDIR_STDIN,
	REDIR_STDOUT,
	REDIR_HEREDOC,
	REDIR_APPEND
}						t_redirection_type;
typedef struct s_redirect
{
	char				*filename;
	int					here_doc_fd;
	char				*heredoc_filename;
	char				*delimiteur;
	int					file;
	t_redirection_type	type;
}						t_redirect;

typedef struct s_split_state
{
	size_t				start;
	size_t				i;
	size_t				count;
	int					sq;
	int					dq;
}						t_split_state;
typedef struct s_node_cmd
{
	char				**cmd;
	int					nb_redirect;
	t_redirect			*redirect;

}						t_node_cmd;

typedef struct s_builtins
{
	char				*name;
}						t_builtins;

typedef struct t_node_env
{
	char				*key;
	char				*value;
	int					add;
}						t_node_env;

typedef struct s_exec
{
	int					pipe[2];
	int					nb_cmd;
	int					error;
	int					pipefd[2];
	int					prev_fd;
	pid_t				*pid;
	int					status;
	char				*path;
	int					i;
}						t_exec;

typedef struct s_heredoc_data
{
	int					here_doc_fd;
	char				*delimiteur;
	size_t				delim_len;
	char				*line;
}						t_heredoc_data;

typedef struct s_quote_state
{
	size_t	src_idx;
	size_t	dst_idx;
	int		in_single;
	int		in_double;
}			t_quote_state;

typedef struct s_char_copy
{
	size_t	read_index;
	size_t	write_index;
	int		in_quotes;
}			t_char_copy;

typedef struct s_syntax_state
{
	int	index;
	int	in_single_quote;
	int	in_double_quote;
}		t_syntax_state;

#endif
