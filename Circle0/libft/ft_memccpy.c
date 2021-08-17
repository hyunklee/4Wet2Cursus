/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 01:22:20 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/09 21:21:09 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *temp_src;
	unsigned char *temp_dst;
	unsigned char temp_c;

	temp_c = (unsigned char)c;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (n--)
	{
		if (*temp_src == temp_c)
		{
			*temp_dst = *temp_src;
			return (dst + 1);
		}
		*temp_dst++ = *temp_src++;
		dst++;
	}
	return (NULL);
}
