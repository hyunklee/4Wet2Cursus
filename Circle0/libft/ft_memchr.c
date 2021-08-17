/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 04:30:22 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/07 23:44:43 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc_c;
	const unsigned char	*temp;

	temp = (const unsigned char *)s;
	uc_c = (unsigned char)c;
	while (n--)
	{
		if (*temp == uc_c)
			return (void *)(temp);
		temp++;
	}
	return (0);
}
