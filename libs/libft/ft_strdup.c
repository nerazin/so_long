/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:52:40 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/21 23:42:09 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	string_lenght;
	char	*copy_pointer;

	string_lenght = ft_strlen(s1) + 1;
	copy_pointer = (char *) malloc(string_lenght);
	if (copy_pointer == NULL)
		return (NULL);
	ft_memcpy(copy_pointer, s1, string_lenght);
	return (copy_pointer);
}
