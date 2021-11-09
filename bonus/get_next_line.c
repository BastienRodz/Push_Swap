/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:21:09 by barodrig          #+#    #+#             */
/*   Updated: 2021/09/11 14:16:29 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_join(char *s1, char *s2, int len)
{
	char		*s3;
	int			i;
	int			j;
	int			size_s1;

	i = 0;
	size_s1 = 0;
	while (s1 && s1[size_s1])
		size_s1++;
	s3 = (char *)malloc(sizeof(char) * (len + size_s1 + 1));
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2 && ++j < len)
		s3[i++] = s2[j];
	if (s1)
		free(s1);
	s3[i] = '\0';
	return (s3);
}

int	ft_new_line(char *tmp)
{
	int			i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	return (i);
}

int	ft_get_ret(int ret, char *buf, char **line, char *tmp)
{
	if (ret > 0)
	{
		buf[ret] = '\0';
		*line = ft_join(tmp, buf, ft_new_line(buf));
		if (!(*line))
			return (-1);
		return (ret);
	}
	else if (ret == 0)
	{
		if (!*line)
		{
			*line = ft_join(0, 0, 0);
			if (!(*line))
				return (-1);
		}
		return (0);
	}
	*line = ft_join(0, 0, 0);
	return (-1);
}

char	*init(int *i, char **line)
{
	i = 0;
	if (line)
		line = NULL;
	else if (!line)
		exit(1);
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	i;
	int			ret;
	char		*tmp;

	tmp = init(&i, line);
	while (BUFFER_SIZE > 0)
	{
		*line = ft_join(tmp, buf + i, ft_new_line(buf + i));
		if (i && !(*line))
			return (-1);
		else if (!i)
		{
			ret = read(fd, buf, BUFFER_SIZE);
			if (ret >= -1)
				if ((ft_get_ret(ret, buf, line, tmp)) <= 0)
					return (ret);
		}
		tmp = *line;
		i = i + ft_new_line(buf + i) + 1;
		if (buf_checker(&i, buf))
			return (1);
	}
	return (-1);
}
