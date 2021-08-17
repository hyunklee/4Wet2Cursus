/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:21:55 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/17 17:28:30 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_ret(char const *s, char c)
{
	size_t size;

	size = 0;
	while (*s)
	{
		if (*s != c)
		{
			size++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (size);
}

static char		**free_ret(char **ret, size_t idx)
{
	size_t i;

	i = 0;
	while (i < idx)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (0);
}

static char		*set_ret(char const *s, char c, size_t *cnt)
{
	char	*res;
	size_t	size;

	size = 0;
	while (s[*cnt] != c && s[*cnt])
	{
		*cnt += 1;
		size++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	*cnt -= size;
	size = 0;
	while (s[*cnt] != c && s[*cnt])
	{
		res[size] = s[*cnt];
		size++;
		*cnt += 1;
	}
	res[size] = 0;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	cnt;
	size_t	idx;
	size_t	size;

	if (!s)
		return (0);
	idx = 0;
	cnt = 0;
	size = get_ret(s, c) + 1;
	if (!(ret = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (idx + 1 < size)
	{
		while (s[cnt] == c && s[cnt])
			cnt++;
		ret[idx] = set_ret(s, c, &cnt);
		if (ret[idx] == 0)
			return (free_ret(ret, idx));
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}
