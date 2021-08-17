/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 04:46:18 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/09 21:21:36 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				ret;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	ret = 0;
	while (n--)
	{
		if (*uc_s1 != *uc_s2)
		{
			ret = (int)(*uc_s1 - *uc_s2);
			return (ret);
		}
		uc_s1++;
		uc_s2++;
	}
	return (ret);
}
