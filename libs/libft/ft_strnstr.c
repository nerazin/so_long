/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:34:16 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 20:54:55 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;

	needle_size = ft_strlen(needle);
	if (!haystack || !needle)
		return (NULL);
	if (!needle_size)
		return ((char *) haystack);
	while (len >= needle_size && *haystack != '\0')
	{
		if (!ft_memcmp(haystack, needle, needle_size))
			return ((char *) haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
