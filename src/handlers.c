/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:25:19 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 04:46:25 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_key_a(nec_data *sl)
{
	if ((sl->map[sl->player_y][sl->player_x - 1] == 'E' && sl->jewel_count == 0)
		|| sl->map[sl->player_y][sl->player_x - 1] == 'V')
		goodbye_my_friend("Game is over, play again if you want\n");
	if (sl->map[sl->player_y][sl->player_x - 1] == '1' ||
		sl->map[sl->player_y][sl->player_x - 1] == 'E')
		return ;
	if (sl->map[sl->player_y][sl->player_x - 1] == 'C')
		sl->jewel_count--;
	sl->map[sl->player_y][sl->player_x - 1] = 'P';
	sl->map[sl->player_y][sl->player_x] = '0';
	sl->player_x = sl->player_x - 1;
}

static void	handle_key_s(nec_data *sl)
{
	if ((sl->map[sl->player_y + 1][sl->player_x] == 'E' && sl->jewel_count == 0)
		|| sl->map[sl->player_y + 1][sl->player_x] == 'V')
		goodbye_my_friend("Game is over, play again if you want\n");
	if (sl->map[sl->player_y + 1][sl->player_x] == '1' ||
		sl->map[sl->player_y + 1][sl->player_x] == 'E')
		return ;
	if (sl->map[sl->player_y + 1][sl->player_x] == 'C')
		sl->jewel_count--;
	sl->map[sl->player_y + 1][sl->player_x] = 'P';
	sl->map[sl->player_y][sl->player_x] = '0';
	sl->player_y = sl->player_y + 1;
}

static void	handle_key_d(nec_data *sl)
{
	if ((sl->map[sl->player_y][sl->player_x + 1] == 'E' && \
		sl->jewel_count == 0) || sl->map[sl->player_y][sl->player_x + 1] == 'V')
		goodbye_my_friend("Game is over, play again if you want\n");
	if (sl->map[sl->player_y][sl->player_x + 1] == '1' || \
							sl->map[sl->player_y][sl->player_x + 1] == 'E')
		return ;
	if (sl->map[sl->player_y][sl->player_x + 1] == 'C')
		sl->jewel_count--;
	sl->map[sl->player_y][sl->player_x + 1] = 'P';
	sl->map[sl->player_y][sl->player_x] = '0';
	sl->player_x = sl->player_x + 1;
}

static void	handle_key_w(nec_data *sl)
{
	if ((sl->map[sl->player_y - 1][sl->player_x] == 'E' && sl->jewel_count == 0)
		|| sl->map[sl->player_y - 1][sl->player_x] == 'V')
		goodbye_my_friend("Game is over, play again if you want\n");
	if (sl->map[sl->player_y - 1][sl->player_x] == '1' ||
		sl->map[sl->player_y - 1][sl->player_x] == 'E')
		return ;
	if (sl->map[sl->player_y - 1][sl->player_x] == 'C')
		sl->jewel_count--;
	sl->map[sl->player_y - 1][sl->player_x] = 'P';
	sl->map[sl->player_y][sl->player_x] = '0';
	sl->player_y = sl->player_y - 1;
}

int	key_press(int key, nec_data *sl)
{
	if (key == KEY_ESC || key == KEY_Q)
		goodbye(sl);
	if (key == KEY_A)
		handle_key_a(sl);
	else if (key == KEY_S)
		handle_key_s(sl);
	else if (key == KEY_D)
		handle_key_d(sl);
	else if (key == KEY_W)
		handle_key_w(sl);
	render_map(sl);
	return (EXIT_SUCCESS);
}
