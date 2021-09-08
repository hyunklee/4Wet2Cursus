/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 00:46:22 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/06 01:15:43 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_format(const char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c == FORMAT[i])
			return (FORMAT[i]);
		i++;
	}
	return (-1);
}

char	is_digit(const char c)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (BASE[i] == c)
			return (BASE[i]);
		i++;
	}
	return (0);
}

int	ft_len(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	if (!*s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;
	char	*temp;

	len = ft_len(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret || !s1)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*s1_cp;
	char	*s2_cp;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!ret || (!s1 && !s2))
		return (0);
	s1_cp = s1;
	s2_cp = s2;
	while (s1 && *s1)
		ret[i++] = *(s1++);
	while (s2 && *s2)
		ret[i++] = *(s2++);
	ret[i] = 0;
	safe_free((void **)&s1_cp);
	safe_free((void **)&s2_cp);
	return (ret);
}
