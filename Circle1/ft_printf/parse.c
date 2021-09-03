/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 00:50:03 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/04 01:18:03 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(char *tmp, int precision)
{
	char	*ret;
	int		i;

	i = 0;
	if (ft_len(tmp) < precision)
	{
		ret = (char *)malloc(sizeof(char) * (precision - ft_len(tmp) + 1));
		if (!ret)
			return (0);
		while (i < precision - ft_len(tmp))
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
	if ((ft_len(tmp) > precision))
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
	if ((option->format == 'd' || option->format == 'i') && !(option->sign))
	{
		if (option->empty)
			tmp = ft_strjoin(ft_strdup(" "), tmp);
		else if (option->plus)
			tmp = ft_strjoin(ft_strdup("+"), tmp);
	}
	else if (option->format == 'x' && option->sharp)
		tmp = ft_strjoin(ft_strdup("0x"), tmp);
	else if (option->format == 'X' && option->sharp)
		tmp = ft_strjoin(ft_strdup("0X"), tmp);
	return (tmp);
}

char	*apply_width(char *tmp, t_option *option)
{
	int len;
	int	i;
	char *ret;
	char c;

	i = 0;
	c = ' ';
	if (option->zero)
		c = '0';
	len = ft_len(tmp);
	if (len < option->width)
	{
		len = option->width - len;
		ret = (char *)malloc(sizeof(char) * (len + 1));
		if (!ret)
			return (0);
		while (i < len)
			ret[i++] = c;
		if (option->minus)
			ret = ft_strjoin(tmp, ret);
		else
			ret = ft_strjoin(ret, tmp);
		return (ret);
	}
	return (tmp);
}