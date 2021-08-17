/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:02:36 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/09 21:40:28 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*needle)
		return (char *)(haystack);
	while (i < len && haystack[i])
	{
		while (i + j < len && haystack[i + j] && needle[j])
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				break ;
			if (!needle[j])
				return (char *)(&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
