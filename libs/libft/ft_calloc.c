/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:32:21 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/22 02:34:18 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*main_pointer;
	size_t	amount;

	amount = count * size;
	main_pointer = malloc(amount);
	if (main_pointer == NULL)
		return (NULL);
	ft_memset(main_pointer, 0, amount);
	return (main_pointer);
}
