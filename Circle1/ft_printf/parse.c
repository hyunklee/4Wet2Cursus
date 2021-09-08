/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 00:50:03 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/08 16:31:47 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(char *tmp, t_option *option)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_len(tmp);
	i = 0;
	if (option->sign == '0' && option->precision == 0)
	{
		safe_free((void **)&tmp);
		return (ft_strdup(""));
	}
	if (len < option->precision)
	{
		len = option->precision - len;
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (!ret)
			return (0);
		while (i < option->precision - ft_len(tmp))
			ret[i++] = '0';
		ret[i] = 0;
		tmp = ft_strjoin(ret, tmp);
	}
	return (tmp);
}

char	*apply_precision_s(char *tmp, int precision)
{
	char	*ret;
	int		i;

	i = 0;
	if (precision < 0)
		return (tmp);
	if ((ft_len(tmp) > precision) && tmp)
	{
		ret = (char *)malloc(sizeof(char) * (precision + 1));
		if (!ret)
			return (0);
		while (i < precision)
		{	
			ret[i] = tmp[i];
			i++;
		}
		ret[i] = 0;
		free(tmp);
		return (ret);
	}
	return (tmp);
}

char	*apply_sign(char *tmp, t_option *option)
{
	if (!tmp)
		return (0);
	if (option->format == 'd' || option->format == 'i')
	{
		if (option->sign != '-')
		{
			if (option->empty)
				tmp = ft_strjoin(ft_strdup(" "), tmp);
			else if (option->plus)
				tmp = ft_strjoin(ft_strdup("+"), tmp);
		}
		else if (option->sign == '-')
			tmp = ft_strjoin(ft_strdup("-"), tmp);
	}
	else if (option->format == 'x' && option->sharp && option->sign != '0')
		tmp = ft_strjoin(ft_strdup("0x"), tmp);
	else if (option->format == 'X' && option->sharp && option->sign != '0')
		tmp = ft_strjoin(ft_strdup("0X"), tmp);
	return (tmp);
}

char	*apply_width(char *tmp, t_option *option)
{
	int		len;
	char	*ret;

	len = reslut_len(tmp, option);
	if (len < option->width)
	{
		len = option->width - len;
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (!ret)
			return (0);
		fill_width(ret, option, len);
		if (option->minus)
			ret = ft_strjoin(tmp, ret);
		else
			ret = ft_strjoin(ret, tmp);
		return (ret);
	}
	return (tmp);
}

void	fill_width(char *ret, t_option *option, int len)
{
	char	c;
	int		i;

	i = 0;
	if (option->zero && option->precision == -1)
		c = '0';
	else
		c = ' ';
	while (i < len)
		ret[i++] = c;
	ret[i] = 0;
}
