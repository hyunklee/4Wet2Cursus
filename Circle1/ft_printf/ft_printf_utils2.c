/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 06:38:12 by hyunklee          #+#    #+#             */
/*   Updated: 2021/08/17 17:20:35 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_number(long n, int base_num)
{
	int n_count;

	n_count = 0;
	if (n < 0)
		n_count++;
	while (n != 0)
	{
		n /= (long)base_num;
		n_count++;
	}
	return (n_count);
}

char		*change_to_ascii(long n, int base_num, char format)
{
	int		n_count;
	char	*ret;

	n_count = count_number(n, base_num);
	ret = (char *)malloc(sizeof(char) * (n_count + 1));
	ret[n_count] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (--n_count >= 0)
	{
		if (n_count == 0 && ret[n_count] == '-')
			break;
		ret[n_count] = BASE[n % (long)base_num];
		if (format == 'x' && (ret[n_count] >= 'A' && 
		ret[n_count] <= 'F'))
			ret[n_count] += 32;
		n /= (long)base_num;
	}
	return (ret);
}

char		*itoa_base(int n, char format)
{
	int     base_num;
	long	long_num;

	if (n == 0)
		return ("0");
	long_num = (long)n;
	if (format == 'i' || format == 'd')
		base_num = 10;
	else
		base_num = 16;
	return (change_to_ascii(long_num, base_num, format));
}