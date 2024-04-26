/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:47:23 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/12 15:11:51 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef unsigned char	t_byte;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void				ft_putchar(char c);
int					ft_print_char(int c);
char				*ft_itoa(int n);
int					ft_print_int(int n);
int					ft_print_hex(unsigned int n, const char c);
int					ft_print_uint(unsigned int n);
int					ft_print_str(char *str);
int					ft_print_ptr(unsigned long long ptr);
int					ft_printf(const char *str, ...);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isdigit_str(char *str);
int					ft_isalphanum_str(char *str);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_new(char *s1, char *s2, int f1, int f2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				**ft_split(char const *s, char c);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t				ft_strlen(const char *s);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char				*get_next_line(int fd);
char				*get_line(char *str);
char				*getrid_old_line(char *str);
char				*ft_strchr_gnl(char *s, int c);
char				*ft_strjoin_gnl(char *s1, char const *s2);
long long			ft_atoll(const char *str);
unsigned long long	ft_atoull(const char *str);
char				*ft_itob(int n);
void				ft_free_char_array(char **array, int freecont);

#endif