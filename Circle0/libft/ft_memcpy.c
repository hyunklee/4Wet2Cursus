/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:57:25 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/08 01:10:05 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d_temp;
	const char	*s_temp;

	if (dst == src)
		return (dst);
	d_temp = (char *)dst;
	s_temp = (char *)src;
	while (n--)
	{
		*d_temp = *s_temp;
		d_temp++;
		s_temp++;
	}
	return (dst);
}
