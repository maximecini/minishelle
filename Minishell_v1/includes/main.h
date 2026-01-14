/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:35:16 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:36:28 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "../libft/include/libft.h"
# include "define.h"
# include "struct.h"
# include "utils.h"

/*---------------------------------------EXEC------------------------------*/
int					execution(t_element *lst_cmd, t_element **lst_env);
void				wait_for_children(t_exec *exec);
void				handle_status(int status);
void				wait_and_finalize(t_exec *exec, t_element *lst_cmd);
void				handle_signals_for_parent(void);
int					setup_execution(t_exec *exec, t_element *lst_cmd,
						t_element **lst_env);
void				process_command(t_exec *exec, t_node_cmd *node_cmd,
						t_element **lst_env, t_element **lst_cmd);
/*---------------------------------------HANDLER------------------------------*/

void				handle_sigint(int a);
void				handle_sigint_heredoc(int a);

/*---------------------------------------ENV------------------------------*/
t_element			*envp_lst(char **envp);
char				**envp_copy(char **envp);
void				print_env(t_element *envp);

/*---------------------------------------BULTIN------------------------------*/
void				export_env_var(t_element **envp_lst, char *key,
						char *value);
int					execute_builtin(t_node_cmd *node_cmd, t_element **lst_env,
						t_element **lst_cmd);
char				*get_env(char *key, t_element *envp_lst);
int					export(t_node_cmd *node, t_element **lst_env);
int					cd(char **args, t_element **lst_env);
int					pwd(void);
int					echo(t_node_cmd *node_cmd);
int					env(t_element *lst_env);
int					unset(t_node_cmd *node_cmd, t_element **lst_env);
int					try_builtin_and_exit_if_ok(t_node_cmd *node_cmd,
						t_element **lst_env, t_element **lst_cmd);
int					is_single_builtin(t_element *lst_cmd);
int					exec_single_builtin(t_exec *exec, t_node_cmd *node_cmd,
						t_element **lst_env, t_element **lst_cmd);

/*---------------------------------------PARSER------------------------------*/
t_redirection_type	get_redirection_type(char *str);
t_redirect			*check_redirect(char *str, int *count);
int					count_redirects(char *str);
int					is_double_redirect(char *line);
int					is_simple_redirect(char *line);
char				*get_completed_line(char *line, char quote);
void				print_redirects(t_redirect *redir, int count);
t_element			*build_command_list(char *line, t_element **node_lst);
t_element			*build_command_list(char *line, t_element **node_lst);
int					expand(t_element *lst_cmd, t_element **lst_env);

/*---------------------------------------ERRORS------------------------------*/
int					print_syntax_error(char *token);
int					has_syntax_error(char *input);
/* Helper functions for error lexer */
void				init_syntax_state(t_syntax_state *state);
int					should_skip_char(char *input, t_syntax_state *state);
int					process_token(char *input, t_syntax_state *state);
int					error(char *builtin, char *message, char *token);
void				error_cmd(int error, char *cmd);
void				error_file(int error, char *file);
void				print_error(char *str);
/*---------------------------------------PRINTS------------------------------*/
void				print_lst_env(t_element *lst_env);
void				print_arr_env(char **new_env);
int					print_syntax_error_export(char *token, int error);
void				print_command_list_full(t_element *lst_cmd);
void				get_path(t_exec *exec, char **env);

/*---------------------------------------signaux------------------------------*/
void				handle_sigquiy(int a);
void				handle_sigint_parent(int sig);
void				handle_status(int status);
/*---------------------------------------signaux------------------------------*/
int					exit_builtin(t_node_cmd *node_cmd, t_element **lst_env,
						t_element **lst_cmd);
/*---------------------------------------signaux------------------------------*/
void				child_read_heredoc(t_heredoc_data *data);
char				*process_single_expansion(char **arg, char **temp,
						t_element **lst_env);
char				*extract_env_var_name(char *str);
char				*replace_variable_in_string(char *input, char *var_name,
						char *value);
int					cmp_key(void *a, void *b);

char				*extract_env_var_name_from(char *start);

char				*clean_line(const char *line, int in_single_quote,
						int in_double_quote, size_t write_index);
int					create_command_node(char *cmd, t_element **node_lst,
						int nb_redirect, t_redirect *redirect);
int					get_quote_context(char *str, int pos);
char				*replace_variable_in_string(char *input, char *var_name,
						char *value);
int					is_operator_invalid(char *input, int pos, char *operator,
						int operator_len);

int					read_heredoc_fork(t_redirect *redirect, t_element **lst_cmd,
						t_element **lst_env);

void				set_heredoc_data(t_heredoc_data *data);
t_heredoc_data		**get_heredoc_data(void);
void				free_heredoc_data(t_heredoc_data *heredoc_data);
void				heredoc_sigint_handler(int sig);
int					is_delimiter_reached(char *line, char *delim, size_t l_arg);
void				write_line_to_heredoc(t_heredoc_data *heredoc_data);
void				read_and_write_heredoc_loop(t_heredoc_data *heredoc_data);

#endif
