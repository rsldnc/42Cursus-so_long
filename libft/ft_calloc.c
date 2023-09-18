/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:52:15 by rdinc             #+#    #+#             */
/*   Updated: 2023/07/07 13:52:46 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_arr;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	ret_arr = (void *)malloc(count * size);
	if (!ret_arr)
		return (NULL);
	ft_bzero(ret_arr, (count * size));
	return (ret_arr);
}
