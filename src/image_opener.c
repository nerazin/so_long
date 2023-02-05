/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_opener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:32:15 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 19:38:05 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_opener(nec_data *sl)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	open_util("./pics/mc50.xpm", 0);
	open_util("./pics/brick50.xpm", 0);
	open_util("./pics/jewel50.xpm", 0);
	open_util("./pics/exit50.xpm", 0);
	sl->mc_img = mlx_xpm_file_to_image(sl->mlx_conn_id, \
		"./pics/mc50.xpm", &x, &y);
	sl->brick_img = mlx_xpm_file_to_image(sl->mlx_conn_id, \
		"./pics/brick50.xpm", &x, &y);
	sl->jewel_img = mlx_xpm_file_to_image(sl->mlx_conn_id, \
		"./pics/jewel50.xpm", &x, &y);
	sl->exit_img = mlx_xpm_file_to_image(sl->mlx_conn_id, \
		"./pics/exit50.xpm", &x, &y);
}
