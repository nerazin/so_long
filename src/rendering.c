/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:08:44 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 04:59:29 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map_helper(nec_data *sl, int *s, int *x, int *y)
{
	if (sl->map[*s][*x] == 'P')
		mlx_put_image_to_window(sl->mlx_conn_id, \
			sl->mlx_window_id, sl->mc_img, *x * 50, *y * 50);
	else if (sl->map[*s][*x] == '1')
		mlx_put_image_to_window(sl->mlx_conn_id, \
			sl->mlx_window_id, sl->brick_img, *x * 50, *y * 50);
	else if (sl->map[*s][*x] == 'E')
		mlx_put_image_to_window(sl->mlx_conn_id, \
			sl->mlx_window_id, sl->exit_img, *x * 50, *y * 50);
	else if (sl->map[*s][*x] == 'C')
		mlx_put_image_to_window(sl->mlx_conn_id, \
			sl->mlx_window_id, sl->jewel_img, *x * 50, *y * 50);
}

void	render_map(nec_data *sl)
{
	int	s;
	int	x;
	int	y;

	mlx_clear_window(sl->mlx_conn_id, sl->mlx_window_id);
	y = 0;
	s = 0;
	while (sl->map[s])
	{
		x = 0;
		while (sl->map[s][x])
		{
			render_map_helper(sl, &s, &x, &y);
			x++;
		}
		s++;
		y++;
	}
}
