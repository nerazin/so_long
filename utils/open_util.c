/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:11:01 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/23 19:47:05 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_util(char *filename, int keep_opened)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		goodbye_my_friend("Some of the image files don't exist\n");
		return (-1);
	}
	if (keep_opened)
		return (fd);
	else
		close(fd);
	return (0);
}
