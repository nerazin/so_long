/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goodbye.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:35:04 by ajothos           #+#    #+#             */
/*   Updated: 2022/01/22 23:44:34 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	goodbye(nec_data *sl)
{
	(void) sl;
	exit(1);
	return (0);
}

int	goodbye_my_friend(char *gb_message)
{
	write(1, gb_message, ft_strlen(gb_message));
	exit(0);
	return (0);
}
