/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:27:17 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 15:56:21 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result_pointer;

	i = 0;
	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	result_pointer = ft_strdup(s);
	if (!result_pointer)
		return (NULL);
	while (s[i])
	{
		result_pointer[i] = (*f)(i, s[i]);
		i++;
	}
	return (result_pointer);
}
