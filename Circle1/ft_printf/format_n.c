/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 01:42:23 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/08 16:22:17 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_number(unsigned long long n, int base_num, char format)
{
	int	cnt;

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

char	*excpet_itoa(int n, t_option *option)
{
	if (n == -2147483648)
	{
		option->sign = '-';
		return (ft_strdup("2147483648"));
	}
	else
	{
		option->sign = '0';
		return (ft_strdup("0"));
	}
}

char	*ft_itoa(int n, t_option *option)
{
	int		cnt;
	char	*ret;

	if (n == -2147483648 || n == 0)
		return (excpet_itoa(n, option));
	if (n < 0)
	{
		option->sign = '-';
		n *= -1;
	}
	cnt = count_number((unsigned long long)n, 10, option->format);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	while (--cnt >= 0 && n > 0)
	{
		ret[cnt] = BASE[n % 10];
		n /= 10;
	}
	return (ret);
}

char	*change_to_str(unsigned long long n, int base_num, t_option *option)
{
	int		cnt;
	char	*ret;

	cnt = count_number(n, base_num, option->format);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	if (option->format == 'p')
	{
		ret[0] = '0';
		ret[1] = 'x';
	}
	while (--cnt >= 0 && n > 0)
	{
		ret[cnt] = BASE[n % (unsigned long long)base_num];
		if (option->format == 'X' && (ret[cnt] >= 'a' && ret[cnt] <= 'f'))
			ret[cnt] -= 32;
		n /= (unsigned long long)base_num;
	}
	return (ret);
}

char	*unitoa_base(unsigned long long n, t_option *option)
{
	int	base_num;

	if (option->format == 'u')
		base_num = 10;
	else
		base_num = 16;
	if (option->format != 'p')
		n = (unsigned int)n;
	if (n == 0)
	{
		if (option->format == 'p')
		{
			option->sign = '0';
			return (ft_strdup("0x0"));
		}
		else
		{
			option->sign = '0';
			return (ft_strdup("0"));
		}
	}
	return (change_to_str(n, base_num, option));
}
