/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:18:01 by hyunklee          #+#    #+#             */
/*   Updated: 2021/08/17 17:33:23 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*long_to_char(long mem)
{
	int		n_count;
	char	*ret;

	n_count = count_number(mem, 16) + 2;
	ret = (char *)malloc(sizeof(char) * (n_count + 1));
	ret[n_count] = '\0';
	ret[0] = '0';
	ret[1] = 'x';
	while (--n_count > 1)
	{
		ret[n_count] = BASE[mem % 16];
		if (ret[n_count] >= 'A' && ret[n_count] <= 'F')
			ret[n_count] += 32;
		mem /= 16;
	}
	return (ret);
}

char	*memtoa(void *mem)
{
	long mem_cp;
	char *ret;

	mem_cp = (long)mem;
	ret = long_to_char(mem_cp);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*ret_cp;
	char	*s1_cp;

	if (!(ret = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ret_cp = ret;
	s1_cp = (char *)s1;
	while (s1 && *s1)
		*ret_cp++ = *s1++;
	while (s2 && *s2)
		*ret_cp++ = *s2++;
	return (ret);
}

char	*apply_precision(char *tmp, char format, int precision)
{
	char	*ret;
	int		i;
	
	i = -1;
	if (precision < 0)
		return (tmp);
	if (format == 's' && (ft_strlen(tmp) > (size_t)precision))
	{
		ret = (char *)malloc(sizeof(char) * (precision + 1));
		if (!ret)
			return (0);
		while (++i < precision)
			ret[i] = tmp[i];
		ret[i] = 0;
		free(tmp);
		return (ret);
	}
	else if ((format != 'p' || format != 'c') &&
	 ft_strlen(tmp) < (size_t)precision)
	{
		ret = (char *)malloc(sizeof(char) * (precision - (int)ft_strlen(tmp) + 1));
		if (!ret)
			return (0);
		while (i < precision)
			ret[i++] = '0';
		ret[i] = 0;
		tmp = ft_strjoin(ret, tmp);
	}
	return (tmp);
}

char	*apply_sign(char *tmp, t_option *option)
{
	if ((option->format == 'd' || option->format == 'i') && !(option->sign))
	{
		if (option->empty)
			tmp = ft_strjoin(" ", tmp);
		else if (option->plus)
			tmp = ft_strjoin("+", tmp);
	}
	else if (option->format == 'x' && option->sharp)
		tmp = ft_strjoin("0x", tmp);
	else if (option->format == 'X' && option->sharp)
		tmp = ft_strjoin("0X", tmp);
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
	len = (int)ft_strlen(tmp);
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
	}
	return (ret);
}