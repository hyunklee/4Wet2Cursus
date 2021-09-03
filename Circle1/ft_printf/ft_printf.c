/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:25:57 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/04 01:24:05 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		combine_tag(char *tmp, t_option *option)
{
	int ret;

	if (option->format == 's')
		tmp = apply_precision_s(tmp, option->precision);
	else
		tmp = apply_precision(tmp, option->precision);
	tmp = apply_sign(tmp, option);
	tmp = apply_width(tmp, option);
	ret = ft_len(tmp);
	write (1, tmp, ret);
	safety_free(tmp);
	safety_free(option);
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
	else
		tmp = va_arg(ap, char *);
	ret = combine_tag(tmp, option);
	return (ret);
}


int     parse_tag(const char **format, va_list ap, size_t *ret)
{
	t_option	*option;

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
			if (*(format + 1) == '%')
			{
				write(1, "%", 1);
				return (1);
			}
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