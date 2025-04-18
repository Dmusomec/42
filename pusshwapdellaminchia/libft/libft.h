/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:44:14 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/18 19:11:29 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"
# define BASE10 "0123456789"
# define BUFFER_SIZE 1

void	ft_putstr(char *str, size_t *counter);
void	ft_putbase(const char *str, unsigned long num, size_t *counter);
void	ft_hexpt(void *point, size_t *counter);
void	ft_putnbrfd(int n, int fd, size_t *counter);
void	ft_putchar(char c, size_t *counter);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *puntero, size_t numero);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *pegar, const void *copiar, size_t numero);
void	*ft_memmove(void *pegar, const void *copiar, size_t numero);
void	*ft_memset(void *puntero, int valor, size_t numero);
char	*ft_strchr(const char *origen, int car);
size_t	ft_strlcat(char *pegar, const char *copiar, size_t numero);
size_t	ft_strlcpy(char *pegar, const char *copiar, size_t numero);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*fstrnstr(const char *big, const char *little, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strchr_str(const char *str, const char *allow);
char	*ftt_cutit(char *statik);
char	*givememyline(char *statik);
char	*readline(int fd, char *statik);
char	*get_next_line(int fd);
size_t	ftt_strlen(const char *s);
void	*ftt_calloc(size_t nmb, size_t size);
char	*ftt_strchr(const char *origen, int car);
char	*ftt_strjoin(char *s1, char *s2);
long	ft_atol(const char *str);

#endif