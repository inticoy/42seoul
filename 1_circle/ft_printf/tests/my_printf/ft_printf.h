/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:10:51 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/13 15:36:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

typedef enum e_bool
{
	ft_false,
	ft_true
}	t_bool;

typedef struct s_flag
{
	t_bool	left;
	t_bool	sign;
	t_bool	space;
	t_bool	prefix;
	t_bool	zero;
}	t_flag;

typedef struct s_format
{
	int		len;
	t_flag	flag;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

typedef struct s_string
{
	char	*str;
	int		len;
	int		size;
}	t_string;

// convert
char		*convert_padding(char *str, t_format format);
char		*convert_precision(char *str, t_format format);
char		*convert_prefix(char *str, t_format format);
char		*convert_sign(char *str, t_format format);
char		*convert_space(char *str, t_format format);

// flag
t_flag		init_flag(void);
t_bool		need_padding(char *str, t_format format);
t_bool		need_precision(t_format format);
t_bool		need_prefix(t_format format);
t_bool		need_sign(t_format format);
t_bool		need_space(t_format format);
t_flag		update_flag(t_flag flag, int c);

// format
t_format	get_formatf(const char *fmt);
t_format	init_format(void);

// string
char		*get_strf(const char *fmt, t_format format, va_list *args);
t_list		*get_strlstf(const char *fmt, va_list *args);

// toa
char		*ft_ctoa(int c);
char		*ft_ptoa(void *ptr);
char		*ft_vtoa(char specifier, va_list *args);
char		*ft_utoa(unsigned int u);
char		*ft_xtoa(unsigned int num);

// utils
void		ft_bspace(void *s, size_t n);
void		ft_free_s(void *ptr);
int			ft_isdot(int c);
int			ft_isflag(int c);
int			ft_isnumfs(int c);
int			ft_isminus(int c);
int			ft_ispercent(int c);
int			ft_isplus(int c);
int			ft_isstrfs(int c);
int			ft_iszero(int c);
int			ft_strlstlen(t_list *strlst);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strtoupper(char *s);

// ft_printf
int			get_skip_digit(const char *str);
void		prints(char *str);
int			ft_printf(const char *fmt, ...);

#endif
