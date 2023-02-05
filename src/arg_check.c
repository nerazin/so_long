/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:49:58 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 20:05:49 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char **av, nec_data *sl)
{
	int		i;
	int		fd;
	char	*line;

	fd = open_util(av[1], 1);
	sl->map = (char **) malloc(100);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		sl->map[i] = ft_strdup(line);
		if (!sl->map[i++])
		{
			free(line);
			exit (0);
		}
		free(line);
	}
	free(line);
}

void	analize_map(nec_data *sl)
{
	int	y;
	int	x;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == 'P')
			{
				sl->player_x = x;
				sl->player_y = y;
				sl->player_count++;
			}
			if (sl->map[y][x] == 'C')
				sl->jewel_count++;
			if (sl->map[y][x] == 'E')
				sl->exit_count++;
			x++;
		}
		y++;
	}
	sl->map_height = y * IMG_SIZE;
	sl->map_width = x * IMG_SIZE;
}

void	sberbank(char *filename)
{
	while (filename && *filename != '.')
		filename++;
	if (ft_strncmp(filename, ".ber", 4))
	{
		write (1, "so_long: bad file extension\n", 28);
		exit(1);
	}
}

void	check_error(unsigned int error_condition)
{
	if (error_condition)
	{
		perror("so_long");
		exit(EXIT_FAILURE);
	}
}
