/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.C                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:33:11 by lohanyan          #+#    #+#             */
/*   Updated: 2023/04/22 15:40:08 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	count(char *tmp)
{
	int	count;

	count = 0;
	while (tmp[count] != '\0')
	{
		if (tmp[count] == '\n')
			return (count + 1);
		count++;
	}
	return (count);
}

void	trim(char **tmp, int count)
{
	int		i;
	char	*stat;

	i = 0;
	stat = *tmp;
	while (stat[count + i] != '\0')
	{
		i++;
	}
	*tmp = ft_substr(*tmp, count, i);
	free (stat);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*tmp;
	int			i;
	int			len;
	char		*str;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (i > 0 && ft_strchr(buf, '\n') == NULL)
	{
		i = read(fd, buf, BUFFER_SIZE);
		printf(">>%d\n", i);
		if (i == -1 || (tmp == NULL && i == 0))
			return (NULL);
		buf[i] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(tmp, buf);
	}
	len = count(tmp);
	str = ft_substr(tmp, 0, len);
	trim(&tmp, len);
	return (str);
}*/
char	*mywhile(int fd, long readsize, char *sline)
{
	char	buff[BUFFER_SIZE + 1];

	while (1)
	{
		readsize = read(fd, buff, BUFFER_SIZE);
		buff[readsize] = '\0';
		if (readsize == -1)
			return (0);
		if (!sline)
			sline = ft_strdup(buff);
		else
			sline = ft_strjoin(sline, buff);
		if (ft_strchr(buff, '\n') || readsize == 0)
			break ;
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	long		index;
	long		readsize;
	static char	*sline;
	char		*line;
	char		*tmp;

	readsize = 1;
	sline = mywhile(fd, readsize, sline);
	index = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;
	line = ft_substr(sline, 0, index);
	tmp = sline;
	sline = ft_substr(sline, index, ft_strlen(sline));
	free(tmp);
	return (line);
}
