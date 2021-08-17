# define BASE "0123456789ABCDEF"
# define FORMAT "cspdiuxX"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // 지우셈
# include <stdarg.h>

int     ft_len(const char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
    int     i;

	ret = (char *)malloc(sizeof(char) *(ft_len(s1) + ft_len(s2) + 1));
    if (!ret)
        return (0);
	while (s1 && *s1)
		ret[i++] = *(s1++);
	while (s2 && *s2)
		ret[i++] = *(s2++);
    ret[i] = 0;
	return (ret);
}

char	*memtoa(void *mem)
{
	long mem_cp;
	char *ret;
    int  cnt;

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

int      count_number(long n, int base_num)
{
	int cnt;

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

char		*change_to_str(long n, int base_num, char format)
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
			break;
		ret[cnt] = BASE[n % (long)base_num];
		if (format == 'x' && (ret[cnt] >= 'A' && 
		ret[cnt] <= 'F'))
			ret[cnt] += 32;
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
	return (change_to_str(long_num, base_num, format));