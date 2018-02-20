/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:15:14 by dborysen          #+#    #+#             */
/*   Updated: 2017/11/26 11:39:59 by dborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_help
{
	char			*entr_str;
	int				fd;
	struct s_help	*next;
}					t_help;

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_isdigit(int c);
int					ft_isalpha(int ch);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *str);
void				ft_shwlst(t_list *alst);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *destptr, const char *srcptr);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncat(char *destptr, const char *srcptr, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strstr(const char *big, const char *lit);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
unsigned int		ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putendl(char const *s);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_shwlst(t_list *alst);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_addlst(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_reverse(char *str);
int					ft_countw(char const *s, char c);
int					ft_isvalid(char *s);
int					ft_ispower(int x);
int					ft_reverse_bits(unsigned char octet);
char				*ft_itoa_base(unsigned long long v, int base);
char				*ft_lowstr(char *s);
unsigned int		ft_putlonglong(long long n);
unsigned int		ft_putllu(unsigned long long n);
int					get_next_line(const int fd, char **line);
int					ft_count_digit_u(unsigned long long n);

#endif
