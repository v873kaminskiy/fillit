/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:16:00 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/30 16:12:02 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t pos;
	size_t len_little;

	len_little = ft_strlen(little);
	if (!len_little)
		return ((char *)big);
	i = 0;
	pos = 0;
	while (big[i] && i < len)
	{
		while (big[i + pos] == little[pos] && i + pos < len)
		{
			if (pos == len_little - 1)
				return ((char*)big + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (NULL);
}
