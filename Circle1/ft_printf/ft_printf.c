/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:25:57 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/06 02:13:28 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	combine_tag(char *tmp, t_option *option)
{
	int	ret;

	if (!tmp)
		return (-1);
	if (option->format == 's')
		tmp = apply_precision_s(tmp, option->precision);
	else
		tmp = apply_precision(tmp, option->precision);
	tmp = apply_sign(tmp, option);
	tmp = apply_width(tmp, option);
	ret = reslut_len(tmp, option->format);
	write (1, tmp, ret);
	safe_free((void **)&(tmp));
	safe_free((void **)&(option));
	return (ret);
}

int	combine_ap(va_list ap, t_option *option)
{
	char	*tmp;
	int		ret;
	
	if (option->format == 'd' || option->format == 'i')
	{
		tmp = ft_itoa(va_arg(ap, int));
		if (tmp[0] == '-')
			option->sign = '-';
	}
	else if (option->format == 'x' || option->format == 'X' || option->format == 'u' || option->format == 'p')
		tmp = unitoa_base(va_arg(ap, unsigned long long), option->format);
	else if (option->format == 's')
		tmp = stringtostring(va_arg(ap, char *));
	else if (option->format == 'c')
		tmp = chartostring(va_arg(ap, int));
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
			continue;
		}
		write(1, format, 1);
		format++;
		ret++;
	}
	va_end(ap);
	return (ret);
}
