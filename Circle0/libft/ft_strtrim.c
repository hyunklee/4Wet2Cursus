/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 22:24:31 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/10 21:21:47 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_left(char const *s1, char const *set)
{
	size_t	size;

	size = 0;
	while (*s1)
	{
		if (ft_strchr(set, *s1))
		{
			size++;
			s1++;
		}
		else
			break ;
	}
	return (size);
}

static size_t	count_right(char const *s1, char const *set)
{
	size_t		size;
	const char	*temp;

	temp = s1;
	s1 += ft_strlen(s1) - 1;
	size = 0;
	while (s1 >= temp)
	{
		if (ft_strchr(set, *s1))
		{
			size++;
			s1--;
		}
		else
			break ;
	}
	return (size);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	min;
	size_t	max;
	size_t	size;

	if (!s1 || !set)
		return (0);
	if (ft_strlen(s1) <= count_left(s1, set) + count_right(s1, set))
		size = 0;
	else
		size = ft_strlen(s1) - count_left(s1, set) - count_right(s1, set);
	min = count_left(s1, set);
	max = ft_strlen(s1) - count_right(s1, set);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	size = 0;
	while (min < max)
	{
		ret[size] = s1[min];
		size++;
		min++;
	}
	ret[size] = 0;
	return (ret);
}
