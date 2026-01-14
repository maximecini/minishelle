/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-bail <sle-bail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:08:50 by sle-bail          #+#    #+#             */
/*   Updated: 2025/10/16 22:52:41 by sle-bail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*---------------------QUOTE-------------------*/
int		size_quotes(char *line, int j);
int		check_quotes(char *line);
int		get_quote_error(char *line);
int		is_quote(char c);
void	update_quote_state(char c, int *in_single, int *in_double);
/*---------------------TOKENISATION-------------------*/
int		copy_word(int size_words, char *line, char **ret, int j);
void	ft_free_split(char **split);
/*--------------------PARSING-------------------*/
int		free_all(t_list **lst_token, char **tab, char *line);
int		ft_str_is_printable(char *str);
/*---------------------SMART_SPLIT-------------------*/
typedef struct s_split_state
{
	int	*index;
	int	*cursor;
	int	*word_size;
}t_split_state;

char	**smart_split(char *line);
int		is_metachar(char c);
int		is_double_metachar(char *line, int j);
void	count_metachar(char *line, int *j, size_t *i, size_t *trigger);
int		copy_metachar(char *line, char **ret, int j);
int		handle_quotes(char *line, int *size_words, int *j);
int		handle_space(char *line, char **ret, t_split_state *state);
int		handle_metachar(char *line, char **ret, t_split_state *state);
int		handle_word_before_meta(int size_words, char *line, char **ret,
			t_split_state *state);
// smart_split_helpers.c
void	process_count_char(char *line, int *j, size_t *i, size_t *trigger);
char	**process_write_loop(char **ret, char *line, t_split_state *state,
			int *size_words);
char	**finalize_write(char **ret, char *line, int i, int params[2]);
/*---------------------LST-------------------*/
int		fill_lst_node(t_list **lst_token, t_cmd **node_cmd);
void	next_cmd_lst(t_list **lst_token);
/*---------------------STRING-------------------*/
int		is_redirection(int c);
/*---------------------ENV-------------------*/

int		cmp_key(void *a, void *b);
char	*get_key(char *s);
char	*get_value(char *s);
int		add_back_nodes_env(t_list **lst_env, char *cmd, int add);
void	ft_sort_lst(t_list *head, int (*cmp)(void *, void *));
void	print_lst_env(t_list *lst_env);
int		get_error_export(char *cmd);
t_list	**get_lst_key(t_list **lst_env, char *key);
char	*get_env_name(char *start);
char	*get_env_var_start(char *str);
char	*extract_env_var_name(char *str);
int		update_nodes_env(t_list *lst_env, char *key, char *new_value,
			char *equal);
int		ft_array_len(char **tab);

/*---------------------FREE-------------------*/
void	free_node_env_content(void *content);
/*---------------------SIGNAUX-------------------*/
void	handle_sigint_parent(int sig);
void	cleanup_iteration(t_prompt_state *state);
#endif
