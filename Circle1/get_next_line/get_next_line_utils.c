/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:36:52 by hyunklee          #+#    #+#             */
/*   Updated: 2021/06/18 16:36:35 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(const char *s, int c)
{
	char	*temp;
	int		idx;

	temp = (char *)s;
	idx = 0;
	if (!s)
		return (-1);
	while (temp[idx])
	{
		if (temp[idx] == (char)c)
			return (idx);
		idx++;
	}
	if (temp[idx] == (char)c)
		return (idx);
	else
		return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;
	char	*temp;

	len = ft_strlen(s1);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	temp = ret;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	*ret_cp = 0;
	if (s1_cp)
		free(s1_cp);
	return (ret);
}
