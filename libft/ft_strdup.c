/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:11:33 by rdinc             #+#    #+#             */
/*   Updated: 2023/07/03 16:12:17 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret_arr;
	int		i;

	i = 0;
	ret_arr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret_arr)
		return (NULL);
	while (src[i])
	{
		ret_arr[i] = src[i];
		i++;
	}
	ret_arr[i] = '\0';
	return (ret_arr);
}
