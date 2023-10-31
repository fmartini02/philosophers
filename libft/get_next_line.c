/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:59:20 by lcasu             #+#    #+#             */
/*   Updated: 2023/06/19 15:05:52 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "libft.h"

char	*ft_remove_excess(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i])
		i++;
	res = malloc(i + 1);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		res[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	free(line);
	return (res);
}

char	*ft_get_excess(char *line)
{
	char	*res;
	char	*tmp;

	tmp = ft_strchr_gnl(line, '\n');
	if (tmp)
	{
		tmp++;
		res = ft_strdup_gnl(tmp);
	}
	else
		res = NULL;
	return (res);
}

char	*kludge(char *line, char *excess, char *buff, int byte_read)
{
	if (line[0] == 0)
	{
		free(excess);
		free(line);
		line = NULL;
	}
	else if (byte_read < BUFFER_SIZE && !excess)
		free(excess);
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	int			byte_read;
	char		*buff;
	char		*line;
	static char	*excess;

	buff = ft_calloc_gnl(BUFFER_SIZE + 1);
	line = ft_calloc_gnl(1);
	if (excess)
	{
		line = ft_strjoin_gnl(line, excess);
		free(excess);
	}
	byte_read = BUFFER_SIZE;
	while (!ft_strchr_gnl(buff, '\n') && byte_read == BUFFER_SIZE)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
			buff[byte_read] = '\0';
		if (byte_read > 0)
			line = ft_strjoin_gnl(line, buff);
		excess = ft_get_excess(line);
		line = ft_remove_excess(line);
	}
	line = kludge(line, excess, buff, byte_read);
	return (line);
}
