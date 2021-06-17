/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:32:45 by rzukale           #+#    #+#             */
/*   Updated: 2019/12/10 13:17:45 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	append_line(char **line, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		if (!(*line = ft_strndup(*str, i)))
			return (-1);
		tmp = *str;
		if (!(*str = ft_strdup(&(*str)[i + 1])))
			return (-1);
		ft_strdel(&tmp);
	}
	else
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		(*str)[0] = '\0';
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*str[FD_MAX];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line || fd >= FD_MAX)
		return (-1);
	if (!str[fd] && !(str[fd] = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(str[fd], buf)))
			return (-1);
		ft_strdel(&tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd][0] == '\0')
		return (0);
	else
		return (append_line(line, &str[fd]));
}
