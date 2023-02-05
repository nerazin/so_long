/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:47:19 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 02:19:26 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = (char *) s;
	while (i < n)
	{
		pointer[i] = 0;
		i++;
	}
}
