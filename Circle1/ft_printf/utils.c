/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 00:53:07 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/07 23:34:11 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	safe_free(void **ptr)
{
	if (ptr != 0 && *ptr != 0)
	{
		free(*ptr);
		*ptr = 0;
	}
}

void	init_option(t_option *option)
{
	option->format = 0;
	option->plus = 0;
	option->zero = 0;
	option->minus = 0;
	option->precision = -1;
	option->width = 0;
	option->sharp = 0;
	option->empty = 0;
	option->sign = 0;
}

int	check_error(t_option *option)
{
	if (!option->format || !option->width)
		return (-1);
	if (option->empty && option->plus)
		option->empty = 0;
	if (option->zero && option->minus)
		option->zero = 0;
	if (option->format == 'p' || option->format == 'c' || option->format == '%')
	{
		if (option->precision != -1)
			return (-1);
	}
	return (1);
}

int	atoi_for_pf(const char **format)
{
	long long	temp;
	int			ret;

	temp = 0;
	if (**format == '.')
	{
		(*format)++;
		if (!is_format(**format) || **format == '-')
			return (0);
	}
	while (is_digit(**format))
	{
		temp *= 10;
		temp += **format - '0';
		(*format)++;
	}
	ret = (int)temp;
	return (ret);
}

int	record_option(const char c, t_option *option)
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
