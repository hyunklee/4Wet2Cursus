/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 01:42:23 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/06 02:21:00 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_number(int n, int base_num)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		n /= (int)base_num;
		cnt++;
	}
	return (cnt);
}

int u_count_number(unsigned long long n, int base_num, char format)
{
	int cnt;

	cnt = 0;
	while (n != 0)
	{
		n /= (unsigned long long)base_num;
		cnt++;
	}
	if (format == 'p')
		cnt += 2;
	return (cnt);
}

char	*ft_itoa(int n)
{
	int		cnt;
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	cnt = count_number((long)n, 10);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	ret[cnt] = '\0';
	while (--cnt >= 0 && n > 0)
	{
		ret[cnt] = BASE[n % 10];
		n /= 10;
	}
	return (ret);
}

char	*change_to_str(unsigned long long n, int base_num, char format)
{
	int		cnt;
	char	*ret;

	cnt = u_count_number(n, base_num, format);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	if (format == 'p')
	{
		ret[0] = '0';
		ret[1] = 'x';
	}
	while (--cnt >= 0 && n > 0)
	{
		ret[cnt] = BASE[n % (unsigned long long)base_num];
		if (format == 'X' && (ret[cnt] >= 'a' && ret[cnt] <= 'f'))
			ret[cnt] -= 32;
		n /= (unsigned long long)base_num;
	}
	return (ret);
}

char	*unitoa_base(unsigned long long n, char format)
{
	int	base_num;

	if (n == 0)
	{	if (format == 'p')
			return (ft_strdup("0x0"));
		else
			return (ft_strdup("0"));
	}
	if (format == 'u')
		base_num = 10;
	else
		base_num = 16;
	return (change_to_str(n, base_num, format));
}
