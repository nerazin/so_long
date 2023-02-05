/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajothos <ajothos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:27:52 by ajothos           #+#    #+#             */
/*   Updated: 2021/10/21 22:27:53 by ajothos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_lenght(int num)
{
	int	len;

	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		num_len;
	long	n_copy;

	n_copy = n;
	num_len = num_lenght(n);
	result = (char *) malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	if (n_copy == 0)
		result[0] = '0';
	else if (n_copy < 0)
	{
		result[0] = '-';
		n_copy = -n_copy;
	}
	while (n_copy > 0)
	{
		result[--num_len] = '0' + n_copy % 10;
		n_copy = n_copy / 10;
	}
	return (result);
}
