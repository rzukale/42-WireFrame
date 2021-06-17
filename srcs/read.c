/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:21:00 by rzukale           #+#    #+#             */
/*   Updated: 2020/07/28 16:27:36 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_file(char *argv, t_env *env)
{
	int		fd;
	char	*line;
	int		y;
	t_map	*map;

	map = env->map;
	if ((fd = open(argv, O_RDONLY)) < 0)
		display_error(-2);
	y = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (map->width == 0)
			if ((map->width = count_words(line)) < 1)
				display_error(-3);
		if (count_words(line) != map->width)
			display_error(-3);
		map->list = join_lists(&map->list, fill_map(line, y++));
		ft_strdel(&line);
	}
	if ((y == 0) || (y == 1 && map->width == 1))
		display_error(-3);
	map->height = y;
	find_min_max(map);
	fill_colors(env, 0);
	close(fd);
}

int		count_words(char *str)
{
	int		i;
	int		count;
	char	**words;

	count = 0;
	i = 0;
	words = ft_strsplit(str, ' ');
	while (words[i] != NULL)
	{
		if (validate_word(words[i]) == 1)
			count++;
		else
			return (-1);
		i++;
	}
	cleanup(words);
	return (count);
}

int		validate_word(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == ',')
	{
		if ((check_for_color(str, &i)) == 1)
			return (1);
		else
			return (-1);
	}
	if (len == 1 && str[0] == '-')
		return (-1);
	if (i == len)
		return (1);
	return (-1);
}

int		check_for_color(char *str, int *i)
{
	int	n;

	n = 0;
	if (str[*i + 1] && str[*i + 2] && str[*i + 1] == '0' && str[*i + 2] == 'x')
		*i += 3;
	else
		return (-1);
	while ((str[*i + n] && ft_isdigit(str[*i + n])) ||
			(str[*i + n] >= 'A' && str[*i + n] <= 'F') ||
			(str[*i + n] >= 'a' && str[*i + n] <= 'f'))
		n++;
	if (n > 8)
		return (-1);
	return (1);
}
