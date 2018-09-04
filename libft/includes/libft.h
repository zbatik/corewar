/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:31:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/20 16:54:08 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include "get_next_line.h"
# include "colour.h"
# include "ft_lists.h"

typedef char	t_bool;

void	*ft_memset(void *b, int c, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *hay, const char *need, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
int		ft_strarrlen(char **arr);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);

int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isnumber(char *n);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_puterror(char *s);

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_max(int n, int m);
int		ft_min(int n, int m);
int		ft_abs(int n);
int		ft_element(char c, char const *str);
int		ft_isws(int c);
int		ft_countc(const char *s, char c);
int		ft_sign(int n);
void	ft_putstrarr(char **array);
int		ft_indexcin(char const *s, int c);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_strtake(char const *str, size_t n);
char	*ft_strdrop(char const *str, size_t n);
char	*ft_strctake(char const *str, char c);
char	*ft_strcdrop(char const *str, char c);
char	*ft_strreplace(char **replace, char *with);
char	**ft_arrnew(size_t x, size_t y);
void	ft_arrdel(char ***arr, int x);

#endif
