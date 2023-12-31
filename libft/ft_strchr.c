/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:10:56 by rdinc             #+#    #+#             */
/*   Updated: 2023/07/07 14:17:20 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	i = 0;
	a = c;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)(s + i));
		i++;
	}
	if (a == '\0')
		return ((char *)(s + i));
	return (0);
}
