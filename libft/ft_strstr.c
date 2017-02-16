/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:59:01 by vkaminsk          #+#    #+#             */
/*   Updated: 2016/11/28 21:41:32 by vkaminsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int pos;
	int i;
	int len;

	i = 0;
	pos = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	len = ft_strlen(little);
	while (big[i])
	{
		while (big[pos + i] == little[pos])
		{
			if (pos == len - 1)
				return ((char*)big + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
