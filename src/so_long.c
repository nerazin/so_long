/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:07:35 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 19:57:02 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_size(nec_data *sl)
{
	if (ft_strlen(sl->map[0]) > 20 || ft_strlen(sl->map[0]) > 20)
		goodbye_my_friend("the map is too big");
}

int	main(int ac, char **av)
{
	nec_data	sl;

	sl = (nec_data){0};
	check_error(ac != 2);
	sberbank(av[1]);
	read_map(av, &sl);
	check_map_size(&sl);
	analize_map(&sl);
	map_checker(&sl);
	sl_inits(&sl);
	image_opener(&sl);
	render_map(&sl);
	mlx_hook(sl.mlx_window_id, 2, 0, key_press, &sl);
	mlx_hook(sl.mlx_window_id, 17, 0, goodbye, &sl);
	mlx_loop(sl.mlx_conn_id);
	mlx_destroy_window(sl.mlx_conn_id, sl.mlx_window_id);
	return (0);
}
