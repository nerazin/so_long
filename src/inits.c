/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:59:52 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 19:54:41 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_inits(nec_data *sl)
{
	sl->mlx_conn_id = mlx_init();
	if (!sl->mlx_conn_id)
		goodbye(sl);
	sl->mlx_window_id = mlx_new_window(sl->mlx_conn_id, sl->map_width, \
		sl->map_height, "play this game only if you bored af");
	if (!sl->mlx_window_id)
		goodbye(sl);
}
