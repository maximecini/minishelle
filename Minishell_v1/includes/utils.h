/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:22:56 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/07/31 19:38:35 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../libft/include/libft.h"
# include "define.h"
# include "struct.h"

/*---------------------------------------REDIRECT----------------------------*/
int			is_redirection_to_skip(const char *line, size_t *read_pos);
int			is_redirection_valid(char *str, int index, int in_single_quote,
				int in_double_quote);
int			count_redirects(char *str);
int			process_redirections(t_exec *exec, t_node_cmd *node_cmd);

/*---------------------------------------STRING----------------------------*/
char		*ft_replace_char(char *str, char search, char *replace);
char		*ft_replace_str(char *str, char *search, char *replace);
char		*ft_replace_auto(char *str, char *search, char *replace);
void		update_quote_state(char c, int *in_single, int *in_double);
void		ft_swap_alpha(char **s1, char **s2);
void		skip_spaces(char *str, int *pos);
int			is_unquoted(char c, int sq, int dq, char sep);
int			skip_whitespace(char *str, int i);
int			is_quote_to_skip(char c, int in_single, int in_double);
int			is_sep(char c);
char		*extract_word(const char *str);
int			is_in_dquote(const char *s);
char		*sanitize_word_quotes(const char *str, size_t len);
int			is_whitespace(char c);
int			is_quote(char c);
int			check_unclosed_quotes(char *line);
char		*identify_operator(const char *input, int index);
char		*process_quotes(char *str);

/* Helper functions for word processing */
void		append_char_once(char *dst, const char *src, t_char_copy *copy);
void		init_quote_state(t_quote_state *state);
void		process_quote_to_skip(const char *str, t_quote_state *state);
void		process_normal_char(const char *str, char *word,
				t_quote_state *state);

/*---------------------------------------EXEC--------------------------*/
int			acces_cmd(char *cmd);
void		close_pipe(int pipe, int condition);
void		read_heredoc(t_redirect *redirect);
void		prepare_heredocs(t_element *lst_cmd, t_element **lst_env);
void		ft_dup(int fd, int output, int file);
/*---------------------------------------FREE----------------------------*/
void		free_commands(char **commands);
void		free_list(t_element *node_lst);
void		free_redirects(t_redirect *redirec, int nb);
void		free_node_cmd_content(void *content);
void		free_node_env_content(void *content);
void		free_list_custom(t_element *lst, void (*free_content)(void *));
void		free_list(t_element *node_lst);
/*---------------------------------------AUTRES------------------------------*/

void		append_char_preserve_quotes(char *dst, const char *src,
				t_char_copy *copy);
void		ft_sort_lst(t_element *head, int (*cmp)(void *, void *));
void		sort_env(char **env);
int			open_file_wtc(char *filename, int access);
int			ft_env(t_element *node_lst, t_element **env);
int			only_space(char *s);
int			special_case(char **cmd);
int			get_error_export(char *cmd);
int			update_nodes_env(t_element *lst_env, char *key, char *new_value,
				char *equal);
int			cpy_tab_to_lst(t_element **lst_env, char **env);
int			exec_cmd(char *line, char **envp);
int			process_heredocs(t_element *node_lst);
int			cmp_key(void *a, void *b);
int			get_error_export(char *cmd);
int			add_back_nodes_env(t_element **lst_env, char *cmd, int add);
int			export_no_valide(char *cmd, char *key, size_t siz_key);
char		**split_smart(const char *input, char sep);
char		*copy_trimmed_segment(const char *input, size_t start, size_t end);
char		*read_multiline_if_needed(char *initial_line, char quote_type);
char		*prompt_and_read_line(void);
char		*create_path(char *pwd, char *dst);
char		expand_variable(t_element *node_lst, t_element **env);
char		*get_key(char *s);
char		*get_value(char *s);
char		*get_key(char *s);
t_element	**get_lst_key(t_element **lst_env, char *key);
int			count_lst(t_element *lst_cmd);
char		**cpy_lst_to_tab(t_element *lst_env);
int			get_infile(t_exec *exec, t_redirect *redirect);
char		*create_temp_filename(void);

int			check_command_valid(t_node_cmd *node_cmd);
void		check_command_valid_or_exit(t_node_cmd *node_cmd,
				t_element **lst_env, t_element **lst_cmd);
void		execute_external_command(t_exec *exec, t_node_cmd *node_cmd,
				t_element **lst_env, t_element **lst_cmd);
void		cleanup_and_exit(t_exec *exec, t_element **lst_env,
				t_element **lst_cmd, int exit_code);
void		exec_all_commands(t_exec *exec, t_element *lst_cmd,
				t_element **lst_env);
void		close_unused_fds(t_exec *exec, int i);
void		exec_child_process(t_exec *exec, t_node_cmd *node_cmd, int i,
				t_element **lst_env);
void		execve_or_exit(char *e_path, t_node_cmd *cmd, t_element env);

char		*resolve_executable_or_exit(t_exec *exec, t_node_cmd *node_cmd,
				char **env);
/*---------------------------------------PIPE------------------------------*/
void		close_pipe(int pipe, int condition);
int			setup_pipes(t_exec *exec);

int			fork_and_manage_pipe(t_exec *exec, int i);
/*---------------------------------------PATH------------------------------*/
char		*get_path_cmd(t_exec *exec, char *cmd);
char		*is_exec(t_exec *exec, char **cmd);
char		*is_no_path(char *cmd);
/*---------------------------------------INIT------------------------------*/
int			initialise_exec(t_exec *exec, t_element *lst_cmd);

int			open_and_redirect(const char *filename, int flags, int dup_fd,
				const char *err_ctx);
int			is_builtin(char *cmd);

/*---------------------------------------SIGNAUX------------------------------*/
void		handle_sigint_multiline(int sig);

int			handle_redir(char *str, int *pos, t_redirect *r,
				t_redirection_type type);
int			find_next_redir(char *str, int start, t_redirection_type *type);
int			count_lst_valide(t_element *lst_cmd);
char		*extract_env_var_name(char *str);
int			cmp_key(void *a, void *b);
int			str_is_space(char *str);
int			acces_file(char *cmd);
int			is_point(char *line);
void		free_lst(t_element **lst_env, t_element **lst_cmd);
#endif
