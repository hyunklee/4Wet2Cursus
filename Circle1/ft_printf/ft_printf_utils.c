#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*unittoa(unsigned int n)
{
	int		n_count;
	char	*ret;

	n_count = count_number(n, 10);
	ret = (char *)malloc(sizeof(char) * (n_count + 1));
	ret[n_count] = '\0';
	while (--n_count >= 0)
	{
		ret[n_count] = BASE[n % 10];
		n /= 10;
	}
	return (ret);
}

void	init_option(t_option *option)
{
	option->format = 0;
    option->plus = 0;
    option->zero = 0;
    option->minus = 0;
    option->precision = -1;
    option->width = 0;
    option->sharp = 0;
    option->empty = 0;
	option->sign = 0;
}

char	is_format(const char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c == FORMAT[i])
			return (FORMAT[i]);
		i++;
	}
	return (-1);
}

char	is_digit(const char c)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (BASE[i] == c)
			return (BASE[i]);
		i++;
	}
	return (0);
}