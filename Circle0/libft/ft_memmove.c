/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:30:38 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/09 22:17:48 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d_temp;
	const char	*s_temp;

	if (!dst && !src)
		return (NULL);
	d_temp = (char *)dst;
	s_temp = (char *)src;
	if (s_temp > d_temp)
	{
		while (len--)
			*(d_temp++) = *(s_temp++);
	}
	else
	{
		while (len--)
			d_temp[len] = s_temp[len];
	}
	return (dst);
}
