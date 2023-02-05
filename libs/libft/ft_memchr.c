/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:27:56 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 16:19:19 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_char;

	temp_char = (unsigned char *) s;
	while (n--)
	{
		if (*temp_char == (unsigned char) c)
			return ((void *) temp_char);
		temp_char++;
	}
	return (NULL);
}
