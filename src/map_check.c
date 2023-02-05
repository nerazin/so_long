/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:29:04 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 19:46:41 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangularity(nec_data *sl)
{
	int		x;
	size_t	fisrt_line_len;
	int		lines_count;

	x = -1;
	lines_count = 0;
	while (sl->map[lines_count])
		lines_count++;
	fisrt_line_len = ft_strlen(sl->map[0]);
	while (sl->map[++x])
	{
		if (x == lines_count - 1)
			fisrt_line_len--;
		if (ft_strlen(sl->map[x]) != fisrt_line_len)
			goodbye_my_friend("bad map form\n");
	}
}

static void	check_bad_symbols(nec_data *sl)
{
	int	x;
	int	y;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] != '0' && sl->map[y][x] != '1' &&
				sl->map[y][x] != 'C' && sl->map[y][x] != 'E' &&
				sl->map[y][x] != 'P' && sl->map[y][x] != '\n')
				goodbye_my_friend("bad sybol appeared on the map\n");
			x++;
		}
		y++;
	}
}

static void	check_vertical_borders(nec_data *sl)
{
	int		i;
	int		line;

	line = -1;
	i = (int) ft_strlen(sl->map[0]) - 2;
	while (sl->map[++line])
	{
		if ((sl->map[line][i] != '1') || (sl->map[line][0] != '1'))
			goodbye_my_friend("The maps vertical borders are corrupted\n");
	}
}

static void	check_horizontal_borders(nec_data *sl)
{
	int	i;
	int	line;

	line = 0;
	i = -1;
	while (sl->map[line + 1])
		line++;
	while ((sl->map[0][++i] != '\n') || (sl->map[0][++i] != '\0'))
	{
		if ((sl->map[line][i] != '1') || (sl->map[0][i] != '1'))
			goodbye_my_friend("The maps horizontal borders are corrupted\n");
	}
}

void	map_checker(nec_data *sl)
{
	if (sl->player_count != 1)
		goodbye_my_friend(
			"There have to be only 1 player on the map\n");
	if (sl->jewel_count < 1)
		goodbye_my_friend(
			"There have to be at least 1 jewel on the map\n");
	if (sl->exit_count < 1)
		goodbye_my_friend(
			"There have to be at least 1 exit on the map\n");
	check_rectangularity(sl);
	check_vertical_borders(sl);
	check_horizontal_borders(sl);
	check_bad_symbols(sl);
}
