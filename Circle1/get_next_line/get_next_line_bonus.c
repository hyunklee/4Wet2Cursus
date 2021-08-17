/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:14:33 by hyunklee          #+#    #+#             */
/*   Updated: 2021/06/18 16:32:20 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*left_escape(char *backup, int cut)
{
	char	*new_buf;
	char	*buf_cpy;

	if (cut == -1)
		return (backup);
	if (!(new_buf = (char *)malloc(sizeof(char) * (cut + 1))))
		return (0);
	buf_cpy = new_buf;
	while (*backup != '\n')
		*new_buf++ = *backup++;
	*new_buf = 0;
	return (buf_cpy);
}

char	*right_escape(char *backup, int cut)
{
	char	*new_bu;

	if (cut == -1)
		return (0);
	new_bu = ft_strdup(backup + cut + 1);
	if (backup)
	{
		free(backup);
		backup = 0;
	}
	if (!new_bu)
		return (0);
	return (new_bu);
}

int		end_of_file(char **line, char **backup)
{
	*line = *backup;
	*backup = 0;
	return (0);
}

int		split_backup(int cut, char **backup, char **line)
{
	if (!(*line = left_escape(*backup, cut)) ||
	!(*backup = right_escape(*backup, cut)))
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			aend;
	int			cut;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while (1)
	{
		if (ft_strchr(backup[fd], '\n') == -1)
		{
			aend = read(fd, buf, BUFFER_SIZE);
			if (aend == -1)
				return (-1);
			buf[aend] = '\0';
			if (!(backup[fd] = ft_strjoin(backup[fd], buf)))
				return (-1);
		}
		if ((cut = ft_strchr(backup[fd], '\n')) != -1)
			return (split_backup(cut, &backup[fd], line));
		if (aend == 0)
			return (end_of_file(line, &backup[fd]));
	}
}
