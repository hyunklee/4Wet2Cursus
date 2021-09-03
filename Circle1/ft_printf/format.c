/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 01:42:23 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/04 01:51:24 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_number(long n, int base_num)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		n /= (long)base_num;
		cnt++;
	}
	return (cnt);
}

char	*memtoa(void *mem)
{
	long	mem_cp;
	char	*ret;
	int		cnt;

	mem_cp = (long)mem;
	cnt = count_number(mem_cp, 16) + 2;
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = 0;
	ret[0] = '0';
	ret[1] = 'x';
	while (--cnt > 1)
	{
		ret[cnt] = BASE[mem_cp % 16];
		if (ret[cnt] >= 'A' && ret[cnt] <= 'F')
			ret[cnt] += 32;
		mem_cp /= 16;
	}
	return (ret);
}

char	*unittoa(unsigned int n)
{
	int		cnt;
	char	*ret;

	cnt = count_number((long)n, 10);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	while (--cnt >= 0)
	{
		ret[cnt] = BASE[n % 10];
		n /= 10;
	}
	return (ret);
}

char	*change_to_str(long n, int base_num, char format)
{
	int		cnt;
	char	*ret;

	cnt = count_number(n, base_num);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (--cnt >= 0)
	{
		if (cnt == 0 && ret[cnt] == '-')
			break ;
		ret[cnt] = BASE[n % (long)base_num];
		if (format == 'x' && (ret[cnt] >= 'A' && ret[cnt] <= 'F'))
			ret[cnt] += 32;
		n /= (long)base_num;
	}
	return (ret);
}

char	*itoa_base(int n, char format)
{
	int		base_num;
	long	long_num;

	if (n == 0)
		return ("0");
	long_num = (long)n;
	if (format == 'i' || format == 'd')
		base_num = 10;
	else
		base_num = 16;
	return (change_to_str(long_num, base_num, format));
}
