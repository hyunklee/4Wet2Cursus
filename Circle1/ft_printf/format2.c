/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 00:00:00 by hyunklee          #+#    #+#             */
/*   Updated: 2021/09/06 01:21:46 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *stringtostring(char *s)
{
    char *ret;
    int i;

    i = 0;
    if (!s)
        ret = ft_strdup("(null)");
    else
        ret = ft_strdup(s);
    return (ret);
}

char	*chartostring(char c)
{
	char *ret;

	if (c == 0)
		ret = (char *)malloc(sizeof(char));
	else
		ret = (char *)malloc(sizeof(char) * 2);
	if (!ret)
		return (0);
	if (c == 0)
		ret[0] = 0;
	else
	{
		ret[0] = c;
		ret[1] = 0;
	}
	return (ret);
}

int	reslut_len(const char *s, char format)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	if (!*s && format == 'c')
		return (1);
	while (s[i] != 0)
		i++;
	return (i);
}