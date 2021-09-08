/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:25:57 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/08 16:35:45 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*sort_sign_width(char *tmp, t_option *option)
{
	if (option->zero == 1 && option->width != 0 && option->precision == -1)
	{
		if (option->width > 0)
		{
			if (option->sign == '-' || option->plus || option->empty)
				option->width -= 1;
			else if (option->sharp)
				option->width -= 2;
		}
		tmp = apply_width(tmp, option);
		tmp = apply_sign(tmp, option);
	}
	else
	{
		tmp = apply_sign(tmp, option);
		tmp = apply_width(tmp, option);
	}
	return (tmp);
}

int	combine_tag(char *tmp, t_option *option)
{
	int	ret;

	if (!tmp)
		return (-1);
	if (option->format == 'c' && option->width > 1
		&& option->sign == 1 && option->minus == 1)
		write (1, "\0", 1);
	if (option->format == 's')
		tmp = apply_precision_s(tmp, option->precision);
	else if (option->format == 'd' || option->format == 'i'
		|| option->format == 'X' || option->format == 'x'
		|| option->format == 'u')
		tmp = apply_precision(tmp, option);
	tmp = sort_sign_width(tmp, option);
	ret = reslut_len(tmp, option);
	write (1, tmp, ret);
	if (option->format == 'c' && option->width > 1
		&& option->sign == 1 && option->minus == 0)
		write (1, "\0", 1);
	if (option->format == 'c' && option->width > 1 && option->sign == 1)
		ret++;
	safe_free((void **)&(tmp));
	safe_free((void **)&(option));
	return (ret);
}

int	combine_ap(va_list ap, t_option *option)
{
	char	*tmp;
	int		ret;

	if (option->format == 'd' || option->format == 'i')
		tmp = ft_itoa(va_arg(ap, int), option);
	else if (option->format == 'x' || option->format == 'X'
		|| option->format == 'u' || option->format == 'p')
		tmp = unitoa_base(va_arg(ap, unsigned long long), option);
	else if (option->format == 's')
		tmp = stringtostring(va_arg(ap, char *));
	else if (option->format == 'c')
		tmp = chartostring(va_arg(ap, int), option);
	else
		tmp = ft_strdup("%");
	ret = combine_tag(tmp, option);
	return (ret);
}

int	parse_tag(const char **format, va_list ap, size_t *ret)
{
	t_option	*option;
	int			tmp;

	tmp = 0;
	option = malloc(sizeof(t_option));
	if (!option)
		return (0);
	init_option(option);
	(*format)++;
	while (record_option(**format, option))
		(*format)++;
	if (is_digit(**format))
		option->width = atoi_for_pf(format);
	if (**format == '.')
		option->precision = atoi_for_pf(format);
	option->format = is_format(**format);
	if (!check_error(option))
		return (-1);
	tmp = combine_ap(ap, option);
	if (tmp == -1)
		return (-1);
	*ret += tmp;
	(*format)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (parse_tag(&format, ap, &ret) == -1)
				return (-1);
			continue ;
		}
		write(1, format, 1);
		format++;
		ret++;
	}
	va_end(ap);
	return (ret);
}
