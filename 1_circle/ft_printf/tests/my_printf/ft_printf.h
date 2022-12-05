/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:10:51 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:17:09 by gyoon            ###   ########.fr       */
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
	FT_FALSE,
	FT_TRUE
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
	t_flag	*flag;
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
char		*convert_precision(char *str, t_format *format);
char		*convert_prefix(char *str, t_format *format);
char		*convert_sign(char *str, t_format *format);
char		*convert_space(char *str, t_format *format);
char		*convert_left(char *str, t_format *format);
char		*convert_padding(char *str, t_format *format);

// utils
int			ft_isdot(int c);
int			ft_isflag(int c);
int			ft_ispercent(int c);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strtoupper(char *s);

// format
t_format	*ft_fmtnew(void);
void		set_flag(t_flag *flag, int c);
t_format	*get_fmtf(const char *fmt);
t_list		*get_fmtlstf(const char *fmt);

// toa
char		*ft_ctoa(int c);
char		*ft_ptoa(void *ptr);
char		*ft_vtoa(t_format *format, va_list args);
char		*ft_utoa(unsigned int u);
char		*ft_xtoa(unsigned int num);

// string
int			ft_strlstlen(t_list *strlst);
char		*vatoa(t_format *format, va_list args);
char		*get_strf(const char *fmt, t_format *format, va_list args);
t_list		*get_strlstf(const char *fmt, t_list *formats, va_list args);

int			get_skip_digit(const char *str);
void		prints(char *str);
int			ft_printf(const char *fmt, ...);

#endif
