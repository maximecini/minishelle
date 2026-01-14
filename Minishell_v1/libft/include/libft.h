/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:41:13 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/01 12:19:45 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <bsd/string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# define FD_MAX 1024
/******************************/
/*         DEF FORMAT          */
/*******************************/
# define CHAR 'c'
# define STRING 's'
# define DECIMAL 'd'
# define INTEGER 'i'
# define U_INTEGER 'u'
# define HEX_LOWER_ 'x'
# define HEX_UPP 'X'
# define POINTER 'p'
# define PERCENT '%'
/*******************************/
/*         base        */
/*******************************/
# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_UPP "0123456789ABCDEF"
# define BASE_DEC "0123456789"

typedef struct s_element
{
	void				*content;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

int						ft_isalpha(int letter);
int						ft_isdigit(int nb);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
void					*ft_memset(void *s, int c, size_t n);
size_t					ft_strlen(const char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strchr(const char *string, int searchedChar);
char					*ft_strrchr(const char *string, int searchedChar);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *p1, const void *p2, size_t size);
char					*ft_strnstr(const char *str, const char *search,
							size_t size);
char					*ft_strstr(char *str, char *to_find);
long					ft_atoi(const char *str);
size_t					ft_digitlen(long long n, int size);
void					*ft_calloc(size_t s, size_t size_of);
char					*ft_strdup(const char *source);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char *s1, char *s2, int f1, int f2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
void					ft_itoa_to_buf(int n, char *buf);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
int						ft_putnbr_fd(int n);
int						ft_strcmp(char *s1, char *s2);
t_element				*ft_lstnew(void *content);
void					ft_lstadd_front(t_element **lst, t_element *new);
int						ft_lstsize(t_element *lst);
t_element				*ft_lstlast(t_element *lst);
void					ft_lstadd_back(t_element **lst, t_element *new);
void					ft_lstdelone(t_element *lst, void (*del)(void *));
void					ft_lstclear(t_element **lst, void (*del)(void *));
void					ft_lstiter(t_element *lst, void (*f)(void *));
t_element				*ft_lstmap(t_element *lst, void *(*f)(void *),
							void (*del)(void *));
size_t					ft_base_power(long long s, int size_base);
int						ft_istouppercase(int c);
int						ft_islowercase(int c);
size_t					ft_putnbr_base(int nbr, char *base);
int						ft_display_base(size_t number, char *str, void f(size_t,
								char *, int *));
int						ft_display_string(void *str, void (*f)(char *, int));
long					valide_base(char *base);
int						ft_int_isdigit(int n);
int						ft_printf(const char *format, ...);
char					ft_todigits(int n);
int						ft_count_word(char const *str, char ch);
void					ft_shift_argv(int *arc, char **argv, int nb);
void					ft_sort_int_tab(int *tab, int size);
int						ft_tab_is_sort(int *tab, int size);
int						*ft_intdup(int *arryint, int size);
char					**ft_free_split(char **tab);
char					*get_next_line(int fd, char c);
int						ft_atoi_base(char *str, char *base);
void					ft_strtolower(char *str);
char					*ft_strcat(char *dest, char *src);
void					print_bits(unsigned char octet);
char					**copy_string_array(char **src, int count);
int						ft_array_len(char **tab);
char					**ft_sort_tab_str(char **dbtab);
t_element				*ft_lstcpy(t_element *lst, void (*del)(void *));
void					print_tab_str(char **str);
char					*ft_strcpy(char *dest, const char *src);

#endif
