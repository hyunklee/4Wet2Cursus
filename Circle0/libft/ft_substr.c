/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 22:28:31 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/19 03:36:56 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s || !(s + start))
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start >= ft_strlen(s))
	{
		*ret = 0;
		return (ret);
	}
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
