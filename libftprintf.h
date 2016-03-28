/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:07:41 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/28 17:57:54 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

typedef struct s_data
{
	wchar_t			c_spe;
	wchar_t			*s_spe;
	int				c;
	const char		*s;
}					s_data;

int					ft_higher(int a, int b);
int					ft_printf(char *str, ...);
int					ft_wstrlen(wchar_t *str);
int					get_max_char(s_data s, int *tab);
void				ft_get_code(int base, long long int arg);
void				ft_get_first_char(char **s, char *flag);
int					ft_power(int n, int puiss);
int					ft_strcount(const char *s, char b);
int					ft_strlen_char(const char *s, char b);
void				ft_putnb_base(long long int nb, char *base);
int					ft_nb_len_base(long long int n, int base);
void				ft_get_opt(char **s, char *flag, int *tab);
void				final_check(char *flag, int *tab);
void				ft_get_last_char(char **s, char *flag);
long long int		get_int_flagged(va_list va, char c, char d);
void				get_arg(va_list va, char *flag, int *tab, s_data s);
long long int		get_arg_nb(va_list va, char c, char *flag);
long long int		get_uint_flagged(va_list va, char c, char d);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *str, int n);
void				do_wrd(char *flag, int *tab, s_data s);
void				do_nb(char *flag, int *tab, long long int arg);
void				print_beg(char *flag, int *tab, int max_char, long long int arg);
int					ft_atoi(char *str);
void				ft_print_n_char(char c, int n);
int					ft_base_10(char *str, char *base);
int					get_total_char(long long int arg, char *flag, int *tab);
void				ft_bzero(void *s, size_t n);
int					ft_get_char(char *s, char c);
char				*ft_itoa(int n);
int					ft_max(int *tab, int size);
int					ft_min(int *tab, int size);
void				ft_putchar(char c);
void				ft_putchar_fd(char d, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *s, int n);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s1, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *c));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strrchr(const char *s1, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
