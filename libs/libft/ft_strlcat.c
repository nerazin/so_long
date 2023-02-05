/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:02:14 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 17:16:49 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	dest_len;
	size_t	src_len;

	src_i = 0;
	dest_len = ft_strlen(dst);
	dst_i = dest_len;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dest_len >= dstsize)
		return (dstsize + src_len);
	while ((dest_len + src_i) < dstsize && src[src_i])
	{
		dst[dst_i] = src[src_i];
		src_i++;
		dst_i++;
	}
	if ((dest_len + src_i) == dstsize)
		dst[--dst_i] = '\0';
	else
		dst[dst_i] = '\0';
	return (src_len + dest_len);
}
