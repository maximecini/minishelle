/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:06:49 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 22:49:34 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H
# include "exec.h"
# include "libft.h"
# include "struct.h"
# include "utils.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
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
# define HD_BASE "/tmp/minishell_heredoc_"

/*---------------------MINISHELL-------------------*/
int				if_print_exit(void);
void			init_env(t_list **lst_env, char **env);
int				process_shell_loop(t_list **lst_token, t_list **lst_cmd,
					char ***tab, t_list **lst_env);
int				process_input_line(t_prompt_state *state);
int				handle_parse_result(t_prompt_state *state);
int				handle_heredoc(t_prompt_state *state, t_cleanup_ctx *ctx);
int				handle_expand(t_prompt_state *state);
int				run_execute(t_prompt_state *state, t_cleanup_ctx *ctx);
void			update_exit_code_in_env(t_list *lst_env, int exit_code);

/*---------------------QUOTE-------------------*/
int				create_lst_cmd(t_list *lst_token, t_list **lst_cmd);
int				create_list_token(t_list **lst_cmd, char **tab);
int				get_syntax_error(char *line);
int				fill_node(t_list **lst_cmd, t_list **lst_token);
// delimiter_process.c
char			*process_delimiter_string(char *str);
char			*remove_quotes_from_delimiter(char *eof, int *should_expand);
// lst.c and lst_fill.c
void			process_word(t_cmd **node_cmd, int *index, char *word);
int				process_token_redirect(t_cmd **node_cmd, t_token *lst_token,
					int *j);
int				count_redirect(t_list *lst_token);
int				count_cmd_words(t_list *lst_token);
int				fill_lst_node(t_list **lst_token, t_cmd **node_cmd);
void			next_cmd_lst(t_list **lst_token);
// tokenisation.c
t_token			create_token(char *type, char *value, int *skip_next);
// tokenisation_utils.c
int				add_token_to_list(t_list **lst_token, t_token *token_ptr);
// syntax_error_utils.c
int				syntax_error_msg(char *token);
int				is_inside_quotes(char *line, int pos);
// syntax_error_redirect.c
int				error_redirect(char *line, size_t len);
// syntax_error_redirect_utils.c
int				check_following_redirect(char *line, int j);
int				handle_input_triple(int count);
int				handle_triple_redirect(char redirect_char, int count,
					char *line, int j);
// syntax_error_pipe.c
int				error_pipe(char *line, size_t len);
/*---------------------ENV-------------------*/
int				cpy_tab_to_lst(t_list **lst_env, char **env);
t_list			**get_lst_key(t_list **lst_env, char *key);
int				update_nodes_env(t_list *lst_env, char *key, char *new_value,
					char *equal);
int				cmp_key(void *a, void *b);
char			*get_key(char *s);
char			*get_value(char *s);
int				get_error_export(char *cmd);
int				add_back_nodes_env(t_list **lst_env, char *cmd, int add);
int				export_no_valide(char *cmd, char *key, size_t siz_key);
/*---------------------UTILS-------------------*/
void			print_lst_env(t_list *lst_env);
int				ft_array_len(char **tab);
void			ft_sort_lst(t_list *head, int (*cmp)(void *, void *));
/*---------------------SIGNALS-------------------*/
void			ctrl_c_handler(int a);
void			setup_heredoc_signals(void);
void			restore_heredoc_signals(void);
void			setup_child_signals(void);
void			setup_parent_exec_signals(void);
void			restore_interactive_signals(void);
/*---------------------FREE-------------------*/
void			free_node_env_content(void *content);
void			free_node_cmd_content(void *content);
void			free_node_token_content(void *content);
int				free_all_with_cmd(t_list **lst_token, t_list **lst_cmd,
					char **tab, char *line);
void			cleanup_prompt_state(t_list **lst_token, t_list **lst_cmd,
					char ***tab);
/*---------------------HEREDOC-------------------*/
int				process_heredoc(t_list *lst_cmd, t_list *lst_env,
					t_cleanup_ctx *ctx);
int				ft_close(int *fd);
// heredoc_path.c
char			*make_tempfile_path(void);
// heredoc_utils.c
int				is_our_tempfile(const char *s);
void			cleanup_old_heredoc_file(t_redirect *r);
void			write_heredoc_line(int fd, char *line, t_list *env,
					int do_expand);
int				open_heredoc_file(const char *path);
// heredoc_child.c
void			heredoc_child_process(const char *raw_eof, const char *path,
					t_cleanup_ctx *ctx, int do_expand);
// heredoc_init.c
void			handle_heredoc_eof(char *clean_eof, int line_num,
					void (*exit_func)(int));
int				init_heredoc_child(t_heredoc_singleton *s, const char *raw_eof,
					const char *path, void (*exit_func)(int));
void			finish_heredoc_child(t_heredoc_singleton *s,
					t_cleanup_ctx *ctx);
// heredoc_child_utils.c
void			cleanup_singleton_files(t_heredoc_singleton *s);
void			cleanup_heredoc_ctx(t_cleanup_ctx *ctx);
int				fork_heredoc_child(const char *eof, const char *path,
					t_cleanup_ctx *ctx, int do_expand);
int				wait_heredoc_child(pid_t pid);
// heredoc_cleanup.c
int				find_last_heredoc_index(t_cmd *cmd);
void			delete_heredoc_file(char *file);
void			cleanup_heredoc_keep_last(t_cmd *cmd);
int				run_one_heredoc(t_redirect *r, t_cleanup_ctx *ctx);
/*---------------------EXPAND-------------------*/

t_expand_state	*init_expand_state(int respect_single_quotes);
int				append_char(t_expand_state *state, char c);
int				append_string(t_expand_state *state, char *str);
char			*finalize_expand_state(t_expand_state *state);
int				get_var_name_len(char *str);
int				expand_variable(t_expand_state *state, char *str,
					t_list *lst_env);
void			process_char(t_expand_state *state, char **str,
					t_list *lst_env);
int				expand(t_list **lst_cmd, t_list *lst_env);
char			*expand_heredoc_content(char *content, t_list *lst_env);
int				has_quotes(char *str);
char			*expand_heredoc_line(char *line, t_list *lst_env,
					int should_expand);
char			*get_env_value(char *var_name, t_list *lst_env);
char			*extract_var_name(char *str, int *len);
char			*expand_string(char *str, t_list *lst_env);
char			*expand_string_heredoc(char *str, t_list *lst_env);
int				expand_redirections(t_cmd *node_cmd, t_list *lst_env);
int				expand_command_args(t_cmd *node_cmd, t_list *lst_env);
int				handle_expand(t_prompt_state *state);

/*---------------------TRIM COMMANDS-------------------*/
int				trim_commands(t_list **lst_cmd);
char			*trim_string(char *str);
char			*trim_string_copy(char *str);
char			*trim_string_no_quotes(char *str);
char			*remove_quotes_and_trim(char *str);
void			trim_command_args(t_cmd *node_cmd);
void			trim_redirections(t_cmd *node_cmd);

// trim_cmd_internal.c
char			*remove_quotes_trim_internal(char *str, int *was_quoted);

// trim_cmd_utils.c
void			trim_whitespace(char *str, int *start, int *end);
void			append_trim_char(t_trim_state *state, char c);
int				process_trim_char(t_trim_state *state, char c);
t_trim_state	*init_trim_state(int capacity);

/*---------------------BUILTINS-------------------*/
int				is_builtin(char *cmd);
int				execute_builtin(t_cmd *node_cmd, t_list **lst_env,
					t_list **lst_cmd);
int				is_single_builtin(t_list *lst_cmd);
int				try_builtin_and_exit_if_ok(t_cmd *node_cmd, t_list **lst_env,
					t_list **lst_cmd);
int				echo(t_cmd *node_cmd);
int				cd(char **args, t_list **lst_env);
int				pwd(t_cmd *node_cmd);
int				export(t_cmd *node, t_list **lst_env);
int				env(t_cmd *node_cmd, t_list *lst_env);
int				unset(t_cmd *node, t_list **lst_env);
int				is_numeric_body_valid(char *arg, int sign);
int				exit_builtin(t_cmd *node_cmd, t_list **lst_env,
					t_list **lst_cmd);
int				export_print(t_list **lst_env);

/*---------------------EXECUTION-------------------*/
int				execute_command(t_list *lst_cmd, t_list **lst_env, char **tab,
					t_cleanup_ctx *ctx);
int				execute_pipeline(t_list *lst_cmd, t_list **lst_env, char **tab,
					t_cleanup_ctx *ctx);
int				execute_single_command(t_cmd *cmd, t_list *lst_env);

#endif
