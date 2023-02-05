/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:23:45 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 05:06:43 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_Q 12

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define IMG_SIZE 50

typedef struct	so_long_struct
{
	void	*mlx_conn_id;
	void	*mlx_window_id;
	char	**map;
	int		player_x;
	int		player_y;
	int		player_count;
	int		jewel_count;
	int		exit_count;
	int		map_height;
	int		map_width;
	void	*mc_img;
	void	*brick_img;
	void	*jewel_img;
	void	*exit_img;
}				nec_data;

void	sberbank(char *filename);
void	check_error(unsigned int error_condition);
int		arg_chech(int ac, char *av);
int		goodbye(nec_data *sl);
int		goodbye_my_friend(char *gb_message);
void	sl_inits(nec_data *sl);
int		key_press(int key, nec_data *sl);
char	*get_next_line(int fd);
int		open_util(char *filename, int keep_opened);
void	read_map(char **av, nec_data *sl);
void	analize_map(nec_data *sl);
void	image_opener(nec_data *sl);
void	render_map(nec_data *sl);
void	map_checker(nec_data *sl);

#endif