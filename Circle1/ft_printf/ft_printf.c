/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 02:38:38 by hyunklee          #+#    #+#             */
/*   Updated: 2021/08/17 17:32:29 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		combine_tag(char *tmp, t_option *option)
{
	int ret;

	tmp = apply_precision(tmp, option->format, option->precision);
	tmp = apply_sign(tmp, option);
	tmp = apply_width(tmp, option);
	ret = ft_strlen(tmp);
	write (1, tmp, ret);
	return (ret);
}

int		combine_ap(va_list ap, t_option *option)
{
	char	*tmp;
	int		ret;

	if (option->format == 'd' || option->format == 'i' ||
	 option->format == 'x' || option->format == 'X')
	{
		tmp = itoa_base(va_arg(ap, int), option->format);
		if (tmp[0] == '-')
		option->sign = '-';
	}
	else if (option->format == 'p')
		tmp = memtoa(va_arg(ap, char *));
	else if (option->format == 'u')
		tmp = unittoa(va_arg(ap, unsigned int));
	else if (option->format == 's')
		tmp = va_arg(ap, char *);
	else if (option->format == 'c')
		tmp = va_arg(ap, char *);
	else if (option->format == '%')
		write(1, "%", 1);
	ret = combine_tag(tmp, option);
	return (ret);
}
int		record_option(const char c, t_option *option)
{
	if (c == '-')
		option->minus = 1;
	else if (c == '#')
		option->sharp = 1;
	else if (c == '+')
		option->plus = 1;
	else if (c == '0')
		option->zero = 1;
	else if (c == ' ')
		option->empty = 1;
	else
		return (0);
	return (1);
}

int		atoi_for_pf(const char **format)
{
	long long temp;
	int       ret;

	temp = 0;
	if (**format == '-')
		return (0);
	while (is_digit(**format))
	{
		temp *= 10;
		temp += **format - '0';
		(*format)++;
	}
	ret = (int)temp;
	return (ret);
}

int		check_error(t_option *option)
{
	if (!option->format || !option->width)
		return (-1);
	if (option->format == 'c' && option->format == 'p')
		option->precision = -1;
	if (option->empty && option->plus)
		option->empty = 0;
	if (option->zero && option->minus)
		option->zero = 0;
	return (1);
}

int     parse_tag(const char **format, va_list ap, size_t *ret)
{
	t_option	*option;

	option = malloc(sizeof(t_option));
	if (!option)
	return (0);
	init_option(option);
	(*format)++;
	if (**format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	while (record_option(**format, option))
		(*format)++;
	if (is_digit(**format))
		option->width = atoi_for_pf(format);
	if (**format == '.')
	{
		(*format)++;
		option->precision = atoi_for_pf(format);
	}
	option->format = is_format(**format);
	if (!check_error(option))
		return (0);
	*ret += combine_ap(ap, option);
	(*format)++;
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	size_t  ret;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if(!parse_tag(&format, ap, &ret))
				return (-1);
		}
		write(1, format, 1);
		format++;
		ret++;
	}
	va_end(ap);
	return (ret);
}

int main(void)
{
    char a[10] = "abcdef";
    ft_printf("{%20.15d}",-2147483647);
	printf("{%20.15d}",-2147483647);
}