/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:16:29 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 19:03:01 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while ((s1[count] || s2[count]) && n > 0)
	{
		if (s1[count] != s2[count])
			return ((unsigned char) s1[count] - (unsigned char) s2[count]);
		n--;
		count++;
	}
	return (0);
}
