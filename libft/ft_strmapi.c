/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:35:16 by rdinc             #+#    #+#             */
/*   Updated: 2023/07/06 18:05:37 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_arr;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ret_arr = malloc(sizeof(char) * (len + 1));
	if (!ret_arr)
		return (NULL);
	while (s[i])
	{
		ret_arr[i] = f(i, s[i]);
		i++;
	}
	ret_arr[i] = '\0';
	return (ret_arr);
}
