/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 06:15:26 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/09 17:53:42 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t count;

	count = 0;
	while (*dst && count < dstsize)
	{
		count++;
		dst++;
	}
	while (*src && count + 1 < dstsize)
	{
		*dst++ = *src++;
		count++;
	}
	if (count < dstsize)
		*dst = 0;
	while (*src)
	{
		count++;
		src++;
	}
	return (count);
}
