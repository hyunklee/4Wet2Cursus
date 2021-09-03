/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:26:07 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/04 01:01:22 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE "0123456789ABCDEF"
# define FORMAT "cspdiuxX"
# define safety_free(p) safe_free((void **)&(p))

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

int		ft_printf(const char *format, ...);
int		combine_tag(char *tmp, t_option *option);
int		combine_ap(va_list ap, t_option *option);
int     parse_tag(const char **format, va_list ap, size_t *ret);
int		count_number(long n, int base_num);
char	*memtoa(void *mem);
char	*unittoa(unsigned int n);
char	*change_to_str(long n, int base_num, char format);
char	*itoa_base(int n, char format);
char	*apply_precision(char *tmp, int precision);
char	*apply_precision_s(char *tmp, int precision);
char	*apply_sign(char *tmp, t_option *option);
char	*apply_width(char *tmp, t_option *option);
char	is_format(const char c);
char	is_digit(const char c);
int     ft_len(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
void	safe_free(void **ptr);
void	init_option(t_option *option);
int		check_error(t_option *option);
int		atoi_for_pf(const char **format);
int		record_option(const char c, t_option *option);

#endif