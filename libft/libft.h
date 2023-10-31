/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <@marvin>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:52:29 by fmartini          #+#    #+#             */
/*   Updated: 2023/10/13 17:25:21 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	flood_fill(char **tab, t_point size, t_point begin);
char	*ft_strjoin_free(char *str, char *buff);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *big, char *little, size_t len);
char	*ft_strrchr(char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
char	*ft_strtrim(char *s1, char *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t size);
char	*ft_strdup_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *s);
void	ft_check_class(char str, va_list l, int *n);
void	ft_put_hex(unsigned int num, const char str, int *n);
void	ft_point(unsigned long schif, int *n, const char str);
void	ft_putchar(int c, int *n);
void	ft_putstr(char *str, int *n);
void	ft_putnbr(int nbr, int *n);
void	ft_putnbr_s(unsigned int nbr, int *n);
int		ft_hex_len(unsigned	int num);
int		ft_print_hex(unsigned int num, const char str, int *n);
int		ft_put_point(unsigned long schiff, const char str, int *n);
int		ft_printf(const char *str, ...);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strstr(char	*haystack, char	*needle);

typedef struct s_list
{
	int				content;
	int				pos;
	int				chunk;
	struct s_list	*next;
}			t_list;

t_list	*ft_lstnew(int content);
int		ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
