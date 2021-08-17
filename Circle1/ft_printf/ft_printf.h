/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 02:38:35 by hyunklee          #+#    #+#             */
/*   Updated: 2021/08/17 17:31:46 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE "0123456789ABCDEF"
# define FORMAT "cspdiuxX"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // 지우셈
# include <stdarg.h>

typedef struct	s_option
{
	char		format;
	int			plus;
	int			zero;
	int			minus;
	int			precision;
	int			width;
	int			sharp;
	int			empty;
	char		sign;
}				t_option;

int				ft_printf(const char *format, ...);
int				combine_tag(char *tmp, t_option *option);
int				combine_ap(va_list ap, t_option *option);
int				record_option(const char c, t_option *option);
int				atoi_for_pf(const char **format);
int				check_error(t_option *option);
int				parse_tag(const char **format, va_list ap, size_t *ret);
size_t			ft_strlen(const char *s);
char			*ft_itoa(int n);
char			*itoa_base(int n, char format);
int				count_number(long n, int base_num);
char			*unittoa(unsigned int n);
char			*memtoa(void *mem);
void			init_option(t_option *option);
char			is_format(const char c);
char			is_digit(const char c);
char			*ft_strjoin(char *s1, char *s2);
char			*apply_precision(char *tmp, char format, int precision);
char			*apply_sign(char *tmp, t_option *option);
char			*apply_width(char *tmp, t_option *option);
#endif