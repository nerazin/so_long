/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:51:13 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 16:27:27 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp1 = (const unsigned char *) s1;
	const unsigned char	*tmp2 = (const unsigned char *) s2;

	if (n != 0)
	{
		while (n--)
		{
			if (*tmp1 != *tmp2)
				return (*tmp1 - *tmp2);
			tmp1++;
			tmp2++;
		}
	}
	return (0);
}
