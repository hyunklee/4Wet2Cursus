/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:15:49 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/09 21:23:38 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char ret_s1;
	unsigned char ret_s2;

	if (n <= 0)
		return (0);
	while (--n && *s1 && *s2)
	{
		if (*s1 != *s2)
		{
			ret_s1 = *s1;
			ret_s2 = *s2;
			return (int)(ret_s1 - ret_s2);
		}
		s1++;
		s2++;
	}
	ret_s1 = *s1;
	ret_s2 = *s2;
	return (int)(ret_s1 - ret_s2);
}
