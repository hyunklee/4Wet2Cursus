/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:56:02 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/20 17:50:35 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*recursive(char *ret, long n)
{
	if (n == 0)
		return (ret);
	ret = recursive(ret, n / 10);
	*ret = (n % 10) + '0';
	return (ret + 1);
}

static size_t	count_size(long n)
{
	size_t size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	long	cp_n;
	size_t	size;
	char	*ret;

	cp_n = n;
	size = count_size(cp_n) + 1;
	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (0);
	if (n == 0)
		ret[0] = '0';
	if (cp_n < 0)
	{
		cp_n *= -1;
		*ret = '-';
		ret++;
		size -= 1;
	}
	recursive(ret, cp_n);
	ret[size - 1] = 0;
	if (n < 0)
		return (ret - 1);
	else
		return (ret);
}
